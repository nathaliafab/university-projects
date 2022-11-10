// https://iudex.io/problem/61679ee697713f0001036f6c/statement

#include <iostream>

using namespace std;

class HashNode
{
public:
    string musica;
    int duracao;
    int key = 0;
    int tempo_rep = 0;

    HashNode(string M, int D)
    {
        musica = M;
        duracao = D;
    }
};

class HashMap
{
    HashNode **tabela;

    int capacidade;
    int tam = 0;

public:
    HashMap(int capacidade)
    {
        this->capacidade = capacidade;
        tabela = new HashNode *[capacidade];

        for (int i = 0; i < capacidade; i++)
            tabela[i] = NULL;
    }

    int calcKey(string musica)
    {
        int key = 0;
        for (int count = 0; musica[count] != '\0'; count++)
            key += musica[count] * count;
        return key;
    }

    int hashFunction(string musica, int key, bool flag)
    {
        int Hi = key % capacidade, Hx = Hi;
        if (flag) // Adicionar [linear probing]
            for (int i = 1; tabela[Hx] != NULL; i++)
                Hx = (Hi + i) % capacidade;

        else // Procurar [linear probing]
            for (int i = 1; !(tabela[Hx] != NULL && tabela[Hx]->musica == musica) && i < capacidade; i++)
                Hx = (Hi + i) % capacidade;

        return Hx;
    }

    void adiciona(string musica, int duracao)
    {
        if (tam >= ((capacidade + 1) / 2))
            reHashing();

        int key = calcKey(musica);
        int hashIndex = hashFunction(musica, key, true);
        HashNode *temp = new HashNode(musica, duracao);

        tam++;
        tabela[hashIndex] = temp;
        tabela[hashIndex]->key = key;
        cout << musica << " " << hashIndex << endl;
    }

    void procura(string musica, bool flag)
    {
        int key = calcKey(musica);
        int hashIndex = hashFunction(musica, key, false);

        if (tabela[hashIndex]->musica == musica)
        {
            if (flag) // se for PLAY
                tabela[hashIndex]->tempo_rep += tabela[hashIndex]->duracao;

            cout << musica << " " << tabela[hashIndex]->tempo_rep << endl;
        }
    }

    void reHashing()
    {
        /*Caso a taxa de ocupação (fator de carga) da tabela chegue a 50%, é necessário fazer rehashing,
        aumentando o tamanho da tabela para 2*M + 1. Essa verificação deve ser feita imediatamente antes
        de cada inserção.*/
        int novaCapacidade = 2 * capacidade + 1;
        HashNode **newtabela = new HashNode *[novaCapacidade];

        for (int i = 0; i < novaCapacidade; i++)
            newtabela[i] = NULL;

        for (int i = 0; i < capacidade; i++)
        {
            if (tabela[i] != NULL)
            {
                int Hi = tabela[i]->key % (novaCapacidade), Hx = Hi;
                for (int j = 1; newtabela[Hx] != NULL; j++)
                    Hx = (Hi + j) % (novaCapacidade);

                newtabela[Hx] = tabela[i];
            }
        }

        delete[] tabela;
        tabela = newtabela;

        capacidade = novaCapacidade;
    }
};

int main(void)
{
    int M;       // tamanho inicial da tabela
    int duracao; // duração da música
    string musica;
    string evento;

    cin >> M;
    HashMap *espotifai = new HashMap(M);

    do
    {
        cin >> evento;

        // ADD s t: Adiciona a música de nome s com duração t à tabela (playlist).
        if (evento == "ADD")
        {
            cin >> musica >> duracao;
            espotifai->adiciona(musica, duracao);
        }

        // PLAY s: Busca a música de nome s na tabela e incrementa o tempo total de reprodução
        else if (evento == "PLAY")
        {
            cin >> musica;
            espotifai->procura(musica, true);
        }

        // TIME s: Busca a música de nome s na tabela e informa o tempo total de reprodução de s até o momento atual.
        else if (evento == "TIME")
        {
            cin >> musica;
            espotifai->procura(musica, false);
        }

    } while (evento != "END");

    return 0;
}
