#include <stdio.h>
#include <stdlib.h>
#define MAX 100+1
#define TRUE 1
#define FALSE 0


int menu();

int Len(char s[]);
void Upper(char s[]);
void Lower(char s[]);

int es1(char s[],char x);
void es2(char s[],int n);
void es3(char s[]);
void es4(char s[],char s2[]);

int main()
{
    char s[MAX],s2[MAX];
    int scelta;
    char x;
    int n;
    do{
        scelta=menu();
        fflush(stdin);
        switch(scelta){
            case 0:
                break;
            case 1:
                printf("Inserisci stringa:  ");
                gets(s);
                printf("\nInserisci un carattere: ");
                scanf("%c",&x);
                es1(s,x);
                printf("\nLa lettera '%c' appare %d volte",x,es1(s,x));
                break;
            case 2:
                printf("Inserisci stringa: ");
                gets(s);
                do{
                    printf("Inserisci un numero compreso tra 1 e 10: ");
                    scanf("%d",&n);
                }while(n<=0 || n>10);
                es2(s,n);
                break;
            case 3:
                printf("Inserisci stringa: ");
                gets(s);
                es3(s);
                break;
            case 4:
                printf("Inserisci prima stringa: ");
                gets(s);
                printf("Inserisci seconda stringa: ");
                gets(s2);
                es4(s,s2);
                break;
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
int es1(char s[],char x){
    int cont=0;
    Lower(s);
    if(x>64&&x<91){
        x+=32;
    }
    for(int i=0;s[i]!='\0';i++){
        if(x==s[i])
            cont++;
    }
    return cont;
}
void es2(char s[],int n){
    int i=0;
    for(i=1;s[i]!='\0';i++){
        if(i%2==0){
            s[i]+=n;
        }else s[i]-=n;
    }
    printf("Frase modificata: %s",s);
}
void es3(char s[]){
    int conteggio[255]={0};
    int i=0, max;
    char ripetuto;
    while(s[i]!='\0'){
        conteggio[s[i]]++;
        i++;
    }
    max=0;
    for(i=0;i<255;i++){
        max=conteggio[i];
        ripetuto=i;
    }
    printf("\nIl carattere ripetuto più volte è %c",ripetuto);
}
void es4(char s[],char s2[]){
    int len=Len(s),len2=Len(s2);
    char s3[MAX];
    int i=0; //indice s,s2
    int k=0; //indice s3
    while((s[i]!='\0') && (s2[i]!='\0') && (len+len2!=MAX)){
        if(s[i]>s2[i]){
            s3[k++]=s[i++];
        }else s3[k++]=s2[i++];
    }
    s3[k]='\0';
    printf("Stringa3: %s",s3);
}


int Len(char s[]){
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
void Upper(char s[]){
    int len=Len(s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>96&&s[i]<123){
            s[i]-=32;
        }
    }
    printf("Parola in maiuscolo: ");
    puts(s);
}
void Lower(char s[]){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>64&&s[i]<91){
            s[i]+=32;
        }
    }
}
int menu(){
    int sc;
    printf("MENU'\n");
    printf("0. ESCI\n");
    printf("1. Conta carattere\n");
    printf("2. Cifratura\n");
    printf("3. Stampa il carattere piu' ripetuto\n");
    printf("4. Carica s3\n");

    printf("Scelta: ");
    scanf("%d",&sc);
    return sc;
}
