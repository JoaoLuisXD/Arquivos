#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int qtd_param, char * param[])
{
    if(qtd_param == 2)
    {
        FILE * fp = fopen("exercicio.txt", "rt");
    
        if(fp == NULL)
        {
            printf("erro ao abrir o arquivo\n");
            exit(1);
        }
        printf("arquivo aberto com sucesso\n");


        FILE * saida = fopen("saida_exercicio.txt", "wt");
        int c = 0;
        int qtd_linhas = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            if(c == '\n')
            {
                qtd_linhas++;
            }
            fputc(tolower(c),saida);
            
        }
        printf("quantidade de linhas: %d",qtd_linhas+1);
    

    }

    


    
    


    return 0;
}