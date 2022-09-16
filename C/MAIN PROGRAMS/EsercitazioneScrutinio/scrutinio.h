#ifndef SCRUTINIO_H_INCLUDED
#define SCRUTINIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTI 20 ///RIGHE
#define LEN_STUDENTE 30+1 ///LUNGHEZZA COGNOME DELLO STUDENTE
#define TOT_MATERIE 5 ///MEDIE
#define TRUE 1
#define FALSE 0

void valutazioniFile(char studenti[MAX_STUDENTI][LEN_STUDENTE], float valutazioni[MAX_STUDENTI][TOT_MATERIE], char esito[MAX_STUDENTI], float medie[MAX_STUDENTI], int pos);

float floatRand(float min, float max){
    float val;
    val = rand() / (float) RAND_MAX;  // genera numeri casuali compresi tra 0 e  1.0
    return min + (val * (max - min));
}

int nuovoStudente(char studenti[MAX_STUDENTI][LEN_STUDENTE],float valutazioni[MAX_STUDENTI][TOT_MATERIE],int pos,float medie[MAX_STUDENTI],char esito[MAX_STUDENTI]){ //uso "pos" al posto di totStudenti
    int caricato=FALSE; // 0
    char nome[LEN_STUDENTE];
    float v; //per le materie
    float somma=0;
    int contI=0;

    if(pos < MAX_STUDENTI){
        printf("Inserisci nome: ");
        gets(studenti[pos]);
        somma=0; //azzeriamo somma
        contI=0;
        for(int i=0;i<TOT_MATERIE;i++){ //randomizziamo i voti (float) e carichiamo valutazioni
            v=floatRand(2, 10);
            valutazioni[pos][i]=v;
            somma+=v;
            if(v<6){
                contI++;
            }
        }
        caricato=TRUE;
        medie[pos]=somma/TOT_MATERIE; //calcolo media per studente in posizione pos

        if(contI>3) esito[pos]='B'; //BOCCIATO
        else if(contI>0) esito[pos]='R'; //RIMANDATO
        else esito[pos]='A'; //AMMESSO
    }
    return caricato;
}
void stampaValutazioni(char studenti[MAX_STUDENTI][LEN_STUDENTE],float valutazioni[MAX_STUDENTI][TOT_MATERIE],int pos,float medie[MAX_STUDENTI],char esito[MAX_STUDENTI]){ //"pos" sarebbe "totStudenti"
    int i=0;
    printf("INFO\tTPSIT\tSIS\tITA\tMAT\tAlunno/a\tMedie\tESITO\n"); //intestazione
    for(i=0;i<pos;i++){ //stampa tabella
        printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%s\t\t%.2f\t%c\n",valutazioni[i][0], valutazioni[i][1], valutazioni[i][2],valutazioni[i][3], valutazioni[i][4], studenti[i], medie[i], esito[i]);
    }
}
void ordina(char studenti[MAX_STUDENTI][LEN_STUDENTE],float valutazioni[MAX_STUDENTI][TOT_MATERIE],int pos,float medie[MAX_STUDENTI],char esito[MAX_STUDENTI]){ //"pos" sarebbe "totStudenti"
    int posmin=0;
    char ausS[LEN_STUDENTE];
    float aus=0;
    float ausM=0;
    char ausE;
    int k=0; //variabile ausiliaria
    for(int i=0;i<=pos-2;i++) { //ordinamento per selezione
        posmin=i;
        for(int j=i+1;j<=pos-1;j++){
            if(strcmp(studenti[posmin],studenti[j])>0){ //string compare (come in c#)
                posmin=j;
            }
        }
        if(posmin!=i){ //SWAP
            //swap studenti
            strcpy(ausS, studenti[i]);
            strcpy(studenti[i], studenti[posmin]);
            strcpy(studenti[posmin], ausS);
            //swap valutazioni
            for(k=0;k<TOT_MATERIE;k++) { //costretto a fare un for per incrementare k
                aus=valutazioni[i][k];
                valutazioni[i][k]=valutazioni[posmin][k];
                valutazioni[posmin][k]=aus;
            }
            //swap medie
            ausM=medie[i];
            medie[i]=medie[posmin];
            medie[posmin]=ausM;
            //swap esito
            ausE=esito[i];
            esito[i]=esito[posmin];
            esito[posmin]=ausE;
        }
    }
}

void scrutinio(char studenti[MAX_STUDENTI][LEN_STUDENTE],float valutazioni[MAX_STUDENTI][TOT_MATERIE],int pos,float medie[MAX_STUDENTI],char esito[MAX_STUDENTI]){
    char materie[TOT_MATERIE][12]={"INFORMATICA\0","TPSIT\0","SISTEMI\0","ITALIANO\0","MATEMATICA\0"};
    printf("\n\n\n\n\t\t\t\tSCRUTINIO\n\nSTUDENTE\t ESITO\t \tMATERIE INSUFFICIENTI\n");
    char ris[MAX_STUDENTI];
    for(int i=0;i<pos;i++){
        if(strlen(studenti[i])>=9) printf("\n%s    ",studenti[i]);
        else if(strlen(studenti[i])<=6) printf("\n%s\t    ",studenti[i]);
        else printf("\n%s\t",studenti[i]);
        if(esito[i]=='B') printf("NON AMMESSO\t");
        else if(esito[i]=='R') printf("\tRIMANDATO\t");
        else printf("AMMESSO\t");
        for(int j=0;j<TOT_MATERIE;j++){
            if(valutazioni[i][j]<6)
                printf("%s | ",materie[j]);
        }
    }
}

