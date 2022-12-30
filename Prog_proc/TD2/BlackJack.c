/*



PROJET NON TERMINE




*/





#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NBJOUEUR 3

enum eCouleur{
    spade,
    heart,
    square,
    clover,
};

typedef struct{
    int* package;
    int id;
    char name;
} sJoueur;

typedef struct{
    int value;
    enum eCouleur color;
} sCarte;

void affTab(sCarte T[], int taille){
    for (int i=0; i<taille; i++){
        printf(" %d %d |", T[i].value, T[i].color);
    }
    printf("\n");
}

void affTabInt(int T[], int taille){
    for (int i=0; i<taille; i++){
        printf(" %d |", T[i]);
    }
    printf("\n");
}

void initializeCards(sCarte tab[52]){
    for (int i=0; i<13; i++){
        tab[i].color = 1;
        tab[i].value = i+1;}
    for (int i=13; i<26; i++){
        tab[i].color = 2;
        tab[i].value = i-13+1;}
    for (int i=26; i<39; i++){
        tab[i].color = 3;
        tab[i].value = i-26+1;}
    for (int i=39; i<52; i++){
        tab[i].color = 4;
        tab[i].value = i-39+1;}
    affTab(tab, 52);
}

void affCard(sCarte tab[52], int index){
    switch (tab[index].value)
    {
    case 11:
        printf("\nValet de ");
        break;
    case 12:
        printf("\nReine de ");
        break;
    case 13:
        printf("\nRoi de ");
        break;
    case 1:
        printf("\nAs de ");
        break;
    
    default:
        printf("\n%d de ", tab[index].value);
        break;
    }
    switch (tab[index].color)
    {
    case 1:
        printf("pic.\n");
        break;
    case 2:
        printf("coeur.\n");
        break;
    case 3:
        printf("carreau.\n");
        break;
    case 4:
        printf("trèfle.\n");
        break;
    
    default:
        exit(1);
        break;
    }
}

sCarte getCard(sCarte tab[52]){
    sCarte card;
    time_t t; //variable de temps
    srand((unsigned)time(&t));
    int i;
    do
    {
        i= rand()%52;
    } while (tab[i].value == 0);
    affCard(tab, i);
    card.value = tab[i].value;
    card.color = tab[i].color;
    tab[i].value = 0;
    return card;
    
}

int* allocInt(int size){
    int* pResult = NULL;
    if (size>0){
        pResult= malloc(size * sizeof(int));
    }
    return pResult;
}

int Csum(sCarte cards[21], int nbCartes){
    int sum=0;
    for (int i=0; i<nbCartes; i++){
        sum = sum + cards[i].value;
    }
    return sum;
}

int checkCards(sCarte cards[21], int nbCartes){
    if (Csum(cards, nbCartes) > 21){
        printf("Le total de vos cartes est de %d, vous êtes éliminé.\n", Csum(cards, nbCartes));
        return 1;
    }
    return 0;
}

