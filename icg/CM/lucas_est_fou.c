#include <stdio.h>
#include <string.h>

/*
Q1 : Comment mettre le texte txt="Bonjour" dans un prog C ?

C'est une chaîne de caractère
*/
void positionLettre(char *txt){
    printf("%s \n", txt);

    int lettre = 'z';
    int found = 1;

    for (int i = 0; i < strlen(txt); i++){
        if (txt[i]==lettre){
            printf("la lettre %c se trouve à la %i position \n", lettre, i);
            found = 0;
        }
    }
    if (found == 1){
        printf("la lettre '%c' ne se trouve pas dans le mot\n\n", lettre);
    }
}

void inverseTxt(char *txt){
    printf("l'inverse de Bonjour est : ");

    char *tempo[strlen(txt)] = txt;
    for (int i=strlen(txt); i>=0; i--){
        printf("%c", txt[i]);
    }
    printf("\n");

    printf("l'inverse de Bonjour est : ");
    for (int i=0, i2=strlen(txt)-1; i<strlen(txt); i++, i2--){
        txt[i]=tempo[i2];
        printf("%c", txt[i]);
    }
    printf("\n");

}


void main(){
    char txt[10]="Bonjour";
    positionLettre(txt);
    inverseTxt(txt);

}