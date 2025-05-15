#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ListasEncadeadas/DisciplinaLPI/TAD_LISTA/TAD_LISTA.h"

struct produto
{
    char codigo[21];
    char nome[31];
    char preco[21];
};
typedef struct produto Produto;

void formatacao(void * elemento);
void * ler_linha(char * linha);
char * montar(void * elemento);



int main()
{
    Lista * listinha = lst_cria();
    printf("criando lista\n");
    listinha = lst_carrega(listinha,"revisao_prova.txt",ler_linha);
    printf("carregano lista\n");
    lst_grava(listinha,"revisao_prova.txt",montar);
    printf("gravando lista\n");
    lst_imprime(listinha,formatacao);
    printf("imprimindo lista\n");
    listinha = lst_libera(listinha);

    if(lst_vazia(listinha))
    
    {
        printf("liberou\n");
    }
    else printf("nao liberou\n");



    return 0;
}

void formatacao(void * elemento)
{
    Produto * produto = (Produto *)elemento;
    printf("|%s||%s||%s|\n",produto->codigo,produto->nome,produto->preco);
}
void * ler_linha(char * linha)
{
    Produto * produto = (Produto*)malloc(sizeof(Produto));
    char * c;

    c = strtok(linha,";");
    strcpy(produto->codigo,c);

    c = strtok(NULL,";");
    strcpy(produto->nome,c);

    c = strtok(NULL,"\n");
    strcpy(produto->preco,c);

    return (void*)produto;
}
char * montar(void * elemento)
{
    Produto * produto = (Produto*)elemento;
    char * linha = (char*)malloc(150*sizeof(char));

    sprintf(linha,"%s;%s;%s\n",produto->codigo,produto->nome,produto->preco);
    return linha;
}