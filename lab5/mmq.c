#include "mmq.h"
#include "vetor.h"
#include "matriz.h"
#include "sistlinear.h"
#include <stdio.h>
#include <stdlib.h>

double mmq (int m, int n, double** A, double* b, double* x){

        double** AT = mat_cria(n, m);
        double** ATA = mat_cria(n, n);
        double* ATb = vet_cria(n);
        double* r = vet_cria(m);
        double* Ax = (double*)malloc(m * sizeof(double));
        if (Ax == NULL) exit(1);
        double norma2;

        mat_transposta(m, n, A, AT);
        mat_multm(n, m, n, AT, A, ATA);
        mat_multv(n, m, AT, b, ATb); 
        
        gauss(n, ATA, ATb, x);

        mat_multv(m, n, A, x, Ax);

        for (int i = 0; i < m; i++){
            
            r[i] = b[i] - Ax[i]; 
        }

        norma2 = vet_norma2(m, r);

        mat_libera(n, AT);
        mat_libera(n, ATA);
        vet_libera(ATb);
        vet_libera(r);
        return norma2;
}

double ajuste_parabola (int n, double* px, double* py, double* a, double* b, double* c){

    double** A = mat_cria(n, 3);    
    double* aux = vet_cria(3);
    double erro;
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < n; i++){
            if (j == 0)
                A[i][j] = 1;
            else if (j == 1)
                A[i][j] = px[i];
            else
                A[i][j] = px[i] * px[i];       
        }
    }
    
    erro = mmq(n, 3, A, py, aux);
    *a = aux[0];
    *b = aux[1];
    *c = aux[2];
    return erro;
}

double ajuste_cubica (int n, double* px, double* py, double* a, double* b, double* c, double* d){
    double** A = mat_cria(n, 4);    
    double* aux = vet_cria(4);
    double erro;
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < n; i++){
            if (j == 0)
                A[i][j] = 1;
            else if (j == 1)
                A[i][j] = px[i];
            else if (j == 2)
                A[i][j] = px[i] * px[i];
            else       
                A[i][j] = px[i] * px[i] * px[i];
        }
    }
    
    erro = mmq(n, 4, A, py, aux);
    *a = aux[0];
    *b = aux[1];
    *c = aux[2];
    *d = aux[3];
    return erro;
}