#include "sangamagrama.h"

float sangaPi(int kMax){
    float pi=0;
    char sign =1;
    for (int k=0; k<kMax;k++, sign = -sign){
        pi += sign / (2.0*k+1);
    }
    return 4*pi;
}