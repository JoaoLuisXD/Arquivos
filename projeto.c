#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ListasEncadeadas/TAD_lista_generica/TAD_listagen.h"

#define ARQUIVO_ENTRADA "projeto.txt"

typedef struct 
{
    char matricula[51];
    char nome[100];
} Aluno;

Aluno * identificar_aluno(char *linha);
void * ler_aluno(FILE * fp);
void imprime_aluno(void *a) ;





int main()
{
    FILE * fp = fopen(ARQUIVO_ENTRADA,"rt");

}


Aluno * identificar_aluno(char *linha) 
{
    Aluno * aluno = (Aluno*)malloc(sizeof(Aluno));
    char nome[100];
    char matricula[50];
    int qtd_nome = 0;
    int qtd_matricula = 0;
    int i = 0;
    int j = 0;

    // PERCORRER A STRIING ATÉ ACHAR UM ";" (NOME)
    for (i = 0; linha[i] < '\0'; i++)
    {
        if(linha[i] == ';')
        {
            break;
        }
    }

    // PERCORRE A STRING ATÉ ANTES DO ";" COLOCANDO CADA ELEMENTO DA LINHA EM NOME.
    for (; j < i; j++)
    {
        nome[qtd_nome] = linha[j];
        qtd_nome++;
    }
    nome[qtd_nome] = '\0'; // DECLARA QUE A STRING DE NOME ACABOU.

    // PERCORRE A STRING A PARTIR DE UMA POSIÇÃO APÓS DO ";" COLOCANDO CADA ELEMENTO DA LINHA EM MATRICULA.
    for(j = i+1; j < strlen(linha); j++)
    {
        matricula[qtd_matricula] = linha[j];
        qtd_matricula++;
    }
    matricula[qtd_matricula] = '\0'; // DECLARA QUE A STRING DE MATRICULA.

    // COPIA OS DADOS ARMAZENADOS EM NOME E MATRICULA, COLOCOANDO-OS EM ALUNO->NOME E ALUNO->MATRICULA.
    strcpy(aluno->nome,nome);
    strcpy(aluno->matricula,matricula);
    return aluno;    
}

void * ler_aluno(FILE * fp)
{
    char linha[100];
    char * c;
    while ((c = fgets(linha,100,fp)) != NULL) // PERCORERR A LINHA DO ARQUIVO, E COLOCANDO EM C O QUE ACHOU.
    {
        if(c)
        {
            return identificar_aluno(linha); // RETORNA A FUNÇÃO IDENTIFICANDO SE É UM ALUNO(NOME,MATRICULA).
        }
    }
    return NULL;
}

void imprime_aluno(void *a) 
{
    Aluno *al = (Aluno *)a;
    printf("|Nome: %s||Matrícula: %s| \n", al->matricula, al->nome);
}

void concatena_linha(void *a, FILE * fp)
{
    Aluno *al = (Aluno*)al;
    printf("|%s;%s|\n",al->nome,al->matricula); 
}

