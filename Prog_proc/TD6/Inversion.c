#include "Inversion.h"
#include "creerTableau.h"

void invert(int tab[], int taille){
    int debut = 0;
    int fin = taille-1;
    int tmp;
    for (int i=0; i<taille/2; i++){
        tmp = tab[debut];
        tab[debut] = tab[fin];
        tab[fin] = tmp;
        debut++;
        fin --;
    }
    affTab(tab, taille);
}