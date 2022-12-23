#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* EXERCICE 1 */

void exe_1() { // Fonction d'entrée en matière avec fork()
    pid_t p;
    p = fork(); // Retourne -1 si erreur, 0 si dans le processus fils, le PID du fils dans le processus père
    printf("Je suis le processus %d mon père est %d \n", getpid(), getppid()); // getpid sert à avoir le pid du processus et getppid() sert à avoir celui du père
}

/* EXERCICE 2 */

void exe_2() {
    pid_t p;
    int a = 3, b = 5;
    p = fork(); // Retourne -1 si erreur, 0 si dans le processus fils, le PID du fils dans le processus père
    if (p == 0) { // Si on est dans le fils
        printf("La somme est : %d \n", a + b);
    } else { // Sinon
        if (p != -1) {
            printf("Le produit est : %d \n", a * b);
        } else {
            exit(EXIT_FAILURE);
        }

    }
}

/* EXERCICE 3 */

void exe_3() {
    pid_t p;
    int a = 4;
    int b = 5;
    p = fork();
    printf("Je suis le processus %d mon père est %d \n", getpid(), getppid());
    printf("L'adresse memoire de a et b est : %p et %p \n", & a, & b); // Même adresse vituelle mais pas la même physique
}

/* EXERCICE 4 */

void exe_4() {
    int reval, status = 0;
    pid_t p = fork();
    if (p == 0) { // Si on est dans l'enfant
        sleep(1); // On attend 1 sec
        printf("CHILD : Enter an exit value (0 to 255) : \n");
        scanf("%d", & reval);
        exit(reval); // On sort du processus fils avec la valeur entrée par l'utilisateur
    } else if (p > 0) {
        printf("PARENT: I wait my child to exit. \n"); // On attend la fin du processus enfant pour executer le père
        wait( & status);
        printf("PARENT: Child exit code is: %d \n", WEXITSTATUS(status)); // On affiche la valeur de sortie de processus du fils 
        exit(0);
    } else {
        exit(-1);
    }
}

/* EXERCICE 5 */

void exe_5() {
    int reval, status = 0, i;
    int pidreturn = 0;
    int monp;
    int n = 4;
    pid_t * p = (pid_t * ) malloc(sizeof(pid_t) * n); // Allocation mémoire du tableau contenant les fork()
    for (i = 0; i < n; i++) { // On met les fork dans le tableau
        p[i] = fork();
        monp = p[i];
        if (p[i] == 0) {
            printf("Fils PID %d avec i=%d en sortant de la boucle... \n", getpid(), i);
            sleep(1); // On attend pendant une seconde
            break;
        }
    }
    if (monp != 0) { //père
        do {
            printf("i: %d père mis en attente \n", i);
            pidreturn = wait( & status);
            printf("Père: pidreturn=%d terminé. Exit code est: %d \n", pidreturn, WEXITSTATUS(status));
        } while (pidreturn != -1);
    } else {
        printf("Fils PID %d valeur p[%d] = %d \n", getpid(), i, p[i]);
        exit(p[i]);
    }
}

/* MENU QUI APPELLE TOUTES LES AUTRES FONCTIONS */

void menu() {
    int choix;
    printf("Liste des choix: \n 1: Programme avec fork() \n 2: Programme avec somme et produit \n 3: Programme avec adressage \n 4: Programme sur la synchronisation \n 5: Programme sur la sychronisation de deux fork() \n");
    scanf("%d", & choix);
    switch (choix) // Selon le choix de l'utilisateur
    {
        case 1: // Cas 1
            exe_1(); // On lance l'exercice 1 
            break;
        case 2: // Cas 2
            exe_2(); //On lance l'exercice 2
            break;
        case 3: // Cas 3
            exe_3(); // On lance l'exercice 3
            break;
        case 4: // Cas 4
            exe_4(); // On lance l'exercice 4
            break;
        case 5: // Cas 5
            exe_5(); // On lance l'exercice 5
            break;
        default: // Par défaut on casse 
            break;
    }
}

/* FONCTION PRINCIPALE */

int main(void) {
    menu(); // On appelle le menu
    return 0;
}