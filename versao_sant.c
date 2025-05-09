#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TAD_LISTA/TAD_LISTA.h" +

typedef struct contato
{
    char nome[81];
    char telefone[15];
} Contato;

Contato *identificar_contato(char *linha)
{
    char nome[100];
    char telefone[15];
    int contTelefone = 0;
    int i = 0;
    int j = 0;

    Contato *c = (Contato *)malloc(sizeof(Contato));

    for (i = 0; linha[i] != '\0'; i++)
    {
        if (linha[i] == ';')
        {
            break;
        }
    }

    // FOR PARA PERCORRER DO COMEÇO DO STRING ATÉ O ; (NOME)

    for (; j < i; j++)
    {
        nome[j] = linha[j];
    }
    nome[j] = '\0';

    for (j = i + 1; j < strlen(linha); j++)
    {
        telefone[contTelefone] = linha[j];
        printf("[%i] [%i]\n", contTelefone, j);
        contTelefone++;
    }
    telefone[contTelefone] = '\0';

    strcpy(c->nome, nome);
    strcpy(c->telefone, telefone);
    return c;
}

void ler_arquivo(FILE *f, Lista *lst)
{
    char linha[100];
    do
    {
        char *result = fgets(linha, 100, f);
        if (result)
        {
            identificar_contato(linha);
        }

    } while (!feof(f));
}

void resgatar(FILE *f, Lista *lst)
{
    ler_arquivo(f, lst);
}
int main(int argc, char const *argv[])
{
    // Criando a lista
    Lista *lst = lst_cria();

    FILE *f = fopen("arquivo_contatos.txt", "rt");
    // funções de entrada
    resgatar(f, lst);

    return 0;
}