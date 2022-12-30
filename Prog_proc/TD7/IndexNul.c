#include <stdio.h>
#include "IndexNul.h"

void afficherIndexNuls (){
    int tab[8] = {1, 0, 4, 0, 3, 2, 1, 0};
    for (int* i=tab; i<&tab[8]; i++){
        if (*i ==0 ){
            printf("\n Index de l'élément nul: %d", ((int)(i-tab)));
        }
    }
}