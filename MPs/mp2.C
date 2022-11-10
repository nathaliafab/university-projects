//Nome: Nathalia Fernanda de Araújo Barbosa
//Login: nfab
//Data: 05/08/2021
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char remetente[50];
    char assunto[50];
    char mensagem[200];
} Email;

typedef struct
{
    char nome[50];
    char senha[50];
    int qtdRecebidos, qtdEnviados;
    Email *recebidos, *enviados;
} Usuario;

void cadastrarUsuario(char *nome, char *senha, int *qtd, FILE *arq, Usuario **usuario)
{
    (*usuario) = (Usuario *)realloc(*usuario, ((*qtd) + 1) * sizeof(Usuario));

    if ((*usuario) == NULL)
        exit(1);

    strcpy((*usuario)[(*qtd)].nome, nome);
    strcpy((*usuario)[(*qtd)].senha, senha);
    (*usuario)[(*qtd)].qtdRecebidos = 0;
    (*usuario)[(*qtd)].qtdEnviados = 0;

    (*qtd)++;
    arq = fopen("users.bin", "wb");
    if (arq == NULL)
        exit(1);
    fwrite((*usuario), sizeof(Usuario), (*qtd), arq);
    fclose(arq);
}

/*
▪ Lê o arquivo de usuários, procura pelo usuário com nome e senha, solicitando nome e
senha novamente caso o usuário não seja encontrado. Após autenticar o usuário,
devem ser oferecidas as opções de ver e-mails recebidos, ver e-mails enviados e
enviar e-mail.
*/
void login(char *nome, char *senha, int qtd, FILE *arq, Usuario *usuario)
{
    int encontrado = 0, opcao;
    char nomeL[50], senhaL[50];

    while (!encontrado)
    {
        for (int i = 0; i < qtd && !encontrado; i++)
            if (strcmp(nome, usuario[i].nome) == 0 && strcmp(senha, usuario[i].senha) == 0)
                encontrado = 1;

        if (!encontrado)
        {
            printf("Digite novamente seu nome: ");
            scanf(" %[^\n]", nomeL);
            strcpy(nome, nomeL);
            printf("Digite novamente sua senha: ");
            scanf(" %[^\n]", senhaL);
            strcpy(senha, senhaL);
        }
    }
}

