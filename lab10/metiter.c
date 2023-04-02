#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "metiter.h"
#include "matriz.h"
#include "vetor.h"


int gauss_seidel (int n, double** A, double* b, double* x, double tol){

    double residuo_norma2 = INFINITY;
    double* residuo = vet_cria(n);
    double* Ax = vet_cria(n);
    int iter = 0;

    while (residuo_norma2 > tol){

        for (int i = 0; i < n; i++){
            x[i] = 0.0;
            for (int j = 0; j < n; j++){
                if (j != i){
                    x[i] += A[i][j] * x[j];
                }
            }
            x[i] = fabs(b[i] - x[i]) / A[i][i];
        }
        mat_multv(n, n, A, x, Ax);
        for (int i = 0; i < n; i++){
            residuo[i] = b[i] - Ax[i];
        }
        residuo_norma2 = vet_norma2(n, residuo);
        iter++;
    }
    vet_libera(residuo);
    vet_libera(Ax);
    return iter;
}

int sor_gauss_seidel (int n, double** A, double* b, double* x, double tol, double w){

    double residuo_norma2 = INFINITY;
    double* residuo = vet_cria(n);
    double* Ax = vet_cria(n);
    double* xis = vet_cria(n);
    int iter = 0;

    while (residuo_norma2 > tol){

        for (int i = 0; i < n; i++){
            xis[i] = 0.0;
            for (int j = 0; j < n; j++){
                if (j != i){
                    xis[i] += A[i][j] * x[j];
                }
            }
            x[i] = (1 - w) * x[i] + w / A[i][i] * (b[i] - xis[i]);
        }
        mat_multv(n, n, A, x, Ax);
        for (int i = 0; i < n; i++){
            residuo[i] = b[i] - Ax[i];
        }
        residuo_norma2 = vet_norma2(n, residuo);
        iter++;
    }
    vet_libera(residuo);
    vet_libera(Ax);
    return iter;
}