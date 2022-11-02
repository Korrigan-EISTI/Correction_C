#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pt{
    float x;
    float y;
}Point;

Point vect (){
    Point a, b, vect;
    puts("Entrer les coordonnees du point A");
    scanf("%f %f", &a.x, &a.y);
    puts("Entrer les coordonnees du point B");
    scanf("%f %f", &b.x, &b.y);
    vect.x = b.x - a.x;
    vect.y = b.y - a.y;
    printf ("x : %f y : %f \n", vect.x, vect.y);
    return vect;
}

float scalaire (Point v1, Point v2){
    float sum = (v1.x*v2.x);
    sum = sum + (v1.y*v2.y);
    printf ("%f \n", sum);
    return sum;
}

float proVect (Point v1, Point v2){
    return (v1.x * v2.y) - (v1.y * v2.y);
}

void menu_vect (){
    int choix = 0;
    if (choix != 0){
        puts("Probleme dans le chargement de la fonction");
        exit(0);
    }else{
        puts("Entrer un choix: \n 1: Produits scalaires \n 2: Produits vectoriels");
        scanf ("%d", &choix);
        Point v1 = vect();
        Point v2 = vect();
        switch (choix){
        case 1:
            printf ("Le produit vectoriel de v1=(%f,%f) et v2(%f,%f) est %f \n", v1.x, v1.y, v2.x, v2.y, scalaire (v1, v2));
            break;
        case 2:
            printf ("Le produit vectoriel de v1=(%f,%f) et v2(%f,%f) est %f \n", v1.x, v1.y, v2.x, v2.y, proVect(v1, v2));
            break;
        default:
            break;
        }
    }
}

void menu (){
    int choix = 0;
    if (choix != 0){
        puts("Probleme dans le chargement de la fonction");
        exit(0);
    }else{
        puts("Entrer un choix: \n 1: Menu analyse de vecteurs");
        scanf ("%d", &choix);
        switch (choix)
        {
        case 1:
            menu_vect();
            break;
        default:
            break;
        }
    }
}

int main (void){
    menu();
    return 0;
}