#include<stdio.h>
#include<stdlib.h>

int main(int qtd_parem, char* param[])
{
   /*printf("Quantidade de paremetros: %d\n", qtd_parem);

    for(int i=0;i<qtd_parem;i++){
        printf("%s\n",param[i]);
    }*/ 
    
    FILE* fp;
    fp = fopen("arquivo.txt","r");
    if (fp==NULL)
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    printf("Arquivo abriu com sucesso!");
    fclose(fp);
    
    return 0;
}