#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"



double* vet_cria (int n){
    
    double* v = (double*)malloc(n * sizeof(double));
    if (v == NULL)
        return NULL;
    
    return v;
}

void vet_libera (double* v){

    free(v);

}

double vet_escalar (int n, double* v, double* w){

    double vx = 0.0;

    for (int i = 0; i < n; i++){
        vx += v[i]*w[i];
    }

    return vx;
}

double vet_norma2 (int n, double* v){

    double v2 = 0.0;

    for (int i = 0; i < n; i++){
        v2 += sqrt(v[i]*v[i]);
    }
    return v2;   
}

void vet_mults (int n, double* v, double s, double* w){

    for (int i = 0; i < n; i++){
        w[i] = s*v[i];
    }
}

void vet_imprime(int n, double* v){

    for (int i = 0; i < n; i++){
        printf("%g\t", v[i]);
    }
    printf("\n");
}