void nuoveValutazioni(float valutazioni[MAX_STUDENTI][TOT_MATERIE],float medie[MAX_STUDENTI],char esito[MAX_STUDENTI], int pos){
    int contI=0; //conta insufficienze
    int somma=0;
    float v;
    for(int i=0;i<pos;i++){
        somma=0; //azzeriamo somma
        contI=0;
        for(int j=0;j<TOT_MATERIE;j++){ //randomizziamo i voti (float) e carichiamo valutazioni
            v=floatRand(2, 10);
            valutazioni[i][j]=v;
            somma+=v;
            if(v<6){
                contI++;
            }
        }
        medie[i]=somma/TOT_MATERIE; //calcolo media per studente in posizione pos

        if(contI>3) esito[pos]='B'; //BOCCIATO
        else if(contI>0) esito[pos]='R'; //RIMANDATO
        else esito[pos]='A'; //AMMESSO
    }
}

void stampaScrutinio(char file_name[],char studenti[MAX_STUDENTI][LEN_STUDENTE],float valutazioni[MAX_STUDENTI][TOT_MATERIE],float medie[MAX_STUDENTI],char esito[MAX_STUDENTI], int pos){
    FILE* fp; //File Pointer (puntatore del file); contiene un indirizzo
    // "r" --> READ
    // "w" --> WRITE (se il file esiste vengono cancellati tutti i dati e se ne scrivono altri)
    // "a" --> APPEND (scrittura senza sovrascrittura dei dati precedenti)
    // "rb", "wb", "ab" ... ---> per aprire file BINARI
    fp = fopen(file_name,"w"); //bisogna passare obbligatoriamente il nome del file e la modalità di accesso ("r","w","a")

    if(fp!=NULL){ //se fopen NON è andata a buon file restituisce NULL
            fprintf(fp,"INFO\tTPSIT\tSIS\tITA\tMAT\tAlunno/a\tMedie\tESITO\n");
            // EXCEL fprintf(fp,"INFO;TPSIT;SIS;ITA;MAT;Alunno/a;Medie;ESITO;");
            for(int i=0;i<pos;i++){
                fprintf(fp,"%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%s\t\t%.2f\t%c\n",valutazioni[i][0], valutazioni[i][1], valutazioni[i][2],valutazioni[i][3], valutazioni[i][4], studenti[i], medie[i], esito[i]); //per scrivere nel file, passiamo il puntatore e poi si scrive come se fossimo in una printf normale
                //EXCEL CON ESTENSIONE .csv fprintf(fp,"%.2f;%.2f;%.2f;%.2f;%.2f;%s;%.2f;%c;",valutazioni[i][0], valutazioni[i][1], valutazioni[i][2],valutazioni[i][3], valutazioni[i][4], studenti[i], medie[i], esito[i]); //per scrivere nel file, passiamo il puntatore e poi si scrive come se fossimo in una printf normale
            }
    }else printf("Impossibile aprire il file");

    fclose(fp); //chiusura del file
}

int leggiFile(char file_name[],char studenti[MAX_STUDENTI][LEN_STUDENTE], float valutazioni[MAX_STUDENTI][TOT_MATERIE], float medie[MAX_STUDENTI], char esito[MAX_STUDENTI], int pos){
    FILE* fp;

    char cogn[LEN_STUDENTE];

    fp=fopen(file_name,"r");

    if(fp!=NULL){
        while(!feof(fp)){ //End Of File, cicliamo fino a quando non ci restituisce TRUE
            fscanf(fp,"%s",cogn);
            printf("%s\n",cogn);
            //strcpy(cogn,studenti[pos]);
            valutazioniFile(studenti,valutazioni,esito,medie,pos);
            pos++;
        }
    }else printf("Impossibile aprire file\n");
    fclose(fp);
    return pos;
}
void valutazioniFile(char studenti[MAX_STUDENTI][LEN_STUDENTE], float valutazioni[MAX_STUDENTI][TOT_MATERIE], char esito[MAX_STUDENTI], float medie[MAX_STUDENTI], int pos){
    int contI=0;
    float v=0;
    float somma=0;

    FILE* studente;
    studente=fopen("studenti.txt","a");

    if(pos < MAX_STUDENTI){
        contI=0;
        somma=0;
        /*do{
            fscanf(studente,"%s",studenti[pos]);
        }while(studenti[pos]!='\n');
        printf("%s\n",studenti[pos]);*/

        for(int i=0;i<TOT_MATERIE;i++){
            v=floatRand(2, 10);
            valutazioni[pos][i]=v;
            somma+=v;
            if(v<6){
                contI++;
            }
        }

        medie[pos]=somma/TOT_MATERIE;

        if(contI>3) esito[pos]='B'; //BOCCIATO
        else if(contI>0) esito[pos]='R'; //RIMANDATO
        else esito[pos]='A'; //AMMESSO
    }
}
#endif // SCRUTINIO_H_INCLUDED
