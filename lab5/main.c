#include "mmq.h"
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "vetor.h"
int main(void){ 

    printf("Questao 2\n");
    printf("Letra (a)\n");
    printf("i.\n\n");
    int m = 5, n = 3;
    double** A1 = mat_cria(m, n);
    A1[0][0] = 3;
    A1[0][1] = -1;
    A1[0][2] = 2;
    A1[1][0] = 4;
    A1[1][1] = 1;
    A1[1][2] = 0;
    A1[2][0] = -3;
    A1[2][1] = 2;
    A1[2][2] = 1;
    A1[3][0] = 1;
    A1[3][1] = 1;
    A1[3][2] = 5;
    A1[4][0] = -2;
    A1[4][1] = 0;
    A1[4][2] = 3;

    double* b1 = vet_cria(m);
    b1[0] = 10;
    b1[1] = 10;
    b1[2] = -5;
    b1[3] = 15;
    b1[4] = 0;

    double* x = (double*)malloc(n * sizeof(double));

    double erro = mmq(m, n, A1, b1, x);

    printf("erro: %.16g\n", erro);
    printf("valores de x: ");
    for (int i = 0; i < n; i++){
        printf("x[%d] = %.16g\n", i, x[i]);
    }

    mat_libera(m, A1);
    vet_libera(b1);
    vet_libera(x);
    printf("\n\n");

    printf("ii.\n\n");
    int m2 = 5, n2 = 4;
    double** A2 = mat_cria(m2, n2);
    A2[0][0] = 4;
    A2[0][1] = 2;
    A2[0][2] = 3;
    A2[0][3] = 0;
    A2[1][0] = -2;
    A2[1][1] = 3;
    A2[1][2] = -1;
    A2[1][3] = 1;
    A2[2][0] = 1;
    A2[2][1] = 3;
    A2[2][2] = -4;
    A2[2][3] = 2;
    A2[3][0] = 1;
    A2[3][1] = 0;
    A2[3][2] = 1;
    A2[3][3] = -1;
    A2[4][0] = 3;
    A2[4][1] = 1;
    A2[4][2] = 3;
    A2[4][3] = -2;
    
    double* b2 = vet_cria(m2);
    
    b2[0] = 10;
    b2[1] = 0;
    b2[2] = 2;
    b2[3] = 0;
    b2[4] = 5;

    double* x2 = (double*)malloc(n2 * sizeof(double));

    double erro2 = mmq(m2, n2, A2, b2, x2);

    printf("erro: %.16g\n", erro2);
    printf("valores de x: ");
    for (int i = 0; i < n2; i++){
        printf("x[%d] = %.16g\n", i, x2[i]);
    }

    mat_libera(m, A2);
    vet_libera(b2);
    vet_libera(x2);
    printf("\n\n");

    printf("Letra (b)\n");
    printf(".i\n\n");

    double* px = vet_cria(4);
    px[0] = 0;
    px[1] = 1; 
    px[2] = 2;
    px[3] = 5;

    double* py = vet_cria(4);
    py[0] = 0;
    py[1] = 3; 
    py[2] = 3;
    py[3] = 6;

    printf("Ajuste de Parabola: \n");
    double ap1, bp1, cp1;
    double erro1Parabola = ajuste_parabola(4, px, py, &ap1, &bp1, &cp1);

    printf("Erro: %.16g\n", erro1Parabola);
    printf("valor de a: %.16g\n", ap1);
    printf("valor de b: %.16g\n", bp1);
    printf("valor de c: %.16g\n", cp1);
    printf("\n\n");
    printf("Ajuste de cubica: ");
    double ac1, bc1, cc1, dc1;
    double erro1Cubica = ajuste_cubica(4, px, py, &ac1, &bc1, &cc1, &dc1);
    printf("Erro: %.16g\n", erro1Cubica);
    printf("valor de a: %.16g\n", ac1);
    printf("valor de b: %.16g\n", bc1);
    printf("valor de c: %.16g\n", cc1);
    printf("valor de d: %.16g\n", dc1);

    printf("\n\n");

    double* px1 = vet_cria(4);
    px1[0] = 1;
    px1[1] = 3; 
    px1[2] = 4;
    px1[3] = 6;

    double* py1 = vet_cria(4);
    py1[0] = 2;
    py1[1] = 2; 
    py1[2] = 1;
    py1[3] = 3;

    printf(".ii\n\n");
    printf("Ajuste de Parabola: \n");
    double ap2, bp2, cp2;
    double erro2Parabola = ajuste_parabola(4, px1, py1, &ap2, &bp2, &cp2);

    printf("Erro: %.16g\n", erro2Parabola);
    printf("valor de a: %.16g\n", ap2);
    printf("valor de b: %.16g\n", bp2);
    printf("valor de c: %.16g\n", cp2);

    printf("\n\n");

    printf("Ajuste de cubica: ");
    double ac2, bc2, cc2, dc2;
    double erro2Cubica = ajuste_cubica(4, px1, py1, &ac2, &bc2, &cc2, &dc2);
    printf("Erro: %.16g\n", erro2Cubica);
    printf("valor de a: %.16g\n", ac2);
    printf("valor de b: %.16g\n", bc2);
    printf("valor de c: %.16g\n", cc2);
    printf("valor de d: %.16g\n", dc2);

    vet_libera(px);
    vet_libera(py);
    vet_libera(px1);
    vet_libera(py1);
    
    return 0;
}