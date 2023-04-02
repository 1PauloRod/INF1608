#include "simpson.h"
#include <stdio.h>
#include <math.h>

double auxSimpson(double a, double b, double (*f) (double x), double* valor){

    
    double c = (a + b)/2;

	double ab = ((b - a)/6)*(f(a) + 4*f(c) + f(b));
	double ac = ((c - a)/6)*(f(a) + 4*f((a + c)/2) + f(c));
	double cb = ((b - c)/6)*(f(c) + 4*f((c + b)/2) + f(b));

	*valor = ac + cb;

	return fabs((ab - *valor)/15);
}


double adaptsimpson(double a, double b, double (*f) (double x), double tol){
    double valor;

	if(auxSimpson(a, b, f, &valor) <= tol)
	{
		return valor;
	}
	else
	{
		double c = (a + b)/2;
		return adaptsimpson(a, c, f, tol/2) + adaptsimpson(c, b, f, tol/2);
	}    

}

double funcExp(double x){
    return exp(pow(-x, 2)/2);
}

double probabilidade (double sigma){
    
    double tolerancia = 0.5 * pow(10, -7);
    double func = (1/(sqrt(2*3.1415))) * adaptsimpson(-sigma, sigma, funcExp, tolerancia);

    return func;

}