/*
▪ Solicita o nome do destinatário, assunto e mensagem a ser enviada.
▪ Procura o destinatário no arquivo e guarda o e-mail no vetor de e-mails recebidos
▪ Procura o remetente no arquivo e guarda o e-mail no vetor de e-mails enviados
▪ Atualiza o arquivo (users.bin)
*/
void enviarEmail(char *nomeRemetente, int qtd, FILE *arq, Usuario **usuario)
{
    int i, encontrado = 0, receb, entreg;
    char destinatario[50], assunto[50], mensagem[200];

    printf("Digite o nome do destinatario: ");
    scanf(" %[^\n]", destinatario);
    printf("Digite o assunto: ");
    scanf(" %[^\n]", assunto);
    printf("Digite a mensagem: ");
    scanf(" %[^\n]", mensagem);

    for (i = 0; i < qtd && !encontrado; i++)
        if (strcmp(destinatario, (*usuario)[i].nome) == 0)
            encontrado = 1;

    i--;

    if (encontrado)
    {
        receb = (*usuario)[i].qtdRecebidos;
        if (receb == 0)
            (*usuario)[i].recebidos = (Email *)malloc(sizeof(Email));
        else
            (*usuario)[i].recebidos = (Email *)realloc((*usuario)[i].recebidos, (receb + 1) * sizeof(Email));

        if ((*usuario)[i].recebidos == NULL)
            exit(1);

        strcpy((*usuario)[i].recebidos[receb].remetente, nomeRemetente);
        strcpy((*usuario)[i].recebidos[receb].assunto, assunto);
        strcpy((*usuario)[i].recebidos[receb].mensagem, mensagem);
        (*usuario)[i].qtdRecebidos++;

        encontrado = 0;
        for (i = 0; i < qtd && !encontrado; i++)
            if (strcmp(nomeRemetente, (*usuario)[i].nome) == 0)
                encontrado = 1;

        i--;

        entreg = (*usuario)[i].qtdEnviados;
        if (entreg == 0)
            (*usuario)[i].enviados = (Email *)malloc(sizeof(Email));
        else
            (*usuario)[i].enviados = (Email *)realloc((*usuario)[i].enviados, (entreg + 1) * sizeof(Email));

        if ((*usuario)[i].enviados == NULL)
            exit(1);

        strcpy((*usuario)[i].enviados[entreg].remetente, nomeRemetente);
        strcpy((*usuario)[i].enviados[entreg].assunto, assunto);
        strcpy((*usuario)[i].enviados[entreg].mensagem, mensagem);
        (*usuario)[i].qtdEnviados++;

        arq = fopen("users.bin", "wb");
        if (arq == NULL)
            exit(1);
        fwrite((*usuario), sizeof(Usuario), qtd, arq);
        fclose(arq);

        free((*usuario)[i].recebidos);
        free((*usuario)[i].enviados);
    }
}
//Imprime na tela todos os e-mails recebidos pelo usuário
void verRecebidos(char *nome, Usuario *usuario, int qtd)
{
    int i, encontrado = 0, receb;

    for (i = 0; i < qtd && !encontrado; i++)
        if (strcmp(nome, usuario[i].nome) == 0)
            encontrado = 1;

    i--;

    receb = usuario[i].qtdRecebidos;
    if (receb > 0)
        usuario[i].recebidos = (Email *)realloc(usuario[i].recebidos, (receb) * sizeof(Email));

    if (usuario[i].recebidos == NULL)
        exit(1);

    for (int j = 0; j < receb; j++)
    {
        printf("Remetente: %s\n", usuario[i].recebidos[j].remetente);
        printf("Assunto: %s\n", usuario[i].recebidos[j].assunto);
        printf("Msg: %s\n", usuario[i].recebidos[j].mensagem);
        printf("-----------\n");
    }

    free(usuario[i].recebidos);
}
//Imprime na tela todos os e-mails enviados pelo usuário
void verEnviados(char *nome, Usuario *usuario, int qtd)
{
    int i, encontrado = 0, entreg;

    for (i = 0; i < qtd && !encontrado; i++)
        if (strcmp(nome, usuario[i].nome) == 0)
            encontrado = 1;

    i--;

    entreg = usuario[i].qtdEnviados;
    if (entreg > 0)
        usuario[i].enviados = (Email *)realloc(usuario[i].enviados, (entreg) * sizeof(Email));

    if (usuario[i].enviados == NULL)
        exit(1);

    for (int j = 0; j < entreg; j++)
    {
        printf("Remetente: %s\n", usuario[i].enviados[j].remetente);
        printf("Assunto: %s\n", usuario[i].enviados[j].assunto);
        printf("Msg: %s\n", usuario[i].enviados[j].mensagem);
        printf("-----------\n");
    }

    free(usuario[i].enviados);
}
int main(void)
{
    //declarando funções...
    void cadastrarUsuario(char *nome, char *senha, int *qtd, FILE *arq, Usuario **usuario);
    void login(char *nome, char *senha, int qtd, FILE *arq, Usuario *usuario);
    void enviarEmail(char *nomeRemetente, int qtd, FILE *arq, Usuario **usuario);
    void verRecebidos(char *nome, Usuario *usuario, int qtd);
    void verEnviados(char *nome, Usuario *usuario, int qtd);

    int qtd = 0, opcao;
    char nome[50], senha[50];
    Usuario *usuarios = NULL;
    FILE *arq = NULL;

    arq = fopen("users.bin", "a+b");
    if (arq == NULL)
        exit(1);

    fseek(arq, 0, SEEK_END);
    qtd = ftell(arq) / sizeof(Usuario);
    rewind(arq);

    usuarios = (Usuario *)malloc(qtd * sizeof(Usuario));
    if (usuarios == NULL)
        exit(1);

    fread(usuarios, sizeof(Usuario), qtd, arq);
    fclose(arq);

    printf("Opcoes:\n1 - Cadastrar usuario\n2 - Fazer login\n");
    while (1)
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite nome: ");
            scanf(" %[^\n]", nome);
            printf("Digite senha: ");
            scanf(" %[^\n]", senha);

            cadastrarUsuario(nome, senha, &qtd, arq, &usuarios);
            break;

        case 2:
            printf("Digite nome: ");
            scanf(" %[^\n]", nome);
            printf("Digite senha: ");
            scanf(" %[^\n]", senha);
            login(nome, senha, qtd, arq, usuarios);

            printf("Selecione uma opcao:\n1 - ver e-mails recebidos\n2 - ver e-mails enviados\n3 - enviar e-mail\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                verRecebidos(nome, usuarios, qtd);
                break;
            case 2:
                verEnviados(nome, usuarios, qtd);
                break;
            case 3:
                enviarEmail(nome, qtd, arq, &usuarios);
                break;
            }
            break;

        default:
            free(usuarios);
            return 0;
        }
    }

    return 0;
}
