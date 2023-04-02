#include <stdio.h>
#include <math.h>
#include "otimizacao.h"

#define TRUE 1

int mips (double r, double delta, double (*f) (double x), double* xmin){
    
    double denominador, x, s = r - delta, t = r + delta, fx = f(x), fr = f(r), fs = f(s), ft = f(t), avaliacao;
    int iteracao = 0;
    while(TRUE){
        
        if (iteracao > 50)
            return 0;
        
        if (iteracao >= 3){    
            avaliacao = fabs(fs - ft);
            if (avaliacao <= pow(10, -6)){
                *xmin = (s+t)/2;
        
                return iteracao;
            }
        }
        
        denominador =  2.0 * ((s - r) * (ft - fs) - (fs - fr) * (t - s));  
       
        if (denominador < pow(10, -10)){
            x = (r + s + t)/3.0;
        }else{
            x = ((r + s)/2.0) - ((fs - fr)*(t - r)*(t - s))/denominador;
        }
        fx = f(x);
        r = s; 
        fr = fs;
        s = t;
        fs = ft;
        t = x;
        ft = fx;
        
         
       
        iteracao++;
    }
    
    return iteracao; 
}