#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interp.h"
#include "vetor.h"


double f(double x){
    double o = 0.5;
    double u = 0.0;
    
    double parte1 = (1/sqrt(2*3.141592*o*o));
    double parte2 = -((x-u)*(x-u))/(2*o*o);
    double parte3 = exp(parte2);
    double resultado = parte1 * parte3;

    return resultado;
}


int main(void){

    
    int n = 6;
    int a = -2.0, b = 2.0;
    double newtonAvalia, funcao;

    double* xi1 = vet_cria(n);
    double* bi1 = vet_cria(n);
    double* xi2 = vet_cria(n);
    double* bi2 = vet_cria(n);

    regular(n, a, b, xi1);
    coeficientes(n, xi1, &f, bi1);

    printf("REGULAR: \n");
    for (double x = a; x <= b; x++){
        
        newtonAvalia = avalia(n, xi1, bi1, x);
        funcao = f(x);

        printf("x: %.16g\n", x);
        printf("f(x): %.16g\n", funcao);
        printf("avaliacao: %.16g\n", newtonAvalia);
    }
    printf("\nCHEBYSHEV: \n");
    chebyshev(n, a, b, xi2);
    coeficientes(n, xi2, &f, bi2);

    for (double x = a; x <= b; x++){
        
        newtonAvalia = avalia(n, xi2, bi2, x);
        funcao = f(x);

        printf("x: %.16g\n", x);
        printf("f(x): %.16g\n", funcao);
        printf("avaliacao: %.16g\n", newtonAvalia);
    }

    vet_libera(xi1);
    vet_libera(bi1);
    vet_libera(xi2);
    vet_libera(bi2);

    return 0;
}