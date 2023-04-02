#include "integral.h"
#include <math.h>

double derivada (int n, double (*f) (double x), double x, double h){
    if (n < 1)
        return 1;
    return (2*derivada(n-1, f, x, h)*f(h/2) - f(h))/(2*derivada(n-1, f, x, h) - 1);
}


double simpson (double (*f) (double), double a, double b, int n){

    double h = (b - a) / n;
	double xi = a, integral = 0;
	
    for(xi = a; xi < b; xi += h){
        integral += (h/6) * (f(xi) + 4*f(xi + h/2) + f(xi + h));
        }
	
	return integral;
}
