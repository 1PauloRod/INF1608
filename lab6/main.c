#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"

double f(double x) {
	return cos(x) - 2 * sin(x);
}

double f1(double x) {
	return -sin(x) - 2*cos(x);
}

double integral1(double x) {
	double denominador = sqrt(pow(x, 2) + 9);
	
	return x/denominador;
}

double integral2(double x) {
	return pow(x, 2) * log(x);
}

double integral3(double x) {
	return pow(x, 2) * sin(x);
}

int main(void){

    printf("QUESTAO 1)\n");
    printf("para h = 0\n");
    for (int i = 0; i < 10; i++){
        printf("%.16g\n", derivada(i, f, pow(10, -(i+1)), 0));
    }
    printf("\n");
    printf("para h = 1\n");
    for (int i = 0; i < 10; i++){
        printf("%.16g\n", derivada(i, f, pow(10, -(i+1)), 1));
    }
    printf("\n");
    printf("para h = 2\n");
    for (int i = 0; i < 10; i++){
        printf("%.16g\n", derivada(i, f, pow(10, -(i+1)), 2));
    }
    
    printf("\n\nQuestao 2)\n\n");
    printf("Integral 1\n");
    printf("Resultado = 2.0\n");
	printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral1, 0, 4, 16), simpson(integral1, 0, 4, 32));

    printf("\nIntegral 2\n");
	printf("Resultado = 6.9986217091241\n");
	printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral2, 1, 3, 16), simpson(integral2, 1, 3, 32));

    printf("\nIntegral 3\n");
	printf("Resultado = 5.8696044010894\n");
	printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral3, 0, M_PI, 16), simpson(integral3, 0, M_PI, 32));

    return 0; 
}