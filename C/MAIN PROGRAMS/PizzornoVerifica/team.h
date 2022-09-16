#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

typedef struct team{
    int idTeam;
    char nomeTeam[LEN_NOME];
    char motore[BUFFER];
}Team;

int caricaTeam(char nf[], Team t[]){
    FILE *fp;
    fp=fopen(nf,"r");

    char row_file[BUFFER];
    char sp1[BUFFER];

    int i=0;

    if(fp!=NULL){
        while(!feof(fp)){
            fgets(row_file,BUFFER,fp);

            splittaString(row_file,sp1,0,';');
            t[i].idTeam=atoi(sp1);

            splittaString(row_file,sp1,1,';');
            strcpy(t[i].nomeTeam,sp1);

            splittaString(row_file,sp1,2,';');
            strcpy(t[i].motore,sp1);

            i++;
        }
    }
    fclose(fp);

    return i;
}

void getNomeTeam(int len_team, Team t[], int codTeam, char team[]){
    for(int i=0;i<len_team; i++){
        if(t[i].idTeam==codTeam){
            strcpy(team,t[i].nomeTeam);
        }
    }
}

#endif // TEAM_H_INCLUDED
