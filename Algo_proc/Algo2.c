#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Type définissant un point */

typedef struct pt{
    float x; // X
    float y; // Y
}Point;


/* Fonction donnant un vecteur à partir de deux points entrés par l'utilisateur */

Point vect (){
    Point a, b, vect;
    puts("Entrer les coordonnees du point A");
    scanf("%f %f", &a.x, &a.y);
    puts("Entrer les coordonnees du point B");
    scanf("%f %f", &b.x, &b.y);
    vect.x = b.x - a.x; // X_AB = X_B - X_A
    vect.y = b.y - a.y; // Y_AB = Y_B - Y_A
    return vect; // On retourne le vecteur
}

/* Foncton donnant le produit scalaire entre deux vecteurs */

float scalaire (Point v1, Point v2){ 
    return (v1.x*v2.x) + (v1.y*v2.y); // On retourne l'addition des produits des coordonnées des vecteurs
}

/* Fonction donnant le produit vectoriel de deux vecteurs */

float proVect (Point v1, Point v2){
    return (v1.x * v2.y) - (v1.y * v2.y); // u(x,y)^v(z,t) = xt - yz
}

/* Fonction menu pour agir sur les vecteurs */

void menu_vect (){
    int choix = 0;
    if (choix != 0){
        puts("Probleme dans le chargement de la fonction");
        exit(0);
    }else{
        puts("Entrer un choix: \n 1: Produits scalaires \n 2: Produits vectoriels"); // On donne les différents choix
        scanf ("%d", &choix); // L'utilisateur entre son choix
        // On créé les vecteurs
        Point v1 = vect(); 
        Point v2 = vect();
        switch (choix){
        case 1: // Cas 1 on calcule le produit scalaire
            printf ("Le produit vectoriel de v1=(%f,%f) et v2(%f,%f) est %f \n", v1.x, v1.y, v2.x, v2.y, scalaire (v1, v2));
            break;
        case 2: // Cas 2 on calcule le produit vectoriel
            printf ("Le produit vectoriel de v1=(%f,%f) et v2(%f,%f) est %f \n", v1.x, v1.y, v2.x, v2.y, proVect(v1, v2));
            break;
        default: // Cas par défaut on sort
            break;
        }
    }
}

/* Fonction menu appelant toutes les fonctions */

void menu (){
    int choix = 0;
    if (choix != 0){
        puts("Probleme dans le chargement de la fonction");
        exit(0);
    }else{
        puts("Entrer un choix: \n 1: Menu analyse de vecteurs"); // On donne les différents choix
        scanf ("%d", &choix); // L'utilisateur entre son choix
        switch (choix)
        {
        case 1: // Cas 1 on joue avec les vecteurs
            menu_vect();
            break;
        default: // Cas par défaut on sort 
            break;
        }
    }
}

/* Fonction principale */

int main (void){
    menu(); // On appelle le menu qui appelle toutes les autres fonctions
    return 0;
}