#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int qtd_param, char* param[]){
 
    if (qtd_param == 2) // Verifica se foi passado 1 argumento além do nome do programa (ex: ./programa arquivo.txt)
    {
        char* nome_arquivo = param[1]; // nome_arquivo = "arquivo.txt"

        FILE* fp = fopen(nome_arquivo, "rt"); // Lê o arquivo de texto "rt"
        
        // Se não conseguiu abrir o arquivo, exibe erro e encerra o programa
        if(!fp)
        {
            printf("Erro ao abrir o arquivo: %s", nome_arquivo);
            exit(1);
        }

        //Confirma a abertura do arquivo
        printf("\nArquivo abriu com sucesso!\n");

        //Cria/abre o arquivo de saída onde será escrito o conteúdo convertido para minúsculas
        FILE * saida = fopen("saida.txt", "wt");
        if(!saida)
        {
            printf("erro ao abrir arquivo saida.txt");
            exit(1);
        }


        


        int c = 0; // Variável pra armazenar cada caractere lido
        int nlinhas = 0; // Contador de linhas do arquivo original

        while ((c = fgetc(fp)) != EOF) // Lê o arquivo, e atribui o valor em "c". Depois compara com "EOF"
        {
            if(c == '\n') // Se for igual '\n' entre aspas simples
            {
                nlinhas++; // Incrementa a quantidade de linhas
            }
            
            // Escreve o caractere no novo arquivo, convertendo pra minúsculo
            fputc(tolower(c),saida);
            
            
        }
        printf("Quantidade de linhas: %d",nlinhas+1);

        




        fclose(fp); //Fecha o arquivo original
        fclose(saida); //Fecha a saída (boa prática)
    }
    
   

    return 0;
}