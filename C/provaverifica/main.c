#include <stdio.h>
#include <stdlib.h>
#define MAX 100+1

void menu(int *sc);
int contaC(char frase[],char x);
int miaLen(char frase[]);
void Upper(char frase[]);
void Lower(char frase[]);
void carattereRipetuto(char frase[]);

int main()
{
    char frase[MAX];
    int scelta;
    char x;
    do{
        menu(&scelta);
        fflush(stdin);
        switch(scelta){
            case 0:
                break;
            case 1:
                printf("Inserisci stringa:  ");
                gets(frase);
                printf("\nInserisci un carattere: ");
                scanf("%c",&x);
                contaC(frase,x);
                printf("\nLa lettera '%c' appare %d volte",x,contaC(frase,x));
                break;
            case 2:
                printf("Inserisci stringa: ");
                gets(frase);
                carattereRipetuto(frase);
            default:
                printf("\nValore non corretto, RIPROVA");
                break;
        }
        fflush(stdin);
        printf("\nPremi un tasto per continuare...");
        getchar();
        system("@cls || clear");
    }while(scelta!=0);
    printf("\nProgramma terminato...\n");
    return 0;
}

void carattereRipetuto(char frase[]){
    int cont=0;
    int max=0;
    char c=frase[0];

    for(int i=1; frase[i] != '\0'; i++)
    {
        if(frase[i] == frase[i-1])
            max++;
        else if(frase[i] == c)
            cont++;
        if(max > cont)
        {
            cont=max;
            max=0;
            c=frase[i];
        }
    }
    printf("La lettera che compare piu volte e' %c", c);
}
int miaLen(char frase[]){
    int i=0;
    while(frase[i]!='\0')
        i++;
    return i;
}
void Upper(char frase[]){
    int len=miaLen(frase);
    for(int i=0;frase[i]!='\0';i++){
        if(frase[i]>96&&frase[i]<123
           ){
            frase[i]-=32;
        }
    }
    printf("Parola in maiuscolo: ");
    puts(frase);
}
void Lower(char frase[]){
    for(int i=0;frase[i]!='\0';i++){
        if(frase[i]>64&&frase[i]<91){
            frase[i]+=32;
        }
    }
}
int contaC(char frase[],char x){
    int cont=0;
    Lower(frase);
    if(x>64&&x<91){
        x+=32;
    }
    for(int i=0;frase[i]!='\0';i++){
        if(x==frase[i])
            cont++;
    }
    return cont;
}
void menu(int *sc){
    printf("MENU'\n");
    printf("0. ESCI\n");
    printf("1. Data una stringa, conta quante volte e' presente X\n");
    printf("2. Stampa il carattere piu' ripetuto\n");

    printf("Scelta: ");
    scanf("%d",sc);
}
