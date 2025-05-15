#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\ListasEncadeadas\DisciplinaLPI\TAD_LISTA\TAD_LISTA.h"

struct aluno
{
    char id[11];
    char matricula[21];
    char nome[31];
    char local[21];
    char data[21];
    char problema[21];
    char resolvido[21];
};
typedef struct aluno Aluno;

void formatacao(void * elemento);
void * ler_linha(char * linha);
char * montar_linha(void * elemento);
int verifica_al(void *a,void*b);

int main()
{
    Lista * minha_lista = lst_cria();
    
    minha_lista = lst_carrega(minha_lista,"prova.txt",ler_linha);

    lst_imprime(minha_lista,formatacao);

    char mudar = 's';

    while (mudar == 's' || mudar == 'S')
    {
        Aluno * novo = (Aluno*)malloc(sizeof(Aluno));
        if(!novo)
        break;

        printf("criando um novo aluno\n");
        printf("id\n");
        fgets(novo->id,sizeof(novo->id),stdin);
        novo->id[strlen(novo->id) - 1] = '\0';
        printf("matricula\n");
        fgets(novo->matricula,sizeof(novo->matricula),stdin);
        novo->matricula[strlen(novo->matricula) - 1] = '\0';
        printf("nome\n");
        fgets(novo->nome,sizeof(novo->nome),stdin);
        novo->nome[strlen(novo->nome) - 1] = '\0';
        printf("local\n");
        fgets(novo->local,sizeof(novo->local),stdin);
        novo->local[strlen(novo->local) - 1] = '\0';
        printf("data\n");
        fgets(novo->data,sizeof(novo->data),stdin);
        novo->data[strlen(novo->data) - 1] = '\0';
        printf("problema\n");
        fgets(novo->problema,sizeof(novo->problema),stdin);
        novo->problema[strlen(novo->problema) - 1] = '\0';
        printf("resolvido\n");
        fgets(novo->resolvido,sizeof(novo->resolvido),stdin);
        novo->resolvido[strlen(novo->resolvido) - 1] = '\0';
        lst_insere(minha_lista,novo,verifica_al);

        printf("gostaria de adicionar mais um aluno ? s/n\n");
        
        mudar = getchar();
        getchar();
    }
    lst_imprime(minha_lista,formatacao);

    lst_grava(minha_lista,"prova.txt",montar_linha);

    minha_lista = lst_libera(minha_lista);

    if(lst_vazia(minha_lista))
    {
        printf("lista vaiza\n");
    }
    else printf("a lista nao esta vazia\n");


    return 0;
}
int verifica_al(void *a,void*b)
{
    Aluno * al = (Aluno*)a;
    Aluno * bl = (Aluno*)b;
    return strcmp(al->id, bl->id) == 0;

}

void formatacao(void * elemento)
{
    Aluno * luno = (Aluno*)elemento;
    printf("|id - %s| |matricula - %s| |nome - %s| |local - %s| |data - %s| |problema - %s| |resolvido - %s|\n",luno->id,luno->matricula,luno->nome,luno->local,luno->data,luno->problema,luno->resolvido);
}
void * ler_linha(char * linha)
{
    Aluno * luno = (Aluno*)malloc(sizeof(Aluno));
    if(!luno)
    {
        exit(1);
    }
    char * c;

    c = strtok(linha,";");
    strcpy(luno->id,c);

    c = strtok(NULL,";");
    strcpy(luno->matricula,c);

    c = strtok(NULL, ";");
    strcpy(luno->nome,c);

    c = strtok(NULL, ";");
    strcpy(luno->local,c);
    
    c = strtok(NULL, ";");
    strcpy(luno->data,c);

    c = strtok(NULL, ";");
    strcpy(luno->problema,c);

    c = strtok(NULL, "\n");
    strcpy(luno->resolvido,c);

    return (void*)luno;
}
char * montar_linha(void * elemento)
{
    Aluno * luno = (Aluno*)elemento;
    char * linha = (char*)malloc(250*sizeof(char));
    if(!linha)
    {
        exit(1);
    }
    sprintf(linha,"%s;%s;%s;%s;%s;%s;%s\n",luno->id,luno->matricula,luno->nome,luno->local,luno->data,luno->problema,luno->resolvido);
    return linha;
}
