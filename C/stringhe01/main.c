#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100+1 /// +1 perchè se mettiamo 100, ce ne sono solamente 99 utili
#define TRUE 1
#define FALSE 0

void menu(int *sc);

void clrcls(){
    system("@cls || clear"); /// cls per distribuzioni Linux, clear per Windows --> in questo modo generalizziamo il comando system("cls");
}
void sostituisciPunto(char frase[]);
int parolaPalindroma(char parola[]);
int anagramma(char parola[], char parola2[]);
int miaLen(char frase[]);
int miaUpper(char frase[]);
int miaLower(char frase[]);
int contaConsonantiVocali(char frase[]);
int invertiStringa(char frase[]);
int concatenaStringhe(char frase[], char frase2[], int maxlen);
int compareString(char frase[],char frase2[]);
void alternato(char frase[],char frase2[]);

int main()
{
    int scelta;
    char s[MAX],s2[MAX];
    for(int i=0;i<MAX;i++)
        s[i]='*';
    printf("Stampo stringa s: \n");
    puts(s); ///stampa stringa
    printf("Stampo stringa s: \n");
    s[0]='C';
    s[1]='I';
    s[2]='A';
    s[3]='O';
    s[4]='\0'; //tappo
    puts(s);
    printf("s[5]: %c\n\n",s[5]);

    do{
        menu(&scelta); ///con la "&" trasmetto per referenza l'INDIRIZZO della cella, senza essa trasmetto solo il valore, creando una copia del valore della variabile.
        fflush(stdin);
        switch(scelta){
        case 0:
            break;

        case 1:
            printf("Inserisci frase: ");
            //scanf("%s",&s);
            gets(s);
            sostituisciPunto(s);
            break;
        case 2:
            printf("Inserisci stringa: ");
            gets(s);
            contaConsonantiVocali(s);
            break;
        case 3:
            printf("Inserisci parola: ");
            gets(s);
            if(parolaPalindroma(s)==TRUE) //non esistono le variabili booleane, quindi usiamo 1 e 0 al posto di true e false
                printf("La parola e' palindroma");
            else
                printf("La parola NON e' palindroma");
            break;
        case 4:
            printf("Inserisci la prima parola: ");
            gets(s);
            printf("Inserisci la seconda parola: ");
            gets(s2);
            if(anagramma(s,s2)==TRUE)
                printf("%s e' l'anagramma di %s",s,s2);
            else
                printf("%s non e' l'anagramma di %s",s,s2);
            break;
        case 5:
            printf("Inserisci stringa: ");
            gets(s);
            miaLen(s);
            printf("\n");
            break;
        case 6:
            printf("Inserisci stringa: ");
            gets(s);
            printf("\n");
            miaUpper(s);
            printf("\n");
            break;
        case 7:
            printf("Inserisci stringa: ");
            gets(s);
            printf("\n");
            miaLower(s);
            printf("\n");
            break;
        case 8:
            printf("Inserisci stringa: ");
            gets(s);
            invertiStringa(s);
            break;
        case 9:
            printf("Inserisci la prima stringa: ");
            gets(s);
            printf("Inserisci la seconda stringa: ");
            gets(s2);
            concatenaStringhe(s,s2,MAX);
            break;
        case 10:
            printf("Inserisci la prima stringa: ");
            gets(s);
            printf("Inserisci la seconda stringa: ");
            gets(s2);
            if(compareString(s,s2)==1)
                printf("frase1 > frase2");
            else if(compareString(s,s2)==0)
                printf("frase1 = frase2");
            else if(compareString(s,s2)==-1)
                printf("frase1 < frase2");
            break;
        case 11:
            printf("Inserisci la prima stringa: ");
            gets(s);
            printf("Inserisci la seconda stringa: ");
            gets(s2);
            alternato(s,s2);
        default:
            printf("\nValore non corretto, RIPROVA\n");
            break;
        }
        fflush(stdin); ///fa una pulizia di tutti i valori inseriti nel buffer
        printf("\nPremi un tasto per continuare...");
        getchar(); ///attendo pressione pulsante per proseguire
        clrcls(); //system("cls");
    }while(scelta!=0);

    printf("\nProgramma terminato...\n");

    return 0;
}
void alternato(char frase[],char frase2[]){
    char frase3[MAX];
    int len1 = strlen(frase), len2 = strlen(frase2);
    int i=0, j=0, k=0;
    int esci = FALSE;

    while(esci == FALSE) {
        if(frase[i] != '\0') {
            frase3[k++] = frase[i++];
        }
        if(frase2[j] != '\0') {
            frase3[k++] = frase2[j++];
        }
        if(frase[i] == '\0' && frase2[j] == '\0') {
            esci = TRUE;
        }
    }
    frase3[k] = '\0';
    printf("\nLa stringa alternata e' %s",frase3);
}
int compareString(char frase[],char frase2[]){
    int lunghezza1=strlen(frase),lunghezza2=strlen(frase2);
    int ris;
    int uguali=0;

    for(int i=0;i<lunghezza1;i++)
        frase[i]=tolower(frase[i]);

    for(int i=0;i<lunghezza2;i++)
        frase2[i]=tolower(frase2[i]);

    int i=0;
    while((frase[i]!='\0') && (frase2[i]!='\0') && (frase[i]==frase2[i]))
        i++;
    if(frase[i]==frase2[i]){
        uguali=0;
    }else if(frase[i]>frase2[i]){
        uguali=1;
    }else uguali=-1;
    return uguali;
}
int concatenaStringhe(char frase[], char frase2[], int maxlen){
    printf("Prima stringa: ");
    puts(frase);
    printf("Seconda stringa: ");
    puts(frase2);
    int lunghezza1=strlen(frase);
    int lunghezza2=strlen(frase2);
    int i=0;
    printf("\nLunghezza prima stringa: %d",lunghezza1);
    printf("\nLunghezza seconda stringa: %d\n",lunghezza2);
    if((lunghezza1+lunghezza2)<=maxlen){
        while(frase[i]!='\0'){
            frase[lunghezza1+i]=frase2[i];
            i++;
        }
        frase[lunghezza1+i]='\0';
        printf("Stringhe concatenate: ");
        puts(frase);
    } else printf("\nImpossibile concatenare. Dimensione massima superata");
}
int invertiStringa(char frase[]){
    int lunghezza=strlen(frase);
    char aus;
    int j,i;
    j=lunghezza-1;
    while(i<j){
        aus=frase[i];
        frase[i]=frase[j];
        frase[j]=aus;
        i++;
        j--;
    }
    printf("La parola e': %s\n",frase);
}
int contaConsonantiVocali(char frase[]){
    int i,lunghezza=strlen(frase);
    int contatori[26];
    int posizione;
    int vocali,consonanti;

    for(i=0;i<26;i++){
        contatori[i]=0;
    }
    for(i=0;i<lunghezza;i++){
         if(frase[i]>='A'&&frase[i]<='Z'){
            posizione=frase[i]-'A';
            contatori[posizione]++;
         }
         else{
            if(frase[i]>='a'&&frase[i]<='z'){
                posizione=frase[i]-'a';
                contatori[posizione]++;
            }
         }
    }
    ///STAMPA DEL CONTATORE CON LE LETTERE DELL'ALFABETO MESSE UNA SOTTO ALL'ALTRA
    for(i=0;i<26;i++){
        printf("La lettere %c compare %d volte\n",'A'+i,contatori[i]);
    }
    ///CONTO LE VOCALI
    vocali=contatori['A'-'A'],contatori['E'-'A'],contatori['I'-'A'],contatori['O'-'A'],contatori['U'-'A'];
    ///CONTO LE CONSONANTI
    for(i=0;i<26;i++){
        consonanti+=contatori[i];
    }
    consonanti-=vocali;
    printf("Vocali: %d\n",vocali);
    printf("Consonanti: %d\n",consonanti);
}
int miaUpper(char frase[]){
    int lunghezza=strlen(frase); ///o si usa '\0' come tappo oppure si mette nel for di arrivare fino a strlen
    printf("\nLa stringa normale e': %s",frase);
    for(int i=0;frase[i]!='\0';i++){ ///utilizziamo il tappo
        if(frase[i]>96&&frase[i]<123) ///al posto di 96 potevamo mettere anche 'a' e al posto di 123 potevamo mettere 'z', perchè sono l'equivalente nel codice ASCII (linguaggio C riconosce il codice ASCIi)
            frase[i]-=32;
    }
    printf("\nParola in MAIUSCOLO\n");
    puts(frase);
}
int miaLower(char frase[]){
    int lunghezza=strlen(frase);
    printf("\nLa stringa normale e': %s",frase);
    for(int i=0;frase[i]!='\0';i++){
        if(frase[i]>64&&frase[i]<91) ///al posto di 64 potevamo mettere anche 'A' e al posto di 91 potevamo mettere 'Z', perchè sono l'equivalente nel codice ASCII
            frase[i]+=32;
    }
    printf("\nParola un minuscolo\n");
    puts(frase);
}
int miaLen(char frase[]){
    printf("La stringa e': ");
    puts(frase);
    int cont=0;
    do{
        cont++;
    }while(frase[cont] != '\0');
    /* int i=0;
    while(frase[i]!='\0'){
     i++; ///metodo alternativo (funzione)
    }
    return i;*/
    printf("La stringa ha %d caratteri",cont);
}
int anagramma(char parola[], char parola2[]){
    int lunghezza=0,lunghezza2=0;
    int anagramma, i=0;
    int num1[26],num2[26]; ///26 come i caratteri dell'alfabeto

    miaLower(parola);
    miaLower(parola2);

    //memorizzo la lunghezza delle due parole
    lunghezza=strlen(parola);
    lunghezza2=strlen(parola2);

    printf("\n%s\n%s\n",parola,parola2);

    if(lunghezza==lunghezza2){
            ///Inizializzo array interi
        for(i=0;i<26;i++){
            num1[i]=0;
            num2[i]=0;
        }
        i=0;
        while(parola[i]!='\0'){ ///possiamo anche usare un for ponendo la i=0 e che arriva fino alla lunghezza della stringa
            num1[parola[i]-97]++; ///potevamo fare anche -'a' al posto di -97
            num2[parola2[i]-97]++;
            i++;
        }
        /*for(i=0;i<26;i++){
            printf("%d\n",num1[i]);
        }
        for(i=0;i<26;i++){
            printf("%d\n",num2[i]);
        }*/
        while(i<26 && num1[i]==num2[i]){ ///prima metto la condizione "i<26" per evitare, nel caso in cui questa condiziona non venga soddisfatta, di fare un'altra condizione
            i++;
        }
        if(i==26)
            anagramma=TRUE;
        else
            anagramma=FALSE;

    }
    else
        anagramma=FALSE;
    return anagramma;
}

