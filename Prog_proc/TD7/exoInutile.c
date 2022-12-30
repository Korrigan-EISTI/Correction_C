#include "exoInutile.h"
#include <stdio.h>

void inutile(){
    int i = 3;
    int * p = &i;
    printf("i : %d\n", i);
    *p = 2;
    printf("i après modification: %d\n", i);
}