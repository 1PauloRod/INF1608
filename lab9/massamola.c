#include "massamola.h"
#include <math.h> 

void forca (double t, double x, double y, double* fx, double* fy){
    
    double k = 0.3;
    double r = 200.0;
    double m = 2.0; 
    double g = 9.8; 
    double w = 10.0; 
    double fg = m * g;
    double fw = w * exp(-t/20.0);
    double x_barra = sqrt(x*x + y*y);
    
    double fkx = -k*(x_barra - r)*x/x_barra;
    double fky = -k*(x_barra - r)*y/x_barra;
    
    *fx = fw + fkx; 
    *fy = fg + fky; 
}

double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn){
    
    double fx, fy, m = 2.0, sigma = 0.002;
    
    forca(t, x, y, &fx, &fy);
    
    *xn = x + (1.0 - sigma)*(x - xp) + (h*h) * fx/m;
    *yn = y + (1.0 - sigma)*(y - yp) + (h*h) * fy/m;

    return t + h;
}
void simula (double x0, double y0, double t_final, int n, double* x, double* y){
     
    double t = 0.0, h = t_final/n, x_atual = x0, y_atual = y0, xp = x0, yp = y0;
    
    for(int i = 0; i < n; ++i){
    
        t = evolui(t, h, x_atual, y_atual, xp, yp, &x[i], &y[i]);
    
    
        xp = x_atual;
        yp = y_atual;
    
    
        x_atual = x[i];
        y_atual = y[i];
      
        
    }
}