#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "vetor.h"


int main(void){

    printf("Questao 1\n\n");

    double* v = vet_cria(3);
    double* w = vet_cria(3);

    v[0] = 1;
    v[1] = -1;
    v[2] = -2;

    w[0] = -2;
    w[1] = 2;
    w[2] = 2;

    // Testando a funçao 
    double vet_escalar_resultado = vet_escalar(3, v, w);
    printf("-> vetor escalar: v * w  = %g\n", vet_escalar_resultado);
    printf("\n");

    // Testando a funçao vet_norma2
    double vet_norma2_resultado = vet_norma2(3, v);

    printf("->vetor norma2: ||v||2 = %g\n", vet_norma2_resultado);
    printf("\n");

    // Testando vet_mults

    vet_libera(w);
    w = vet_cria(3);
    vet_mults(3, v, 2, w);
    printf("->vetor multiplicacao: w[i] = s*v[i]: ");
    vet_imprime(3, w);

    

    printf("Questao 2\n\n");
    int m = 3;
    int n = 3;
    double** A = mat_cria(m, n);
    double** B = mat_cria(n, m);
    double** C = mat_cria(m, n);
    double** T = mat_cria(n, m);

    A[0][0] = 5.0;
    A[0][1] = 0.0;
    A[0][2] = -4.0;
    A[1][0] = -5.0;
    A[1][1] = 0.0;
    A[1][2] = 5.0;
    A[2][0] = 4.0;
    A[2][1] = 2.0;
    A[2][2] = 3.0;
    

    B[0][0] = -1.0;
    B[0][1] = -5.0;
    B[0][2] = 2.0;
    B[1][0] = 1.0;
    B[1][1] = 5.0;
    B[1][2] = -3.0;
    B[2][0] = 5.0;
    B[2][1] = -3.0;
    B[2][2] = -5.0;

    printf("Matriz A\n");
    mat_imprime(m, n, A);
    printf("\n");

    printf("Matriz B\n");
    mat_imprime(n, m, B);
    printf("\n");

    mat_transposta(m, n, A, T); 
    printf("Matriz Transposta de A\n");
    mat_imprime(n, m, T);
    printf("\n");

    printf("Multiplica vetor\n");
    w = vet_cria(3);
    mat_multv (m, n, A, v, w);
    vet_imprime(n, w);
    printf("\n");

    printf("Multiplica matriz\n");
    mat_multm (m, n, n, A, B, C);
    mat_imprime(m, n, C);

    vet_libera(v);
    vet_libera(w);
    mat_libera(m, A);
    mat_libera(m, B);
    mat_libera(m, C);
    mat_libera(m, T);
    
       
    return 0;
}