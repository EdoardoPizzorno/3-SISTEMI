#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATI 50
#define BUFFER 100
#define LEN_NOME 30
#define TRUE 1
#define FALSE 0

#include "utility.h"
#include "team.h"
#include "piloti.h"

int menu();

int main()
{
    Piloti p[DATI];
    Team t[DATI];

    int len_pil=0;
    int len_team=0;

    len_pil=caricaPiloti("File/piloti.csv", p);
    len_team=caricaTeam("File/team.csv", t);

    char nazioneInput[BUFFER];
    int number=0;

    int scelta=0;
    do{
        scelta = menu();
        fflush(stdin);
        system("@cls||clear");
        switch(scelta){
        case 0:
            break;
        case 1:
            es1(len_pil, len_team, t, p);
            break;
        case 2:
            printf("Inserisci la nazione dei piloti da cercare: ");
            gets(nazioneInput);
            es2(nazioneInput, len_pil, p);
            break;
        case 3:
            printf("Inserisci numero: ");
            scanf("%d",&number);
            es3(number,len_pil, p, len_team, t);
            break;
        case 4:
            es4("File/migliore.txt",p, t, len_team, len_pil);
            printf("File salvato");
            break;
        }

        fflush(stdin);
        getchar();
        system("@cls||clear");
    }
    while(scelta != 0);
    printf("Programma terminato");
    return 0;
}
int menu(){
    int sc;

    printf("0. ESCI\n");
    printf("1. Visualizzare piloti con team\n");
    printf("2. Visualizzare piloti data nazione\n");
    printf("3. Dato numero in input, visualizzare tutti i piloti il cui punteggio è superiore\n");
    printf("4. Miglior pilota in migliore.txt\n");

    printf("Scelta--> ");
    scanf("%d",&sc);
    return sc;
}
