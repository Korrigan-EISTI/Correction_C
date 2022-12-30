#include <stdio.h>
#include <stdlib.h>
#include "decalage.h"

int main(){
    char Chaine[20+1]={ 'B', 'o', 'n', 'j', 'o', 'u', 'r', '\0' };
    char Cle[19+1]={ 'C', 'o', 'u', 'c', 'o', 'u', '\0' };
    printf("%s", codeCesar(Chaine, 3));
    printf("\n");
    printf("%s", codeVigenere(Chaine, Cle));
    printf("\n");
}