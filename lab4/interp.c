#include <math.h>
#include "interp.h"
#include "matriz.h"


void regular (int n, double a, double b, double* xi){
    
    xi[0] = a;
    xi[n-1] = b;
    for (int i = 1; i < n-1; i++){
        xi[i] = ((b-a)/2)*i/n + (a+b)/2;
    }

}

void chebyshev (int n, double a, double b, double* xi){

    
    for (int beta = 1, i = 0; beta <= (2*n) - 1; beta += 2, i++){

        xi[i] = ((b - a)/2) * cos(beta*3.1415/(2*n)) + (a + b)/2;
    }

}

void coeficientes (int n, double* xi, double (*f) (double), double* bi){

    double** F = mat_cria(n, n);
    int c, j, i;
    for (c = 0; c < n; c++){
        i = 0;
        for (j = c; j < n; j++, i++){
            if (i == j)
               F[i][j] = f(xi[i]);
            
            else
                F[i][j] = (F[i + 1][j] - F[i][j-1])/(xi[j] - xi[i]);
        }
        bi[c] = F[0][c];
    } 
    mat_libera(n, F);
}

double avalia (int n, double* xi, double* bi, double x){

    double resultado = 0.0;
    double f;
    int i, j;

    for (i = 0; i < n; i++){

        f = 1;

        for (j = 0; j < i; j++){
            f *= (x - xi[j]);
        }
        resultado += bi[i] * f;
    }
    return resultado;
}

