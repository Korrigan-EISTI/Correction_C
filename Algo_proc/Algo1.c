#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC(x)((x*)malloc(sizeof(x)))

/* EXERCICE 1 */

/* Structure définissant le type MinMax */

typedef struct mm{
    int min;
    int max;
}MinMax;

/* Procédure d'initialisation du tableau (on a pas besoin de return car c'est un pointeur) */

void init (int n, int* T){
    int entree;
    if (n == 0){ // Si la taille est égale à zéro on sort du programme
        exit(0);
    }else{ // Sinon pour chaque position du tableau on demande à l'utilisateur de rentrer une valeur 
        for (int i = 0; i<n; i++){
            printf ("Entrer la %d valeur du tableau : \n", i);
            scanf("%d", &entree);
            if (entree < 0){
                T[i] = -entree;
            }else{
                T[i] = entree;
            }
        }
    }
}

/* Fonction pour trouver le min max */

MinMax minmax (int T[], int n){
    MinMax mm;
    mm.min = T[0]; // On initialise le min à la première valeur du tableau
    mm.max = 0; // On initialise le max à zéro (il va nécessairement augmenter)
    for (int i = 0; i<n; i++){ // On boucle sur la longueur du tableau
        if (T[i]>mm.max){ // Si on a un nouveau max, on change la valeur de max
            mm.max = T[i];
        }else if (T[i]<mm.min){ // Sinon Si on a un nouveau min, on change la valeur de min
            mm.min = T[i];
        }
    }
    return mm; // On retourne le max et le min
}

/* EXERCICE 2 */

void devinette (){
    int n = rand () % 100; // On créé un nombre random en 1 et 100
    if (n < 0){ // Si on a un nombre négatif on sort du programme
        exit(0); 
    }else{ // Sinon
        int nb = 0;
        if (nb != 0){ // Si la variable c'est mal loadée, on sort du programme
            exit(0);
        }else{ // Sinon on demande à l'utilisateur de rentrer un nombre jusqu'à ce qu'il trouve le bon nombre
            printf ("Entrer un nombre : \n");
            scanf("%d", &nb);
            int i = 1;
             while (nb != n){
                printf ("Entrer un nombre : \n");
                scanf("%d", &nb);
                i++;
            }
            printf("Trouvé en %d coup(s)", i);
        }
    }
}

/* EXERCICE 3 */

int RechMot (char car){
    FILE* f;
    char c;
    int compt = 0;
    f = fopen("New Text Document.txt", "r");
    if (f == NULL){
        printf("Le chemin passe en parametre n'est pas bon \n");
        exit (0);
    }else{
        while (fread(&c, sizeof(char), 1, f)){
            if (car == c){
                compt++;
            }
        }
    }
    fclose(f);
    return compt;
}

void occurences (){
    char c;
    printf("Entrer un caractere a rechercher \n");
    scanf ("%s", &c);
    printf ("Il y a %d occurences du caractere %c \n", RechMot(c), c);
}

/* MENU */

void menu () {
    int choix = 0;
    if (choix != 0){ // Si la fonction c'est mal loadée, on sort du programme
        exit(0);
    }else{ // Sinon on laisse l'utilisateur choisir
        printf("Entrer votre choix \n 1: Min et Max d'un tableau \n 2: Cree un nombre entre 1 et 100 a deviner \n 3: Trouve le nombre d'occurences d'un caractere dans un texte \n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1 : // Cas 1 Min et Max
            printf ("Entrer la taille du tableau \n");
            int n;
            scanf("%d", &n);
            int* T;
            T = (int*)malloc(sizeof(int)*n);
            init(n, T);
            MinMax mm = minmax(T, n);
            printf ("Le min du tableau est %d et le max est %d \n", mm.min, mm.max);
            break;
        case 2 : // Cas 2 deviner un nombre aléatoire
            devinette();
            break;
        case 3:
            occurences();
            break;
        default: // Cas par défaut on sort
            break;
        }
    }
}

/* FONCTION PRINCIPALE */

int main (){
    menu(); 
    return 0;
}
