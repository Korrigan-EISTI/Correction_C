#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float partieReelle;
    float partieImaginaire;
} COMPLEXE;

typedef struct{
    COMPLEXE racine1;
    COMPLEXE racine2;
} SOLUTION;


SOLUTION resolution(float a, float b, float c){
    SOLUTION sol;
    float delta = (b*b)-(4*a*c);
    if (delta > 0){
        sol.racine1.partieReelle = (-b-(sqrt(delta)))/(2*a);
        sol.racine2.partieReelle = (b-(sqrt(delta)))/(2*a);
        sol.racine1.partieImaginaire = 0;
        sol.racine2.partieImaginaire = 0;
    }
    else if (delta == 0){
        sol.racine1.partieReelle = -b/(2*a);
        sol.racine2.partieReelle = 0;
        sol.racine1.partieImaginaire = 0;
        sol.racine2.partieImaginaire = 0;
    }
    else if (delta < 0){
        sol.racine1.partieReelle = (-b/(2*a));
        sol.racine2.partieReelle = (b/(2*a));
        sol.racine1.partieImaginaire = (sqrt(-delta)/(2*a));
        sol.racine2.partieImaginaire = (sqrt(-delta)/(2*a));
    }
    return sol;
}

int main(){
    float a, b, c;
    printf("Saisissez a:");
    scanf("%f", &a);
    printf("\nSaisissez b:");
    scanf("%f", &b);
    printf("\nSaisissez c:");
    scanf("%f", &c);
    SOLUTION sol= resolution (a,b,c);
    printf("Racine 1:\n");
    printf("%f", sol.racine1.partieReelle);
    printf("+i %f\n", sol.racine1.partieImaginaire);
    printf("Racine 2:\n");
    printf("%f", sol.racine2.partieReelle);
    printf("+i %f\n", sol.racine2.partieImaginaire);
}