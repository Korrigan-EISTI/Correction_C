#include "pointeurPointeur.h"
#include <stdio.h>


void imprimePointeur(){
    int a; int b; int * p;
    int ** pp ;
    a = 0 ;b = 1 ;
    p = &a ;
    a += b ;
    pp = &p ;

    printf("a : %d\n", a);
    printf("*p : %d\n", *p);
    printf("**p : %d\n", **pp);
}