#include <stdio.h>
#include <stdlib.h>
int main(int qtd_param, char * param[])
{

    if(qtd_param == 2)
    {
        FILE * fp = fopen("scan.txt", "rt");
        int a = 1;
        float b = 2.2;
        if(fp != NULL)
        {
            fscanf(fp, "%d %f", &a, &b);
        }
        printf("a = %d\n",a);
        printf("b = %.2f\n",b);
        fclose(fp);

        FILE * write = fopen("scan.txt", "wt");
        fprintf(write,"%d\n",a);
        fprintf(write,"%.2f\n",b);
        
    }
        
        
        


    return 0;
}