#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void affichageSapin(){
    int n;
    int tailleDeLaBase;
    printf("Choisissez la hauteur du sapin ");
    scanf("%d", &n);
    printf("\n");
    tailleDeLaBase=(2*n)-1;
    for (int i=1; i<=n; i++){
        for (int j=0; j<n-i; j++){
            printf(" ");
        }
        for (int k=0; k<(2*i)-1; k++){
            printf("*");
        }
        printf("\n");
    }
    for (int l=0; l<3; l++){
        for (int m=0; m<((tailleDeLaBase-3)/2); m++){
            printf(" ");
        }
        printf("@@@\n");
    }
}

int factorielle (int nombre){
    int fact=1;
    for (int i=1; i<= nombre; i++){
        fact=fact*i;
    }
    return fact;
}

int rangFactorielle(){
    int k;
    int n=0;
    printf("Entrez un entier k: ");
    scanf("%d", &k);
    while (factorielle(n)<k){
        n++;
    }
    return n-1;
}

void nombreAmstrong(){
    int n;
    int somme=0;
    printf("Entrez un entier n: ");
    scanf("%d", &n);
    int nb= n;
    while (n/10 != 0){
        somme= somme+((n%10)*(n%10)*(n%10));
        n=n/10;
    }
    somme= somme+((n%10)*(n%10)*(n%10));
    if (somme == nb){
        printf("C'est un nombre d'Amstrong\n");
    }
    else {
        printf("Ce n'est pas un nombre d'Amstrong\n");
    }
}

void affichageBinaire(){
    int n;
    printf("Entrez un entier n: ");
    scanf("%d", &n);
    int nbr= n;
    int binaire=0;
    int multiplicateur=1;
    while (n != 0){
        if (n%2 != 0){
            binaire= binaire+(1*multiplicateur);
        }
        n= floor(n/2);
        multiplicateur=multiplicateur*10;
    }
    printf("%d\n", binaire);
}

void coeffBinom(){
    int c=0;
    int p;
    printf("Entrez un entier p: ");
    scanf("%d", &p);
    int n;
    printf("Entrez un entier n: ");
    scanf("%d", &n);
    c=((factorielle(n))/(factorielle(n-p)*factorielle(p)));
    printf("Résulat: %d\n ", c);
}

long coef_bin(int n, int p){
    long tmp =1;
    long tmp2 =1;
    if (n<p){
        tmp = -1;
    }
    else {
        for (int i=n; i>n-p; i--){
            tmp *= i;
            tmp2 *= i-n+p;
        }
    }
    return tmp/tmp2;
}

void flushScanf(){
    int res =0;
    char ch =0;
    do{
        res = scanf("%c", &ch);
    } while(res==1 &&- ch!='\n');
}

int getInt(){
    int result =0;
    int value =0;

    do{
        result = scanf("%d", & value);
        flushScanf();
    } while (result != 1);

    return value;
}

void menu(){
    int selection = -1;
    //while (selection != 0){
        printf("Bonjour! Choisissez une fonctionnalité. \n0. Quitter le programme. \n1. Affichage d'un sapin.\n2. Déterminer le rang d'une factorielle\n3. Nombre d'Amstrong\n4. Affichage d'un réel en binaire\n5. Coefficient Binomial\nChoix: ");
        scanf("%d", &selection);
        switch (selection)
        {
        case 0:
            exit(0);
            //break;

        case 1:
            affichageSapin();
            break;
        
        case 2:
            printf("%d\n", rangFactorielle());
            break;
        case 3:
            nombreAmstrong();
            break;
        case 4:
            affichageBinaire();
            break;
        case 5:
            coeffBinom();
            break;
        default:
            printf("Erreur: sélection invalide\n");
            break;
        }
    //}
}

int main(){
    menu();
}