int parolaPalindroma(char parola[]){
    int lunghezza_stringa;
    lunghezza_stringa=strlen(parola);
    printf("\n");
    puts(parola);
    printf("La tua parola contiene %d caratteri (inclusi spazi)\n",lunghezza_stringa);

    for(int i=0;i<lunghezza_stringa;i++){
        parola[i]=tolower(parola[i]);
    }
    printf("\nLa parola (IN MINUSCOLO) inserita e': ");
    puts(parola);

    int i=0, j=lunghezza_stringa-1; ///indici che uso, "i" per l'inizio della parola, "j" per la fine della parola
    while(i<j && parola[i]==parola[j]){
        i++;
        j--;
    }
    if(i>=j) //superata la metà
        return TRUE;
    else
        return FALSE;
}

void sostituisciPunto(char frase[]){
    /// s => buongiorno 3B INF Sveglia!!!
    /*
        frasemodificata --> buongiorno
                            3B INF
                            Sveglia!!!
    */
    int lunghezza_stringa;
    char frasemodificata[MAX];
    lunghezza_stringa = strlen(frase);
    printf("\n");
    puts(frase);
    printf("\n");
    printf("La tua frase contiene %d caratteri (inclusi gli spazi)\n",lunghezza_stringa);
    for(int i=0; i<lunghezza_stringa; i++)
        if(frase[i]=='.')
            frasemodificata[i]='\n';
        else
            frasemodificata[i]=frase[i];
    frasemodificata[lunghezza_stringa]='\n';
    printf("La frase modificata e': \n%s\n\n\n",frasemodificata);
}

void menu(int *sc){
    printf("MENU'\n\n");
    printf("0. ESCI\n");
    printf("1. Sostituisci punto con carattere a capo\n");
    printf("2. Conta vocali e consonanti di una frase\n");
    printf("3. Verifica se la parola e' palindroma\n");
    printf("4. Verifica se le due parole sono l'anagramma dell'altro\n");
    printf("5. miaLen\n");
    printf("6. Stringa in maiuscolo\n");
    printf("7. Stringa in minuscolo\n");
    printf("8. Inverti stringa\n");
    printf("9. Concatenare due stringhe\n");
    printf("10. Compare string\n");
    printf("11. Alternato\n");

    printf("Scelta --> ");
    scanf("%d",sc);
}

