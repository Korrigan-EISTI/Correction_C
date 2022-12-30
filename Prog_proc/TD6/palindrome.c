#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>

void palin(char tab[], int taille){
    int debut = 0;
    int fin = taille-1;
    int verif = 1;
    for (int i=0; i<taille/2; i++){
        if (tab[debut] != tab[fin]){
            printf("Ce n'est pas un palindrome\n");
            exit(1);
        }
        debut ++;
        fin --;
    }
    printf("C'est un palindrome!\n");
}