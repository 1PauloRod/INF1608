#include "sistlinear.h"
#include "matriz.h"
#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){

    double** mat1 = mat_cria(3, 3);
    double** mat2 = mat_cria(6, 6);
    double* b1 = vet_cria(3); 
    double* b2 = vet_cria(6);
    b1[0] = 0; b1[1] = 2; b1[2] = 3;
    b2[0] = 2.5; b2[1] = 1.5; b2[2] = 1; b2[3] = 1; b2[4] = 1.5; b2[5] = 2.5;
    double* x1 = vet_cria(3);
    double* x2 = vet_cria(6);

    mat1[0][0] = 1;
    mat1[0][1] = -1;
    mat1[0][2] = 0;

    mat1[1][0] = -1;
    mat1[1][1] = 2;
    mat1[1][2] = 1;

    mat1[2][0] = 0;
    mat1[2][1] = 1;
    mat1[2][2] = 2;


    mat2[0][0] = 3;
    mat2[0][1] = -1;
    mat2[0][2] = 0;
    mat2[0][3] = 0;
    mat2[0][4] = 0;
    mat2[0][5] = 0.5;

    mat2[1][0] = -1;
    mat2[1][1] = 3;
    mat2[1][2] = -1;
    mat2[1][3] = 0;
    mat2[1][4] = 0.5;
    mat2[1][5] = 0;

    mat2[2][0] = 0;
    mat2[2][1] = -1;
    mat2[2][2] = 3;
    mat2[2][3] = -1;
    mat2[2][4] = 0;
    mat2[2][5] = 0;

    mat2[3][0] = 0;
    mat2[3][1] = 0;
    mat2[3][2] = -1;
    mat2[3][3] = 3;
    mat2[3][4] = -1;
    mat2[3][5] = 0;

    mat2[4][0] = 0;
    mat2[4][1] = 0.5;
    mat2[4][2] = 0;
    mat2[4][3] = -1;
    mat2[4][4] = 3;
    mat2[4][5] = -1;

    mat2[5][0] = 0.5;
    mat2[5][1] = 0;
    mat2[5][2] = 0;
    mat2[5][3] = 0;
    mat2[5][4] = -1;
    mat2[5][5] = 3;


    printf("MATRIZ 1\n\n");
    printf("Matriz antes de Gauss: \n\n");
    mat_imprime(3, 3, mat1);
    printf("\n\n");
    printf("Matriz depois de Gauss: \n");
    gauss(3, mat1, b1, x1);
    printf("\n");
    mat_imprime(3, 3, mat1);
    printf("\n\n");

    printf("Resultado: ");
    vet_imprime(3, x1);

    printf("\n\n\n");
    
    printf("MATRIZ 2\n\n");
    printf("Matriz antes de Gauss: \n\n");
    mat_imprime(6, 6, mat2);
    printf("\n\n");
    printf("Matriz depois de Gauss: \n");
    gauss(6, mat2, b2, x2);
    printf("\n");
    mat_imprime(6, 6, mat2);
    printf("\n\n");

    printf("Resultado: ");
    vet_imprime(6, x2);
    printf("\n");

    mat_libera(3, mat1);
    mat_libera(6, mat2);
    vet_libera(b1);
    vet_libera(b2);
    vet_libera(x1);
    vet_libera(x2);

    return 0; 
}