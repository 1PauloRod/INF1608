#include "simpson.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f1(double x){
    return x/(sqrt(x*x + 9));
}

double f2(double x){
    return (2/sqrt(3.1415)) * exp(pow(-x, 2));
}

double f3(double x){
    return log(cos(x) + sin(x));
}


int main(void){

    double tolerancia = 0.5 * pow(10, -7);
    double valor1 = adaptsimpson(0, 1, f1, tolerancia);
    double valor2 = adaptsimpson(0, 3, f2, tolerancia);
    double valor3 = adaptsimpson(0, 3.1415/2, f3, tolerancia);

    printf("valor funcao 1: %.16g\n", valor1);
    printf("valor funcao 2: %.16g\n", valor2);
    printf("valor funcao 3: %.16g\n", valor3);

    printf("\n\n");

    for (int i = 1; i < 4; i++){
        printf("valor probabilidade para sigma = %d: %.16g\n", i, probabilidade(i));
    }
    
    return 0;
}