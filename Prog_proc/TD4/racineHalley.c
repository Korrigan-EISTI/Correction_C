#include "racineHalley.h"

float racineHalley(int k){
    float x=1;
    for (int i=0; i<k; i++){
        x=x*(((x*x)+6)/((3*x*x)+2));
    }
    return x;
}