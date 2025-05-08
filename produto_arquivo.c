#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    char nome[101];
    char preco[51];
    char quantidade[51];
};
typedef struct produto Produto;

#define ABERTURA_ARQUIVO "produto.txt"



int main()
{
    FILE * fp = fopen(ABERTURA_ARQUIVO,"rt");
    int qtd_linhas = 0;
    Produto registro[3];
    int qtd_produtos = 0;
    char linha[121];
    int num_verificacao = 0;
    while (fgets(linha,121,fp) != NULL)
    {
        qtd_linhas ++;
        
        if (num_verificacao == 0)
        strcpy(registro[qtd_produtos].nome,linha);
        if(num_verificacao == 1)
        strcpy(registro[qtd_produtos].preco,linha);
        if (num_verificacao == 2)
        {
            strcpy(registro[qtd_produtos].quantidade,linha);
            qtd_produtos++;
        }
        
        num_verificacao ++;
        if(num_verificacao == 3)
        {
            num_verificacao = 0;
        }
        
    }

    for (int i = 0; i < qtd_produtos; i++)
    {
        printf("-----PRODUTO N%d-----\n",i);
        printf("nome: %s\n",registro[i].nome);
        printf("preco: %s\n",registro[i].preco);
        printf("quantidade: %s\n",registro[i].quantidade);
    }

    printf("quantidade de linhas: %d",qtd_linhas+1);
    fclose(fp);
    return 0;
}