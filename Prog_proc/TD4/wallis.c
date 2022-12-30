#include "wallis.h"

float piWallis(int k){
    float pi=1;
    for (int i=1; i<k; i++){
        pi=((2.0*i)*(2.0*i))/((2.0*i)*(2.0*i)-1)*pi;
    }
    return 2*pi;
}