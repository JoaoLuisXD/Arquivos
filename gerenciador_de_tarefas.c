#include <stdio.h>
#include <stdlib.h>

#define ARQUIVO_ENTRADA "tarefas.txt"
#define RELATORIO "relatorio.txt"

int main()
{
    FILE * fp = fopen(ARQUIVO_ENTRADA,"rt");
    int qtd_linhas = 0;
    int c = 0;
    int maior = 0;
    FILE * relatorio = fopen(RELATORIO,"wt");
    while ((c = fgetc(fp)) != EOF)
    {
        if(c == '\n')
        {
            qtd_linhas++;
        }
        fputc(c,relatorio);
    }
    int * vetor = (int*)malloc(qtd_linhas * sizeof(int));
    if (vetor == NULL)
    {
        exit(1);
        fclose(fp);
    }
    // Volta ao início do arquivo para ler os números
    rewind(fp);
    for (int i = 0; i < qtd_linhas; i++)
    {
        fscanf(fp,"%d%*c",&vetor[i]);
        if(maior < vetor[i])
        {
            maior = vetor[i];
        }
    }
    for (int i = 0; i < qtd_linhas; i++)
    {
        printf("%d\n",vetor[i]);
    }
    printf("maior: %d\n",maior);

    fprintf(relatorio,"maior: %d\n",maior);

    free(vetor);
    fclose(fp);
    return 0;
}