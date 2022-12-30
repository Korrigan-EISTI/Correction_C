#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

float calculPi(int n){
    time_t t;
    srand((unsigned)time(&t));
    int aire=0;
    for (int i=0; i<n; i++){
        int x= rand()%(n - n/2);
        int y= rand()%(n - n/2);
        //printf("Essai %d : %d\n",i, x);
        //printf("Essai %d : %d\n",i, y);
        //printf("\n");
        if ((x*x)+(y*y) <=  (n*n/4)){
            aire++;
        }
    }
    return (4.0*aire)/n;
}

