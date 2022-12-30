#include "decalage.h"
#include <math.h>

char* codeCesar(char* texte, int decal){
    int i=0;
    while (texte[i] != '\0'){
        texte[i]= texte[i]+decal;
        i++;
    }
    return texte;
}
char* codeVigenere(char* string, char* cle){
    int decal=0, tmp=0,j=-1;

    for (int i = 0; i < strlen(string); i++)
    {     
        if(j==strlen(cle)){
            j=0;
        }else{
            j++;
        }
        if(string[i]>='A' && string[i]<='Z'){ //majuscule
            decal=abs(65-cle[j]);
            if((string[i]+decal)>90){
                tmp=90-(int)string[i];
                tmp=decal-tmp;
                string[i]=64+tmp;
            }else{
                string[i]=(int)string[i]+decal;
            }
        }
    }
    printf("La chaîne cryptée est : %s\n",string);
}

void scytale(char* string){
    float longueur=sqrt(strlen(string));
    if(longueur-floor(longueur)!=0){
        longueur=floor(longueur)+1;
    }
    char bloc[(int)longueur][(int)longueur];
    int y = 0;
    for (int i = 0; i < (int)longueur; i++)
    {
        for (int j = 0; j < (int)longueur; j++)
        {
            if(y==strlen(string)){
                bloc[i][j]=32;
            }else{
                bloc[i][j]=string[y];
                y++;
            }
        }
    }
    y=0;
    for (int i = 0; i < longueur; i++)
    {
        for (int j = 0; j < longueur; j++)
        {
            string[y]=bloc[j][i];
            y++;
        }
    }
    printf("Le/la mot/phrase crypté est : %s\n",string);
}
