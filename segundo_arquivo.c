#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int qtd_param, char* param[]){
 
    if (qtd_param == 2)
    {
        char* nome_arquivo = param[1];

        FILE* fp = fopen(nome_arquivo, "rt"); // Lê o arquivo de texto "rt"
        
        if(!fp)
        {
            printf("Erro ao abrir o arquivo: %s", nome_arquivo);
            exit(1);
        }
        
        printf("\nArquivo abriu com sucesso!\n");


        int c = 0;
        int nlinhas = 0;
        while ((c = fgetc(fp)) != EOF) // Lê o arquivo, e atribui o valor em "c". Depois compara com "EOF"
        {
            if(c == '\n') // Se for igual '\n' entre aspas simples
            {
                nlinhas++; // Incrementa a quantidade de linhas
            }
        }
        printf("Quantidade de linhas: %d",nlinhas+1);

    




        fclose(fp);
    }
    
    

    return 0;
}