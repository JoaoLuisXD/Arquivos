#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa
{
    char nome[121];
    char idade[10];
    char profissao[51];
};
typedef struct pessoa Pessoa;

#define ENTRADA "arquivo.txt"



int main()
{
    FILE *arquvo_entrada = fopen(ENTRADA, "rt");
    char linha[121];
    int n_linha = 0;
    int i = 0;
    int qtd_registro = 0;
    Pessoa registro[5];
    if(!arquvo_entrada)
    {
        printf("não foi possivel abrir o arquivo");
        exit(1);
    }
    printf("arquivo abriu com sucesso");

    while (fgets(linha,121,arquvo_entrada) != NULL)
    {
        n_linha++;

        if(i % 3 == 0)
        strcpy(registro[qtd_registro].nome, linha);
        else if(i % 3 == 1)
        strcpy(registro[qtd_registro].idade, linha);
        else if(i % 3 == 2)
        {
            strcpy(registro[qtd_registro].profissao, linha);
            qtd_registro++;
        }
        


        i++;
    }
    
    for(int i=0; i<qtd_registro; i++)
    {
        printf("\nRegistro: %d\n",i+1);
        printf("Nome: %s\n",registro[i].nome);
        printf("Idade: %s\n",registro[i].idade);
        printf("Profissao: %s\n",registro[i].profissao);
    }

    fclose(arquvo_entrada);
    return 0;
}