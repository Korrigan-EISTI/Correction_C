#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    int* pa;

    a=3;
    pa= &a;
    printf("%d\n", a);
    printf("%p\n", pa);
    printf("%d\n", *pa);
}