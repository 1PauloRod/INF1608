#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "taylor.h"
int main()
{
    int n = 11;
    
    printf("o valor da esquerda eh com a avaliacao das funcoes e o valor da direita eh da biblioteca math.h\n");
    for (int i = 0; i < n; i++){

        printf("***************PARA O TAMANHO n = %d**************\n", i);
        
        printf("->Para PI/10:\n");
        printf("   *Cosseno:\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_cosseno(i, 3.1451/10), cos(3.1451/10));
        printf("\n");
        printf("   *Seno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_seno(i, 3.1451/10), sin(3.1451/10));
        printf("\n");
        
        printf("->Para PI/8:\n");
        printf("   *Cosseno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_cosseno(i, 3.1451/8), cos(3.1451/8));
        printf("\n");
        printf("   *Seno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_seno(i, 3.1451/8), sin(3.1451/8));
        printf("\n");
        
        printf("->Para PI/6:\n");
        printf("   *Cosseno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_cosseno(i, 3.1451/6), cos(3.1451/6));
        printf("\n");
        printf("   *Seno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_seno(i, 3.1451/6), sin(3.1451/6));
        printf("\n");
        
        printf("->Para PI/4:\n");
        printf("   *Cosseno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_cosseno(i, 3.1451/4), cos(3.1451/4));
        printf("\n");
        printf("   *Seno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_seno(i, 3.1451/4), sin(3.1451/4));
        printf("\n");
        
        printf("->Para PI/3:\n");
        printf("   *Cosseno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_cosseno(i, 3.1451/3), cos(3.1451/3));
        printf("\n");
        printf("   *Seno\n"); 
        printf("       valor: %.16g\tvalor:%.16g\n", avalia_seno(i, 3.1451/3), sin(3.1451/3));
        printf("\n\n");
    }
    

    return 0;
}

