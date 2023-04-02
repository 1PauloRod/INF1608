
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ode.h"


double f(double t, double y){
    return t*y + (t*t*t);
}


int main(void){

    printf("Para Runge Kutta: \n\n");
    double y1 = RungeKutta(0, 2.4, 0.001, -1, f);
    printf("Valor: %.26g\n",y1);

    printf("\n\n");
    printf("Para Runge Kuttan adaptativo: \n\n");
    double y2 = RungeKuttaAdapt(0,2.4,-1,f,1e-12);
    printf("Valor: %.16g\n",y2);
    return 0;
}