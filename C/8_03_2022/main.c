#include <stdio.h>
#include <stdlib.h>
#define MAX 100+1
void menu(int *sc);
void cifraturaCesare(char s[]);
int Len(char s[]);
void decifraturaCesare(char s[]);
void es3(char s[]);
void cifraturaSostituzione(char s[], char alfabeto[], char alfabetoRnd[]);
void decifraturaSostituzione(char s[], char alfabeto[], char alfabetoRnd[]);
void upper(char s[]);
void alfabetornd(char alfabetoRnd[]){
    int i, pos, aus;

    srand(time(NULL));
    for(i=0; i<26; i++)
    {
        pos=rand()%26;
        aus=alfabetoRnd[i];
        alfabetoRnd[i]=alfabetoRnd[pos];
        alfabetoRnd[pos]=aus;
    }
}


int main()
{
    int scelta;
    char s[MAX];
    char alfabeto[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    char alfabetoRnd[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    alfabetornd(alfabetoRnd);
    do{
        menu(&scelta);
        fflush(stdin);
        switch(scelta){
            case 0:
                break;
            case 1:
                printf("Inserisci stringa: ");
                gets(s);
                cifraturaCesare(s);
                break;
            case 2:
                printf("Inserisci stringa: ");
                gets(s);
                decifraturaCesare(s);
                break;
            case 3:
                printf("Inserisci stringa: ");
                gets(s);
                es3(s);
                break;
            case 4:
                printf("\nLettere in ordine alfabetico --> %s\n", alfabeto);
                printf("\Lettere in ordine casuale --> %s\n", alfabetoRnd);
                printf("\nInserisci stringa: ");
                gets(s);
                cifraturaSostituzione(s,alfabeto,alfabetoRnd);
                break;
            case 5:
                printf("\Lettere in ordine alfabetico --> %s\n", alfabeto);
                printf("\Lettere in ordine casuale --> %s\n", alfabetoRnd);
                printf("\nInserisci stringa: ");
                gets(s);
                decifraturaSostituzione(s,alfabeto,alfabetoRnd);
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
void upper(char s[]){
    for(int i=0;i<Len(s);i++){
        if(s[i]>96 && s[i]<123)
            s[i]-=32;
    }
}
void cifraturaSostituzione(char s[], char alfabeto[], char alfabetoRnd[])
{
    upper(s);
    int i=0;
    while(s[i] != '\0'){
        if(s[i]>=65 && s[i]<91){
            s[i]=alfabetoRnd[s[i]-65];
        }
        i++;
    }
    printf("\nFRASE CIFRATA: %s\n", s);
}
void decifraturaSostituzione(char s[],char alfabeto[], char alfabetoRnd[]){
    upper(s);
    int i=0;
    while(s[i] != '\0'){
        if(s[i]>=65 && s[i]<91){
            s[i]=alfabeto[alfabetoRnd[s[i]-65]];
        }
        i++;
    }
    printf("\nFRASE DECIFRATA: %s\n", s);
}
void decifraturaCesare(char s[]){
    char ris[MAX];
    int len=Len(s);
    s[len]='\0';
    for(int i=0;i<len;i++){
        if(s[i]>67 && s[i]<91 || s[i]>99 && s[i]<123){
            ris[i]=(s[i]-3);
        }else
            if(s[i]>=65 && s[i]<68 || s[i]>=97 && s[i]<100){
                ris[i]=120+(s[i]-97);
            }
    }
    ris[len]='\0';
    printf("%s",ris);
}
void cifraturaCesare(char s[]){
    char ris[MAX];
    int len=Len(s);
    s[len]='\0';
    ris[len]='\0';
    for(int i=0;i<len;i++){
        if(s[i]>64 && s[i]<88 || s[i]>96 && s[i]<120){
            ris[i]=(s[i]+3);
        }else
            if(s[i]>=88 && s[i]<91 || s[i]>=120 && s[i]<123){
                ris[i]=97+s[i]-120;
            }
    }
    ris[len]='\0';
    printf("%s",ris);
}
int Len(char s[]){
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
void es3(char s[])
{
    upper(s);
    char aus;
    for(int j=1; j<26; j++)
    {
        printf("Chiave %i : ", j);
        for(int i=0; s[i] != '\0'; i++)
        {
            if(s[i]>64 && s[i]<91)
            {
                if(s[i]-j<65)
                    aus=(s[i]-64)-j+90;
                else
                    aus=s[i]-j;
            }
            printf("%c", aus);
        }
        printf("\n");
    }
}
void menu(int *sc){
    printf("MENU\n");
    printf("1. Cifratura di Cesare\n");
    printf("2. Decifratura di Cesare\n");
    printf("3. Decifratura di Cesare senza chiave\n");
    printf("4. Cifratura per sostituzione\n");
    printf("5. Decifratura per sostituzione\n");

    printf("Scelta --> ");
    scanf("%d",sc);
}
