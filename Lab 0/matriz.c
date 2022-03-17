#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

double** mat_cria(int m, int n){

    double** mat = (double**)malloc(m * sizeof(double*));
    if (mat == NULL) exit(1);

    for (int i = 0; i < m; i++){
        mat[i] = (double*)malloc(n * sizeof(double));
        if (mat[i] == NULL) exit(1);

    }
    return mat;   
}

void mat_libera(int m, double** A){
    
    for (int i = 0; i < m; i++){
        free(A[i]);
    }
    free(A);
}

void mat_transposta (int m, int n, double** A, double** T){
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            T[j][i] = A[i][j];
        }
    }
}

void mat_multv (int m, int n, double** A, double* v, double* w){

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            w[i] += A[i][j]*v[j];
        }
    }
}

void mat_multm (int m, int n, int q, double** A, double** B, double** C){

    for (int i = 0; i < m; i++){
        for (int j = 0, k = 0; k < n && j < n; j++, k++){
            C[i][k] += A[i][j]*B[j][k];
        }
    }
}

void mat_imprime(int m, int n, double** A){
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%g\t", A[i][j]);
        }
        printf("\n");
    }
}


