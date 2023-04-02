#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "vetor.h"
#include "gradconj.h"

int gradconj (int n, double** A, double* b, double* x, double tol){
    
	double* Ax = vet_cria(n);
	double* rk = vet_cria(n);
	double* dk = vet_cria(n);
	double* rk_mais_1 = vet_cria(n);
	double* dk_mais_1 = vet_cria(n);
	double* Adk = vet_cria(n);
	double* xk_mais_1 = vet_cria(n);
	double alphak, betak, rkTrk, dkTAdk, rTk_mais_1rk_mais_1;
    int iter = 0; 
	
	mat_multv(n, n, A, x, Ax);
	for (int i = 0; i < n; i++) {
		rk[i] = b[i] - Ax[i];
		dk[i] = rk[i];
	}
	
	for (int k = 0; k < n; k++) {
		if (vet_norma2(n, rk) < tol)
			return iter;
		
		rkTrk = 0.0;
		dkTAdk = 0.0;
		mat_multv(n, n, A, dk, Adk);
		for (int i = 0; i < n; i++) {
			rkTrk += rk[i] * rk[i];
			dkTAdk += dk[i] * Adk[i];
		}
		alphak = rkTrk/dkTAdk;
		
		for (int i = 0; i < n; i++){
			xk_mais_1[i] = x[i] + alphak * dk[i];
			rk_mais_1[i] = rk[i] - alphak * Adk[i];
		}
	    rTk_mais_1rk_mais_1 = 0.0;
		rkTrk = 0.0;
	
		for (int i = 0; i < n; i++) {
			rTk_mais_1rk_mais_1 += rk_mais_1[i] * rk_mais_1[i];
			rkTrk += rk[i] * rk[i];
		}
		betak = rTk_mais_1rk_mais_1/rkTrk;
		
		for (int i = 0; i < n; i++){
			dk_mais_1[i] = rk_mais_1[i] + betak * dk[i];
			
			x[i] = xk_mais_1[i];
			rk[i] = rk_mais_1[i];
			dk[i] = dk_mais_1[i];
		}
		iter++; 
	}
	
	return iter;
}

int gradconj_jacobi (int n, double** A, double* b, double* x, double tol){
    
	double** M = mat_cria(n, n);
    double* Ax = vet_cria(n);
	double* rk = vet_cria(n);
	double* dk = vet_cria(n);
	double* zk = vet_cria(n);
	double* rk_mais_1 = vet_cria(n);
	double* dk_mais_1 = vet_cria(n);
	double* Adk = vet_cria(n);
	double* xk_mais_1 = vet_cria(n);
	double* zk_mais_1 = vet_cria(n);
	double alphak, betak, rkTzk, dkTAdk, rTk_mais_1zk_mais_1;
    int iter = 0; 
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			M[i][j] = 0;
			if (i == j)
				M[i][j] = 1/A[i][j];
		}
		
	}
	
	mat_multv(n, n, A, x, Ax);
	for (int i = 0; i < n; i++) {
		rk[i] = b[i] - Ax[i];
	}
	mat_multv(n, n, M, rk, dk);
	mat_multv(n, n, M, rk, zk);
	
	for (int k = 0; k < n; k++) {
		if (vet_norma2(n, rk) < tol)
			return iter;
		
		rkTzk = 0.0;
		dkTAdk = 0.0;
		mat_multv(n, n, A, dk, Adk);
		for (int i = 0; i < n; i++) {
			rkTzk += rk[i] * zk[i];
			dkTAdk += dk[i] * Adk[i];
		}
		alphak = rkTzk/dkTAdk;
		
		for (int i = 0; i < n; i++){
			xk_mais_1[i] = x[i] + alphak * dk[i];
			rk_mais_1[i] = rk[i] - alphak * Adk[i]; 
		}
		mat_multv(n, n, M, rk_mais_1, zk_mais_1);
	    rTk_mais_1zk_mais_1 = 0.0;
		rkTzk = 0.0;
	
		for (int i = 0; i < n; i++) {
			rTk_mais_1zk_mais_1 += rk_mais_1[i] * zk_mais_1[i];
			rkTzk += rk[i] * zk[i];
		}
		betak = rTk_mais_1zk_mais_1/rkTzk;
		
		for (int i = 0; i < n; i++){
			dk_mais_1[i] = zk_mais_1[i] + betak * dk[i];
			
			x[i] = xk_mais_1[i];
			rk[i] = rk_mais_1[i];
			dk[i] = dk_mais_1[i];
			zk[i] = zk_mais_1[i];
		}
		iter++; 
	}
	
	return iter;
}
