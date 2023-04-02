#include <stdio.h>
#include <math.h>
#include "metiter.h"
#include "matriz.h"
#include "vetor.h"



int main(void){
    
    double tol = pow(10.0, -7);
    double w = 1.1;
    int iter1, iter2;

    double** A1 = mat_cria(2, 2);
    A1[0][0] = 3;
    A1[0][1] = 1;
    A1[1][0] = 1;
    A1[1][1] = 2;

    double* b1 = vet_cria(2);
    b1[0] = 5;
    b1[1] = 5;

    double* x1 = vet_cria(2);
    
    iter1 = gauss_seidel(2, A1, b1, x1, tol);


    printf("Metodo de gauss seidel A1: \n");
    for (int i = 0; i < 2; i++){
        printf("%g ", x1[i]);
    }
    printf("\n");
    printf("numero de iteracoes: %d\n", iter1);

    vet_libera(x1);
    x1 = vet_cria(2);

    iter1 = sor_gauss_seidel(2, A1, b1, x1, tol, w);

    printf("Metodo de sor gauss seidel A1: \n");
    for (int i = 0; i < 2; i++){
        printf("%g ", x1[i]);
    }
    printf("\n");
    printf("numero de iteracoes: %d\n", iter1);

    vet_libera(x1);
    mat_libera(2, A1);

    double** A2 = mat_cria(6, 6);
    A2[0][0] = 3;
    A2[0][1] = -1;
    A2[0][2] = 0;
    A2[0][3] = 0;
    A2[0][4] = 0;
    A2[0][5] = 0.5;
    A2[1][0] = -1;
    A2[1][1] = 3;
    A2[1][2] = -1;
    A2[1][3] = 0;
    A2[1][4] = 0.5;
    A2[1][5] = 0;
    A2[2][0] = 0;
    A2[2][1] = -1;
    A2[2][2] = 3;
    A2[2][3] = -1;
    A2[2][4] = 0;
    A2[2][5] = 0;
    A2[3][0] = 0;
    A2[3][1] = 0;
    A2[3][2] = -1;
    A2[3][3] = 3;
    A2[3][4] = -1;
    A2[3][5] = 0;
    A2[4][0] = 0;
    A2[4][1] = 0.5;
    A2[4][2] = 0;
    A2[4][3] = -1;
    A2[4][4] = 3;
    A2[4][5] = -1;
    A2[5][0] = 0.5;
    A2[5][1] = 0;
    A2[5][2] = 0;
    A2[5][3] = 0;
    A2[5][4] = -1;
    A2[5][5] = 3;

    double* b2 = vet_cria(6);
    b2[0] = 2.5;
    b2[1] = 1.5;
    b2[2] = 1;
    b2[3] = 1;
    b2[4] = 1.5;
    b2[5] = 2.5;

    double* x2 = vet_cria(6);

    iter2 = gauss_seidel(6, A2, b2, x2, tol);


    printf("Metodo de gauss seidel A2: \n");
    for (int i = 0; i < 6; i++){
        printf("%g ", x2[i]);
    }
    printf("\n");
    printf("numero de iteracoes: %d\n", iter2);

    vet_libera(x2);
    x2 = vet_cria(6);

    iter2 = sor_gauss_seidel(6, A2, b2, x2, tol, w);
    
    printf("Metodo de sor gauss seidel A2: \n");
    for (int i = 0; i < 6; i++){
        printf("%g ", x2[i]);
    }
    printf("\n");
    printf("numero de iteracoes: %d\n", iter2);

    vet_libera(x2);
    mat_libera(6, A2);



    return 0; 
}