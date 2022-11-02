#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

/* Fonction qui recherche des occurences dans un texte */

int RechMot (char car){
    FILE* f; 
    char c;
    int compt = 0;
    f = fopen("New Text Document.txt", "r"); // On ouvre un fichier
    if (f == NULL){ // Si il n'existe pas, on sort
        printf("Le chemin passe en parametre n'est pas bon \n");
        exit (0); 
    }else{ // Sinon
        while (fread(&c, sizeof(char), 1, f)){ // On parcours le fichier caractère par caractère
            if (car == c){ // Si le caractère lu est le même que celui selectionné
                compt++; // On incrémente le compteur
            }
        }
    }
    fclose(f); // On ferme le fichier
    return compt; // On retourne le compteur
}

/* Fonction initialisant la recherche des occurences */

void occurences (){
    // On demande à l'utilisateur d'entrer le caractère à étudier
    char c;
    printf("Entrer un caractere a rechercher :\n");
    scanf ("%c", &c);
    // On affiche le nombre d'occurences
    printf ("Il y a %d occurences du caractere %c \n", RechMot(c), c);
}

/* Exercice 4 */

/* Fonction qui calcule la puissance d'un nombre */

float puiss (float nb, int n){
    int prod = 1; // On initialise le produit à 1
    for (int i = 0; i<n; i++){
        prod = prod * nb; // On calcule la puissance
    }
    return prod; // On retourne la puissance
}

/* Fonction qui calcule la valeur d'un polynôme à un point donné */

void init_poly (int n, float nb){
    float sum = 0; // On initialise la somme
    if (n == 0){ // Si le polynôme est constant
        int a;
        puts ("Entrer un coefficient");
        scanf ("%d", &a);
        sum = a; // La somme est juste la constante
    }else{
        int coeff; 
        float puis;
        puts ("Entrer tous les coefficients \n");
        for (int i = 0; i<=n; i++){
            // On entre tous les coefficients devant les X
            printf ("Entrer le coefficient pour X^%d : \n", i);
            scanf("%d", &coeff);
            puis= puiss (nb, i); // On prend X à la puissance i
            sum = sum + (puis*coeff); // On calcule la somme
        }
    }
    printf ("Le polynome en %f vaut %f", nb, sum); // On affiche le résultat de la somme
}

/* Fonction initialisant le polynôme */

void poly (){
    int deg = 0;
    float nb = 0;
    if (nb != 0 || deg != 0){ // Erreur lors du chargement de la fonction
        puts ("Erreur de chargement \n");
        exit(0);
    }
    // On demande le degré du polynôme
    printf("Entrer le degres du polynome : \n");
    scanf("%d", &deg);
    // On demande le point auquel il est calculé 
    puts("Entrer un nombre reel :");
    scanf("%f", &nb);
    // On calcule le polynôme au point indiqué
    init_poly(deg, nb);
}

/* EXERCICE 5 */

/* Fonction qui calcule une factorielle */

void factorielle (){
    int nb = 0;
    int prod = 1;
    puts ("Entrer un nombre : ");
    scanf ("%d", &nb);
    for (int i = 1; i <= nb; i++){ // On boucle pour calculer la factorielle
        prod = prod * i;
    }
    printf ("La factorielle de %d est %d", nb, prod); // On affiche la factorielle
}

/* Fonction qui donne le PGCD de deux nombres */

void pgcd (){
    int nbr1, nbr2, pgcd, i;
  
    printf("Entrez deux entiers: ");
    scanf("%d", &nbr1);
    scanf("%d", &nbr2);
  
    for(i=1; i <= nbr1 && i <= nbr2; i++) // On s'arrête quand un des deux nombres est atteint
    {
        if(nbr1%i==0 && nbr2%i==0) // Si les deux nombres sont divisibles par i
            pgcd = i; // i devient le nouveau PGCD
    }
  
    printf("PGCD de %d et %d = %d", nbr1, nbr2, pgcd); // On affiche le PGCD
}

/* Fonction qui calcule le determinant d'une équation du second degré */

int delt (int a, int b, int c){
    int delta = ((b*b) - (4*a*c));
    return delta;
}

/* Fonction qui résoud une équation du second degré */

void second_deg (){
    int a, b, c;
    // On entre les coefficients a pour X^2, b pour X et c tout seul
    puts ("Entrer les coefficient a, b et c");
    scanf ("%d %d %d", &a, &b, &c);
    int delta = delt(a, b, c); // On calcule le determinant
    if (delta > 0){ // Si le déterminant est positif on a deux solutions réelles
        puts ("Deux solutions relles");
        printf ("x1 = %f et x2=%f", (-b + sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a)); // On affiche les deux solutions réelles
    }else{
        if (delta == 0){ // Si le déterminant est égal à zéro alors on a qu'une solution
            puts ("Une soltion relles");
            printf ("x= %f", -b/(2*a)); // On affiche cette solution
        }else{
            if (delta < 0){ // Si le déterminant est négatif alors on a deux solutions complexes
                puts("Pas de solutions reelles mais deux solutions complexes");
                printf("x1 = %f - i%f et x2 = %f +i%f", -b/(2*a), sqrt(abs(delta))/(2*a), -b/(2*a), sqrt(abs(delta))/(2*a)); // On affiche les deux solutions complexes
            }
        }
    }
}

/* Fonction de menu maths */

void menu_maths (){
    printf("\e[1;1H\e[2J"); // Clear le terminal
    int choix = 0;
    if (choix != 0){ // Si la fonction c'est mal loadée, on sort du programme
        exit(0);
    }else{ // Sinon on laisse l'utilisateur choisir
        printf("Entrer votre choix \n 1: factorielle \n 2: PGCD \n 3: Equation du second degre \n");
        scanf("%d", &choix);
        switch (choix){ // Selon le choix de l'utilisateur
        case 1: // Cas 1 on calcule la factorielle
            factorielle();
            break;
        case 2: // Cas 2 on calcule le PGCD de deux nombres
            pgcd();
            break;
        case 3: // Cas 3 on résouds une équation du second degré
            second_deg();
            break;
        default: // Cas par défaut on sort
            break;
        }
    }
}

/* MENU */

void menu () {
    int choix = 0;
    if (choix != 0){ // Si la fonction c'est mal loadée, on sort du programme
        exit(0);
    }else{ // Sinon on laisse l'utilisateur choisir
        printf("Entrer votre choix \n 1: Min et Max d'un tableau \n 2: Cree un nombre entre 1 et 100 a deviner \n 3: Trouve le nombre d'occurences d'un caractere dans un texte \n 4: Trouve la valeur d'un polynome quelquoncque en un point \n 5: Lance un menu effectuant des calculs mathematiques \n");
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
        case 3: // Cas 3 on recherche le nombre d'occurences d'un caractère dans un texte
            occurences();
            break;
        case 4 : // Cas 4 on calcule la valeur d'un polynome entrée par l'utilisateur
            poly();
            break;
        case 5: // Cas 5 on appelle un menu pour effectuer des calculs mathématiques
            menu_maths();
            break;
        default: // Cas par défaut on sort
            break;
        }
    }
}

/* FONCTION PRINCIPALE */

int main (){
    printf("\e[1;1H\e[2J"); // Clear le terminal
    menu(); 
    return 0;
}
