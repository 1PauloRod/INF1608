#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "raiz.h"

int bissecao (double a, double b, double (*f) (double x), double* r){

    double c;
    int numIteracao = 0;
    double fa = f(a), fb = f(b), fc;

    double eMax = 0.5 * pow(10.0, -8.0);

    if (fa * fb >= 0){
        return 0;
    }

    *r = 0;

    while (((b - a)/2.0) > eMax){
        
        c = (a+b)/2;
        fc = f(c);
        *r = c;

        if (fabs(fc) < pow(10, -12)){
           *r = c;
           break;
        }

        if (fa * fc < 0.0)
            b = c;
        else
            a = c;
        
        
        numIteracao++;
    }
    return numIteracao;
}

int secante (double x0, double x1, double (*f) (double x), double* r){

    int numIteracao = 0;
    double x2 = x1 - (f(x1)*(x1-x0))/((f(x1) - f(x0)));
    double eMax = 0.5 * pow(10, -10);
    
    while(fabs(f(x2)) > eMax){
        
        if (numIteracao >= 50){
            *r = 0.0;
            return 0;
        }

        *r = x2;

        if (fabs(f(x1) - f(x0)) < pow(10, -15))
            x2 = (x0 - x1)/2;
        else 
            x2 = x1 - (f(x1)*(x1-x0))/((f(x1) - f(x0)));
        
        x0 = x1;
        x1 = x2;    

        numIteracao++;
    }
    return numIteracao;
}


