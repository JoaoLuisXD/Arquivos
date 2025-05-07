#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filmes
{
    char titulo[101];
    char diretor[51];
    char ano[11];
    char genero[21];
};
typedef struct filmes Filmes;

#define ENTRADA_FILMES "filmes.txt"




int main()
{
    FILE * fp = fopen(ENTRADA_FILMES,"rt");
    int qtd_linhas = 0;
    char linha[121];
    int qtd_filmes = 0;
    Filmes filme[5];
    int campo_atual = 0;
    while (fgets(linha,121,fp) != NULL)
    {
        qtd_linhas++;
        if (campo_atual == 0) 
        strcpy(filme[qtd_filmes].titulo,linha);
        else if (campo_atual == 1)
        strcpy(filme[qtd_filmes].diretor,linha);
        else if (campo_atual == 2)
        strcpy(filme[qtd_filmes].ano,linha);
        else if (campo_atual == 3)
        {
            strcpy(filme[qtd_filmes].genero,linha);
            qtd_filmes ++;
        }
        
        campo_atual ++;
        if(campo_atual == 4)
        {
            campo_atual = 0;
        }
    }
    
    for (int i = 0; i < qtd_filmes; i++)
    {
        printf("----------FILME|%d|----------\n",i+1);
        printf("titulo: %s\n",filme[i].titulo);
        printf("diretor: %s\n",filme[i].diretor);
        printf("ano: %s\n",filme[i].ano);
        printf("genero: %s\n",filme[i].genero);
    }
    


    printf("quantidade de linhas: %d",qtd_linhas+1);
    fclose(fp);

}