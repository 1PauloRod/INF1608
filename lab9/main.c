#include <stdio.h>
#include <stdlib.h>
#include "massamola.h"

int main(void){
    
    double *x = malloc(sizeof(double) * 1000);
    if (x == NULL) exit(1);
    double *y = malloc(sizeof(double) * 1000);
    if (y == NULL) exit(1);

    simula(200.0,0.0,100.0,1000,x,y);

    for(int i = 0; i < 1000; ++i){
        
        printf("[%d] - (%g, %g)\n", i, x[i],y[i]);
    }
    
    free(x);
    free(y); 

    return 0;
}
