#include <stdio.h>
#include <stdlib.h>
#include "sangamagrama.h"
#include "pi.h"
#include "wallis.h"
#include "newton.h"
#include "racineHalley.h"
#include "smyrne.h"
#define N 100

int main(){
    printf("Exercice 1 %f\n", calculPi(N));
    printf("Exercice 2 %f\n", sangaPi(N));
    printf("Exercice 3 %f\n", piWallis(N));
    printf("Exercice 4 %f\n", racineNewton(N));
    printf("Exercice 5 %f\n", racineHalley(N));
    printf("Exercice 6 %f\n", racineSmyrne(N));
}