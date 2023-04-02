#include <stdio.h>
#include <stdlib.h>
#include "taylor.h"




double pot(double n, int e){
    double power = 1.0;
    for (int i = 0; i < e; i++)
        power *= n;
    
    return power;
        
}

double fat(double n){
    
    if (n <= 1)
        return 1;
    return n * fat(n-1);
    
}

double avalia_taylor (int n, double *c, double x0, double x){
    
    
    double p = 0.0;
    for (int i = 0; i < n; i++){
        p += (c[i]/fat(i))*pot(x-x0, i);
    }
    return p;
}

double avalia_cosseno (int n, double x){
    
    double x0 = 0.0;
    double* c = (double*)malloc(n*sizeof(double));
    if (c == NULL) return 1;
    double j = -1.0;
    for (int i= 0; i < n; i++){
        if (i % 2 == 0){
            c[i] = -1 * j;
            j *= -1;
        }
        else{
            c[i] = 0;
        }
    }
    
    double avalia = avalia_taylor(n, c, x0, x);
    free(c);
    return avalia;
}

double avalia_seno (int n, double x){

    double x0 = 0.0;
    double* c = (double*)malloc(n*sizeof(double));
    if (c == NULL) return 1;
    double j = -1.0;
    for (int i= 0; i < n; i++){
        if (i % 2 != 0){
            c[i] = -1*j;
            j *= -1;
        }
        else{
            c[i] = 0;
        }
    }
    
    
    double avalia = avalia_taylor(n, c, x0, x);
    free(c);
    return avalia;
}
