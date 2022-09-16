#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utility.h"
#include "piloti.h"
#include "team.h"

#define MAX_DATI 50

int menu();

int main()
{
    int scelta;
    int len_pil=0,len_team=0;
    Piloti pil[MAX_DATI];
    Team tm[MAX_DATI];
    len_pil=caricaPiloti("File/piloti.csv",pil);
    len_team=caricaTeam("File/team.csv",tm);
    do{
        scelta=menu();
        fflush(stdin);
        system("@cls||clear");
        switch(scelta){
            case 1:
                elencoPiloti(pil, len_pil, tm, len_team);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta!=0);
    return 0;
}

int menu(){
    int sc;
    printf("1.\n");
    printf("2.\n");
    printf("3.\n");
    printf("4.\n");
    printf("Scelta-> ");
    scanf("%d",&sc);
    return sc;
}
