#include "transversable.h"
#include <stdio.h>
#include <stdlib.h>

void transv(int tab[], int taille){
    int indice = 0;
    for (int i=0; i<taille-1; i++){
        if (indice > taille || indice < 0){
            printf("Le tableau n'est pas transversable\n");
            exit(0);
        }
        indice = indice + tab[indice];
        //printf("%d\n", indice);
    }
    if (indice = taille-1){
        printf("Le tableau est transversable!\n");
    }
    else {
        printf("Le tableau n'est pas transversable\n");
    }
}