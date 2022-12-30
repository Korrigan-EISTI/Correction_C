#include "newton.h"

float racineNewton(int k){
    float u=1;
    for (int i=0; i<k; i++){
        u=(u/2)+(1/u);
    }
    return u;
}