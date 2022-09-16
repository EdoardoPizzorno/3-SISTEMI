#include "scrutinio.h" ///scrutinio.h viene compilato prima del main.c

int menu();

int main()
{
    int scelta=0;
    char studenti[MAX_STUDENTI][LEN_STUDENTE]; //dichiarati in scrutinio.h
    float valutazioni[MAX_STUDENTI][TOT_MATERIE];
    int totStudenti=0; //variabile ausiliaria per memorizzare i nomi degli studenti e non deve superare
    int stampato=FALSE;
    float medie[MAX_STUDENTI];
    char esito[MAX_STUDENTI]; //A--> ammesso R--> rimandato(debito) N--> non ammesso
    do{
        scelta=menu();
        fflush(stdin); //pulizia buffer
        switch(scelta){
        case 0:
            break;
        case 1: //nuovo studente
            if(nuovoStudente(studenti,valutazioni,totStudenti,medie,esito)== TRUE){
                totStudenti++;
                printf("Studente caricato\n");
            }
            else printf("Numero massimo di studenti caricato, IMPOSSIBILE PROCEDERE");
            break;
        case 2: //stampa elenco studenti
            if(totStudenti>0){
                stampaValutazioni(studenti,valutazioni,totStudenti,medie,esito); //se ci sono studenti caricati, allora stampiamo, altrimenti informiamo l'utente che non ci sono studenti
            }else printf("Nessuno studente caricato");
            break;
        case 3: //nome studente + dicitura ESITO + nInsufficienze
            if(totStudenti>0){
                stampaValutazioni(studenti,valutazioni,totStudenti,medie,esito); //per confrontare con lo scrutinio
                scrutinio(studenti,valutazioni,totStudenti,medie,esito);
            }else printf("Nessuno studente caricato");
            break;
        case 4:
            if(totStudenti>0){
                printf("Nuove valutazioni caricate");
                nuoveValutazioni(valutazioni,medie,esito,totStudenti);
                stampaValutazioni(studenti,valutazioni,totStudenti,medie,esito);
                //scrutinio(studenti,valutazioni,totStudenti,medie,esito); da guardare perchè non funziona se vengono generate nuove valutazioni
            }else printf("Nessuno studente caricato");
            break;
        case 5: //ordinamento studenti
            if(totStudenti>0){
                ordina(studenti,valutazioni,totStudenti,medie,esito);
                stampaValutazioni(studenti,valutazioni,totStudenti,medie,esito);
            }
            break;
        case 6:
            if(totStudenti>0){
                stampaScrutinio("scrutinio.txt",studenti,valutazioni,medie,esito,totStudenti); //scrutinio.csv per EXCEL
                stampato=TRUE;
                printf("Stampa terminata");
            }else printf("Nessuno studente caricato");
            break;
        case 7:
            if(stampato==TRUE){
                totStudenti=leggiFile("scrutinio.txt",studenti,valutazioni,medie,esito,totStudenti);
                printf("\n\nStampa terminata");
            }else printf("Devi stampare sul file");
        }
        fflush(stdin); //pulizia buffer
        getchar();
        system("@cls||clear"); //pulizia schermo
    }while(scelta!=0);
    printf("Programma terminato...");
    return 0;
}
int menu(){
    int sc=0;
    printf("MENU\n");
    printf("0. ESCI\n");
    printf("1. Aggiungi studente\n");
    printf("2. Stampa elenco studenti\n");
    printf("3. Calcola e visualizza scrutinio\n");
    printf("4. Genera nuove valutazioni\n");
    printf("5. Ordina per studente\n");
    printf("6. Stampa su FILE\n");
    printf("7. Leggi da FILE\n");

    printf("Scelta --> ");
    scanf("%d",&sc); //& perchè abbiamo una variabile di tipo intero e non dobbiamo trasmettere l'indirizzo della variabile
    return sc;
}



