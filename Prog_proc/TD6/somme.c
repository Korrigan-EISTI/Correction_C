#include "somme.h"
#include "creerTableau.h"

void sum(int tab1[], int tab2[], int taille){
    affTab(tab1, taille);
    affTab(tab2, taille);
    int tabVide[taille];
    for (int i=0; i<taille; i++){
        tabVide[i]= tab1[i]+ tab2[i];
    }
    affTab(tabVide, taille);
}