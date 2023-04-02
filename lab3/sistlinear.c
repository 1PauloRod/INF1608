#include <math.h>


void gauss (int n, double** A, double* b, double* x){

    double f, temp, s;
    int pivo;
    int j, k, i;

    //algoritmo de pivotamento
    for(j = 0; j < n-1; j++){
        pivo = j;
        for (k = j + 1; k < n; k++){
            if (fabs(A[k][j]) > fabs(A[pivo][j])){
                pivo = k;
            }
        }
        for(k = j; k < n; k++){
            temp = A[j][k];
            A[j][k] = A[pivo][k];
            A[pivo][k] = temp;
        }
        temp = b[pivo];
        b[pivo] = b[j];
        b[j] = temp;

        //algoritmo de eliminacao       
        for(i = j + 1; i < n; i++){
            f = A[i][j] / A[j][j];
            for(k = j; k < n; k++){
                A[i][k] -= A[j][k] * f;
            }
            b[i] -= b[j] * f;
        }
    }
        //algoritmo de retro-substituicao
    for (int i = n - 1; i >= 0; i--){
        s = 0.0;
        for (j = n - 1; j > i; j--){
            s += A[i][j] * x[j];
        }
        x[i] = (b[i]-s) / A[i][j];

    }      
}