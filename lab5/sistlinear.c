#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"


void gauss (int n, double** A, double* b, double* x){

    double f, swap_temp;
    int p;
    int j, k, i;
    for(j = 0; j < n-1; j++){
        p = j;
        for (k = j + 1; k < n; k++){
            if (fabs(A[k][j]) > fabs(A[p][j])){
                p = k;
            }
        }
        for(k = j; k < n; k++){
            swap_temp = A[j][k];
            A[j][k] = A[p][k];
            A[p][k] = swap_temp;
        }
        swap_temp = b[p];
        b[p] = b[j];
        b[j] = swap_temp;
        
        for(i = j+1; i < n; i++){
            f = A[i][j]/A[j][j];
            for(k = j; k < n; k++)
            {
                A[i][k] -= A[j][k]*f;
            }
            b[i] -= b[j]*f;
        }
        
    }
    for (i = n - 1; i >= 0; i--){
        double a = 0;
        for (j = n - 1; j > i; j--){
            a += A[i][j]*x[j];
        }
        x[i] = (b[i] - a)/A[i][j];
    }
    

}