int distrib(sCarte tab[52], sJoueur t[NBJOUEUR], sCarte cardsJ1[21],sCarte cardsJ2[21],sCarte cardsJ3[21],sCarte cardsJ4[21],sCarte cardsJ5[21],sCarte cardsJ6[21],sCarte cardsJ7[21], int nbJoueur){
    for (int i=0; i<NBJOUEUR; i++){
        printf("Choisir un nom: ");
        scanf("%s", &t[i].name);
        printf("\n");
    }
    int j=1;
    while (j<= NBJOUEUR){
        int answ;
        int k;
        switch (j)
        {
        case 1:
                cardsJ1[0] = getCard(tab);
                cardsJ1[1] = getCard(tab);
                affTab(cardsJ1, 2);
                k= 2;
                do {
                    printf("Voulez vous une carte supplémentaire ? (1 = oui, 0 = non)\n");
                    scanf("%d", &answ);
                    if (answ == 1){
                        cardsJ1[k]=getCard(tab);
                        k++;
                        //affTab(cardsJ1, k);
                        printf("Total: %d\n", Csum(cardsJ1, k));
                        //checkCards(cardsJ1, k);
                    }
                }while (answ == 1 && checkCards(cardsJ1, k) == 0);
            break;
        case 2:
                cardsJ2[0] = getCard(tab);
                cardsJ2[1] = getCard(tab);
                affTab(cardsJ2, 2);
                k= 2;
                do {
                    printf("Voulez vous une carte supplémentaire ? (1 = oui, 0 = non)\n");
                    scanf("%d", &answ);
                    if (answ == 1){
                        cardsJ2[k]=getCard(tab);
                        k++;
                        //affTab(cardsJ2, k);
                        printf("Total: %d\n", Csum(cardsJ2, k));
                        //checkCards(cardsJ2, k);
                    }
                }while (answ == 1 && checkCards(cardsJ2, k) == 0);
            break;
        case 3:
                cardsJ3[0] = getCard(tab);
                cardsJ3[1] = getCard(tab);
                affTab(cardsJ3, 2);
                k= 2;
                do {
                    printf("Voulez vous une carte supplémentaire ? (1 = oui, 0 = non)\n");
                    scanf("%d", &answ);
                    if (answ == 1){
                        cardsJ3[k]=getCard(tab);
                        k++;
                        //affTab(cardsJ3, k);
                        printf("Total: %d\n", Csum(cardsJ3, k));
                        //checkCards(cardsJ3, k);
                    }
                }while (answ == 1 && checkCards(cardsJ3, k) == 0);
            break;
        case 4:
                cardsJ4[0] = getCard(tab);
                cardsJ4[1] = getCard(tab);
                affTab(cardsJ4, 2);
                k= 2;
                do {
                    printf("Voulez vous une carte supplémentaire ? (1 = oui, 0 = non)\n");
                    scanf("%d", &answ);
                    if (answ == 1){
                        cardsJ4[k]=getCard(tab);
                        k++;
                        //affTab(cardsJ4, k);
                        printf("Total: %d\n", Csum(cardsJ4, k));
                        //checkCards(cardsJ4, k);
                    }
                }while (answ == 1 && checkCards(cardsJ4, k) == 0);
            break;
        case 5:
                cardsJ5[0] = getCard(tab);
                cardsJ5[1] = getCard(tab);
                affTab(cardsJ5, 2);
                k= 2;
                do {
                    printf("Voulez vous une carte supplémentaire ? (1 = oui, 0 = non)\n");
                    scanf("%d", &answ);
                    if (answ == 1){
                        cardsJ5[k]=getCard(tab);
                        k++;
                        //affTab(cardsJ5, k);
                        printf("Total: %d\n", Csum(cardsJ5, k));
                        //checkCards(cardsJ5, k);
                    }
                }while (answ == 1 && checkCards(cardsJ5, k) == 0);
            break;
        case 6:
                cardsJ6[0] = getCard(tab);
                cardsJ6[1] = getCard(tab);
                affTab(cardsJ6, 2);
                k= 2;
                do {
                    printf("Voulez vous une carte supplémentaire ? (1 = oui, 0 = non)\n");
                    scanf("%d", &answ);
                    if (answ == 1){
                        cardsJ6[k]=getCard(tab);
                        k++;
                        //affTab(cardsJ6, k);
                        printf("Total: %d\n", Csum(cardsJ6, k));
                        //checkCards(cardsJ6, k);
                    }
                }while (answ == 1 && checkCards(cardsJ6, k) == 0);
            break;
        case 7:
                cardsJ7[0] = getCard(tab);
                cardsJ7[1] = getCard(tab);
                affTab(cardsJ7, 2);
                k= 2;
                do {
                    printf("Voulez vous une carte supplémentaire ? (1 = oui, 0 = non)\n");
                    scanf("%d", &answ);
                    if (answ == 1){
                        cardsJ7[k]=getCard(tab);
                        k++;
                        //affTab(cardsJ7, k);
                        printf("Total: %d\n", Csum(cardsJ7, k));
                        //checkCards(cardsJ7, k);
                    }
                }while (answ == 1 && checkCards(cardsJ7, k) == 0);
            break;
        default:
            break;
        }
        j++;
    }
}

int tourCroupier(sCarte tab[52], sCarte croupier[21]){
    int sum = 0;
    int i = 0;
    while (sum < 17){
        croupier[i] = getCard(tab);
        sum = sum+ croupier[i].value;
        i++;
    }
    return sum;
}

int main(){
    sCarte tab[52];
    initializeCards(tab);
    sJoueur t[NBJOUEUR];
    sCarte cardsJ1[21];
    sCarte cardsJ2[21];
    sCarte cardsJ3[21];
    sCarte cardsJ4[21];
    sCarte cardsJ5[21];
    sCarte cardsJ6[21];
    sCarte cardsJ7[21];
    sCarte croupier[21];
    int nbJoueur=NBJOUEUR;
    distrib(tab, t, cardsJ1, cardsJ2, cardsJ3, cardsJ4, cardsJ5, cardsJ6, cardsJ7, nbJoueur);
    printf("Tous les Joueurs qui ont un total entre %d et 21 remportent le double de leur mise\n", tourCroupier(tab, croupier));
}