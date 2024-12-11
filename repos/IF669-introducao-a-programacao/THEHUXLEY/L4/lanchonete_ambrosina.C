// https://www.thehuxley.com/problem/12

#include <stdio.h>

typedef struct
{
    int codigo;
    char descricao[50];
    float preco;
} Produtos;

typedef struct
{
    int cod;
    int quantidade;
} Pedidos;

int main()
{
    int contador, i;
    float total = 0.0;
    Pedidos pedido;

    scanf("%d", &contador);
    Produtos produto[contador];

    for (i = 0; i < contador; i++)
        scanf("%d %49[^\n] %f", &produto[i].codigo, produto[i].descricao, &produto[i].preco);
        
    scanf("%d", &pedido.cod);

    while (pedido.cod != 0)
    {
        scanf("%d", &pedido.quantidade);

        if(pedido.quantidade > 0){
            for (i = 0; i < contador; i++)
                if (produto[i].codigo == pedido.cod)
                    total += pedido.quantidade * produto[i].preco;
        }
                
        scanf("%d", &pedido.cod);
    }

    printf("%.2f", total);

    return 0;
}
