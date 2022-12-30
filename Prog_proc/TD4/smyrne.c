#include "smyrne.h"
#include <stdio.h>

double racineSmyrne(int k){
    double p=1;
    double q=1;
    for (int i=0; i<k; i++){
        p=p+(2*q);
        //printf("%lf\n", p);
        q=(p-(2*q))+q;
        //printf("%lf\n", q);
    }
    return p/q;
}