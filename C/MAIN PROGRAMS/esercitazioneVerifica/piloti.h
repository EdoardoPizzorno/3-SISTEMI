#ifndef PILOTI_H_INCLUDED
#define PILOTI_H_INCLUDED

#include <string.h>
#include "team.h"

#define MAX_DATI 30
#define BUFFER 100

typedef struct piloti{
    int id;
    char nome[MAX_DATI];
    char nazione[3];
    int punti;
    int codTeam;
} Piloti;

int caricaPiloti(char file_name[], Piloti pil[]){
    int cnt=0;
    FILE* fp;
    char row_file[BUFFER];
    char ret[BUFFER];
    fp=fopen(file_name, "r");


    if(fp!=NULL){
        while(!feof(fp)){
            fgets(row_file, BUFFER, fp);

            splittaString(row_file,ret,0,';');
            pil[cnt].id=atoi(ret);

            splittaString(row_file,ret,1,';');
            strcpy(pil[cnt].nome, ret);

            splittaString(row_file,ret,2,';');
            strcpy(pil[cnt].nazione, ret);

            splittaString(row_file, ret, 3, ';');
            pil[cnt].punti=atoi(ret);

            splittaString(row_file, ret, 4, ';');
            pil[cnt].codTeam=atoi(ret);

            cnt++;
        }
    }
    return cnt;
}

void elencoPiloti(Piloti pil[],int len_pil, Team tm[],int len_team){
    char nomeTeam[MAX_DATI];
    printf("ID\tNAZIONE\t\tNOME\tPUNTI\tTEAM\n");
    for(int i=0;i<len_pil;i++){
        cercaNomeTeam(pil[i].codTeam,tm,len_team,nomeTeam);
        printf("%d\t%s\t%s\t%d\t%s\n",pil[i].id, pil[i].nome, pil[i].nazione, pil[i].punti,nomeTeam);
    }
}

#endif // PILOTI_H_INCLUDED
