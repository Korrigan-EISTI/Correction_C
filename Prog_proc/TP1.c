#include <stdio.h>

#include <stdlib.h>

/* Structure définissant une date */

typedef struct date {
    int jour;
    int mois;
    int annee;
}
Date;

/* Structure définissant une personne */

typedef struct prs {
    char nom[100];
    char prenom[100];
    Date date_naissance;
}
Personne;

/* EXERCICE 1 */

void affiche_nb() {
    int nb = 0; // On initialise le nombre à zéro
    if (nb != 0) { // Si la fonction c'est mal lancée
        exit(0); // On sort
    } else { // Sinon on demande une entrée et on affiche le nombre
        printf("Entrer un nombre : \n");
        scanf("%d", & nb);
        printf("Le nombre est : %d \n", nb);
    }
}

/* EXERCICE 3 */

void affiche_nb_deux() {
    // On initialise les nombres à zéro
    int nb = 0;
    int nb2 = 0;
    if ((nb != 0) || (nb2 != 0)) { // Si l'un des deux nombres n'est pas égal à zéro on exit
        exit(0);
    } else { // Sinon on affiche les deux nombres que l'utilisateur rentre
        printf("Entrer deux nombres : \n");
        scanf("%d", & nb);
        scanf("%d", & nb2);
        printf("Les nombres sont : %d et %d \n", nb, nb2);
    }
}

/* EXERCICE 4 */

void affiche_personne() {
    Personne prs; // On utilise le type personne définit plus haut
    printf("Entrer le nom le prenom et la jour, mois, annee de naissance \n");
    scanf("%s %s %d %d %d", & prs.nom, & prs.prenom, & prs.date_naissance.jour, & prs.date_naissance.mois, & prs.date_naissance.annee); // L'utilisateur entre toutes les valeurs voulue
    printf("Vous vous appelez %s %s et vous etes ne le %d/%d/%d \n", prs.nom, prs.prenom, prs.date_naissance.jour, prs.date_naissance.mois, prs.date_naissance.annee); // On les affiches
}

/* EXERCICE 5 */

void Division() {
    int n = 0, b = 0; // On initialise les deux variables à zéro
    if ((n != 0) || (b != 0)) { // Si on a mal initialisé on sort
        exit(0);
    } else { // Sinon on demande à l'utilisateur de rentrer deux nombres
        printf("Entrer deux nombres : \n");
        scanf("%d %d", & n, & b);
        if (b == 0) { // On ne peut pas diviser par 0 donc si b = 0 on sort
            printf("Division par 0\n");
            exit(0);
        } else { // Sinon on affiche la division
            printf("La division de %d et %d est : %lf \n", n, b, n / b);
        }
    }
}

/* EXERCICE 6 */

void produit() {
    int n = 0, b = 0; // On initialise les deux variables à zéro
    if ((n != 0) || (b != 0)) { // Si on a mal initialisé on sort
        exit(0);
    } else { // Sinon on demande à l'utilisateur de rentrer deux nombres
        printf("Entrer deux nombres : \n");
        scanf("%d %d", & n, & b);
        if (((b < 0) && (n > 0)) || ((b > 0) && (n < 0))) { // Si un des nombres est négatif, le produit est négatif
            printf("Produit negatif\n");
        } else { // Sinon le produit est positif
            printf("Produit positif");
        }
    }
}

/* EXERCICE 7 */

void predi() {
    int h, m;
    //On demande à l'utilisateur d'entrer une heure et des minutes
    printf("Entrer une heure et des minutes \n");
    scanf("%d %d", & h, & m);
    m++; // On incrémente les minutes
    if ((m > 0) && (h > 0)) { // Si tout est positif
        if (m == 60) { // Si on a une heure
            m = 0;
            h++; // On incrémente les heures
            if (h == 24) { // Si on est arrivé à un nouveau jour
                h = 0; // On passe à minuit
            }
        }
        printf("Dans 1 minute, il sera %d heure(s) %d minute(s) \n", h, m); // On affiche le tout
    }
}

/* EXERCICE 8 */

void compte_rebours_for() {
    // On demande à l'utilisateur d'entrer un temps en secondes
    printf("Entrer un temps en secondes \n");
    int n;
    scanf("%d", & n);
    for (int i = n; i >= 0; i--) {
        printf("%d \n", i); // On affiche le nombre i
    }
    printf("BOOM \n"); // A la fin on affiche BOOM
}

/* EXERCICE 9 */

void compte_rebours_while() {
    // On demande à l'utilisateur d'entrer un temps en secondes
    printf("Entrer un temps en secondes \n");
    int n;
    scanf("%d", & n);
    int i = n; // On initialise i à n
    do {
        printf("%d \n", i); // On affiche le nombre i
        i--; // On décrémente i 
    } while (i > -1); // On le fait tant que i>-1
    printf("BOOM \n"); // A la fin on affiche BOOM
}

/* MENU APPELANT TOUTES LES AUTRES FONCTIONS */

void menu() {
    // On demande à l'utilisateur d'entrer un choix
    int choix;
    printf("Entrer votre choix \n 1: Afficher un nombre \n 2: Afficher deux nombres \n 3: Afficher votre identite \n 4: Division de deux entier \n 5: Donne la valeur du signe du produit \n 6: Donne une prediction \n 7: Compte a rebours en boucle for \n 8: Compte a rebours en boucle while \n");
    scanf("%d", & choix);
    switch (choix) {
        case 1: // Cas 1 afficher un nombre
            affiche_nb();
            break;
        case 2: // Cas 2 Afficher deux nombres
            affiche_nb_deux();
            break;
        case 3: // Cas 3 Afficher l'identité d'une personne
            affiche_personne();
            break;
        case 4: // Cas 4 Faire une division
            Division();
            break;
        case 5: // Cas 5 Donner le signe d'un produit
            produit();
            break;
        case 6: // Cas 6 Donner une prédiction
            predi();
            break;
        case 7: // Cas 7 Compte à rebours avec la boucle for
            compte_rebours_for();
            break;
        case 8: // Cas 8 Compte à rebours avec la boucle while
            compte_rebours_while();
            break;
        default: // Cas par défaut on casse
            break;
    }
}

/* FONCTION PRINCIPALE */

int main(void) {
    menu(); // On appelle le menu
    return 0;
}