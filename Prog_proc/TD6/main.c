#include <stdio.h>
#include <stdlib.h>
#include "Inversion.h"
#include "creerTableau.h"
#include "somme.h"
#include "transversable.h"
#include "palindrome.h"

#define M 20

int main(){
    /*int tab[M];
    nouveauTableau(tab, M);
    affTab(tab, M);
    invert(tab, M);
    int tab1[M];
    nouveauTableau(tab1, M);
    int tab2[M];
    nouveauTableau(tab2, M);
    printf("\n------------------------------------------------------------------------------------------\n\n");
    sum(tab1, tab2, M);*/
    int tab[6]={3, 7, 2, -1, 1, 9};
    transv(tab, 6);
    char chaineC[5]={'r','a','d','a','r'};
    palin(chaineC, 5);
}