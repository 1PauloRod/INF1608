#include <stdio.h>
#include <math.h>
#include "otimizacao.h"


double f1(double x){
    return x*x + sin(x);
}

double f2(double x){
    return x*x*x*x*x*x - 11*x*x*x + 17*x*x - 7*x + 1;
}


int main(void){
    
    double r, delta, xmin;
    int iteracao1, iteracao2;
    r = -1.0;
    delta = 0.5;
    
    
    iteracao1 = mips(r, delta, f1, &xmin);
    
    printf("para a funcao 1: \n");
    printf("valor de xmin: %.16g - numero de iteracoes: %d\n", xmin, iteracao1);
    
    printf("\n");
    
    
    r = 0.4;
    delta = 0.5;
    
    printf("para a funcao 2: \n");
    iteracao2 = mips(r, delta, f2, &xmin);
    printf("valor de xmin: %.16g - numero de iteracoes: %d\n", xmin, iteracao2);
    return 0;
}
