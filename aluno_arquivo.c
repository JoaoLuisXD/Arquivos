#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO_ENTRADA "aluno.txt"

struct aluno
{
    int matricula;
    char nome[101];
    int idade;
    char curso[101];
};
typedef struct aluno Aluno;



int main()
{
    FILE * fp = fopen(ARQUIVO_ENTRADA,"rt");
    if (fp == NULL)
    {
        exit(1);
    }
    
    int c = 0;
    int qtd_linhas = 0;
    
    
    while ((c = fgetc(fp)) != EOF)
    {
        if(c == '\n')
        {
            qtd_linhas++;
        }
    }
    Aluno * registro_aluno = (Aluno*)malloc(qtd_linhas*sizeof(Aluno));
    rewind (fp);
    for (int i = 0; i < qtd_linhas; i++) {
        fscanf(fp, "%d;%100[^;];%d;%100[^\n]\n",
               &registro_aluno[i].matricula,
               registro_aluno[i].nome,
               &registro_aluno[i].idade,
               registro_aluno[i].curso);
    }

    
    for (int i = 0; i < qtd_linhas; i++)
    {
        printf("|%d| ",registro_aluno[i].matricula);
        printf("|%s| ",registro_aluno[i].nome);
        printf("|%d| ",registro_aluno[i].idade);
        printf("|%s| ",registro_aluno[i].curso);
        printf("\n");
    }
    
    fclose(fp);
    return 0;
}