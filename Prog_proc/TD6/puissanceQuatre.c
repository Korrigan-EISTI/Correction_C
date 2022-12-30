#include <stdio.h>
#include <stdlib.h>
#define taille 5

void initialiserMatrice(char tab[taille][taille]){
    for (int i=0; i<taille; i++){
        for (int j=0; j<taille; j++){
            tab[i][j]=' ';
        }
    }
}

void afficherMatrice(char tab[taille][taille], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%c | ", tab[i][j]);
        }
        printf("\n");
    }
}

void jouer(char tab[taille][taille], int n, int joueur){
    int colonne;
    do{
        printf("Sélectionner un numéro de colonne :");
        scanf("%d", &colonne);
        printf("\n");
    } while (colonne > n || colonne < 1);
    colonne--;
    int limite = taille-1;
    while (tab[limite][colonne] != ' '){
        limite --;
    }
    if (limite >= 0){
        if (joueur == 1 ){
            tab[limite][colonne] = 'X';
        }
        else if (joueur == 2){
            tab[limite][colonne] = 'O';
        }
        afficherMatrice(tab, taille);
    }
}

int verifLigne(char tab[taille][taille], int n){
    int verif =0;
    for (int i=0; i<n; i++){
        int compteur =0;
        for (int j=0; j<n-1; j++){
            if (tab[i][j] == tab[i][j+1] && tab[i][j] != ' '){
                if (compteur == 0){compteur =2;}
                else { compteur++; }
                if (compteur == 4){
                    verif = 1;
                }
            }
        }
    }
    return verif;
}

int verifColonne(char tab[taille][taille], int n){
    int verif =0;
    for (int j=0; j<n; j++){
        int compteur =0;
        for (int i=0; i<n-1; i++){
            if (tab[i][j] == tab[i+1][j] && tab[i][j] != ' '){
                if (compteur == 0){compteur =2;}
                else { compteur++; }
                if (compteur == 4){
                    verif = 1;
                }
            }
        }
    }
    return verif;
}

void affTab(int T[], int n){
    for (int i=0; i<n; i++){
        printf(" %c |", T[i]);
    }
    printf("\n");
}

int verifTab(int tab[], int n){
    int verif =0;
    for (int i=0; i<n/2; i++){
        for (int j=i; j< 4+i; j++){
            if (tab[j]==tab[j+1] && tab[j+1] == tab[j+2] && tab[j+2] == tab[j+3] && tab[j] != ' '){
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

int verifDiago1(char tab[taille][taille], int n){
    int verif=0;
    
    for (int i=0; i<n-1; i++){
        int k=n;
        int comparaison[n-i];
        for (int j=0; j<k-i; j++){
            //printf("[%d , %d]: %c\n", j+1, j+i+1, tab[j+i][j]);
            comparaison[j]=tab[j+i][j];
        }
        if (n-i >= 4){
            //affTab(comparaison,n-i);
            //printf("Vérification %d : %d\n",i, verifTab(comparaison, n-i));
            if (verifTab(comparaison, n-i)==1){verif =1;}
        }
    }
    if (verif != 1){
        for (int i=1; i<n-1; i++){
            int k=n;
            int comparaison[n-i];
            for (int j=0; j<k-i; j++){
                //printf("[%d , %d]\n", j+i+1, j+1);
                comparaison[j]=tab[j][j+i];
            }
        if (n-i >= 4){
            //affTab(comparaison,n-i);
            //printf("Vérification %d : %d\n",i, verifTab(comparaison, n-i));
            if (verifTab(comparaison, n-i)==1){verif =1;}
        }
        }
    }
    return verif;
}



int verifDiago2(char tab[taille][taille], int n){
    int verif=0;
    for (int i=0; i<n-1; i++){
        int k=n;
        int comparaison[n-i];
        int c=0;
        for (int j=k-1; j>=i; j--){
            //printf("[%d , %d]: %c\n", i+c+1, j+1, tab[j][i+c]);
            comparaison[j]=tab[i+c][j];
            c++;
        }
        if (n-i >= 4){
            //affTab(comparaison,n-i);
            //printf("Vérification %d : %d\n",i, verifTab(comparaison, n-i));
            if (verifTab(comparaison, n-i)==1){verif =1;}
        }
    }
    if (verif != 1){
        for (int i=1; i<n; i++){
            int k=n;
            int comparaison[n-i];
            int c=0;
            for (int j=k-1; j>=i; j--){
                //printf("[%d , %d]\n", j+1, j+i+1);
                comparaison[j]=tab[i+c][j];
                c++;
            }
            if (n-i >= 4){
            //affTab(comparaison,n-i);
            //printf("Vérification %d : %d\n",i, verifTab(comparaison, n-i));
            if (verifTab(comparaison, n-i)==1){verif =1;}
        }
        }
    }
    return verif;
}

int egalite(char tab[taille][taille], int n){
    int verif =1;
    for (int i=0; i<n; i++){
        if (tab[0][i]== ' '){
            verif =0;
        }
    }
    return verif;
}

int verif(char tab[taille][taille], int n){
    int verif =0;
    if ( verifColonne(tab, n)==1){
        verif =1;
    }
    else if (verifLigne(tab,n)==1){
        verif =1;
    }
    else if (verifDiago1(tab,n)==1){
        verif =1;
    }
    else if (verifDiago2(tab,n)==1){
        verif =1;
    }
    else if (egalite(tab,n)==1){
        verif =1;
    }
    return verif;
}

int main(){
    int i=0;
    int joueur;
    char tab[taille][taille];
    initialiserMatrice(tab);
    afficherMatrice(tab, taille);
    while(verif(tab, taille) != 1){
        if (i%2 == 0){
            joueur = 1;
        }
        else {
            joueur = 2;
        }
        jouer(tab, taille, joueur);
        i++;
        //printf("Vérification: %d\n", verif(tab, taille));
    }
    if (egalite(tab,taille)!=1){
        printf("Le Joueur %d a gagné!\n", joueur);
    }
    else{
        printf("Egalité!\n");
    }
}