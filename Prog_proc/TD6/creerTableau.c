#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creerTableau.h"

void affTab(int T[], int taille){
    for (int i=0; i<taille; i++){
        printf(" %d |", T[i]);
    }
    printf("\n");
}

void nouveauTableau(int T[], int taille){
    int i;
    time_t t; //variable de temps
    srand((unsigned)time(&t));

    for (i=0;i<taille;i++){
        T[i]=rand()%100; //valeur entre 0 et 100
    }
}

