#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raiz.h"

double f1(double x){
    return x*x*x + x - 7;
}

double f2(double x){
    return x*x*x*x + x + 1;
}

double f3 (double m){
    return 35.0-((9.8*m)/15.0)*(1.0-exp(-(15.0*9.0 )/m));
}



int main(void){

    double x0 = 1.5, x1 = 1.8;
    
    double* bissecaoRaiz = (double*)malloc(sizeof(double));
    if (bissecaoRaiz == NULL) return 1;
    double* secanteRaiz = (double*)malloc(sizeof(double));
    if (secanteRaiz == NULL) return 1;

    int iterBissecao = bissecao(x0, x1, f1, bissecaoRaiz);
    int iterSecante = secante(x0, x1, f1, secanteRaiz);

    printf("Letra (a) -> f(x) = x^3 + x - 7:\n");
    printf("Raiz Bissecao: %.16g - Num iteracao: %d\nRaiz secante: %.16g - Num iteracao: %d\n", *bissecaoRaiz, iterBissecao, *secanteRaiz, iterSecante);
    printf("\n");

    *bissecaoRaiz = 0.0;
    *secanteRaiz = 0.0;

    iterBissecao = bissecao(x0, x1, f2, bissecaoRaiz);
    iterSecante = secante(x0, x1, f2, secanteRaiz);

    printf("Letra (b) -> f(x) = x^4 + x + 1:\n");
    printf("Raiz Bissecao: %.16g - Num iteracao: %d\nRaiz secante: %.16g - Num iteracao: %d\n", *bissecaoRaiz, iterBissecao, *secanteRaiz, iterSecante);
    printf("\n");

    *bissecaoRaiz = 0.0;
   *secanteRaiz = 0.0;
    x0 = 40.0;
    x1 = 70.0;

    iterBissecao = bissecao(x0, x1, f3, bissecaoRaiz);
    iterSecante = secante(x0, x1, f3, secanteRaiz);

    printf("Letra (c) -> v - ((g*m)/c)*(1 - e^(-c/m*t))\n");
    printf("Raiz Bissecao: %.16g - Num iteracao: %d\nRaiz secante: %.16g - Num iteracao: %d\n", *bissecaoRaiz, iterBissecao, *secanteRaiz, iterSecante);
    printf("\n");

    free(bissecaoRaiz);
    free(secanteRaiz);
 
    return 0;
}