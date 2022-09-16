#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#define MAX 30
#define BUFFER 100

typedef struct team{
    int id;
    char nome[MAX];
    char motore[MAX];
} Team;

int caricaTeam(char file_name[], Team tm[]){
    FILE* fp;
    int cnt=0;
    char row_file[BUFFER];
    char ret[BUFFER];

    fp=fopen(file_name, "r");
    if(fp!=NULL){
        while(!feof(fp)){
            fgets(row_file, BUFFER, fp);
            splittaString(row_file,ret, 0,';');
            tm[cnt].id=atoi(ret);
            splittaString(row_file,ret,1,';');
            strcpy(tm[cnt].nome,ret);
            splittaString(row_file,ret, 2,';');
            strcpy(tm[cnt].motore,ret);
            cnt++;
        }
    }
    return cnt;
}
void cercaNomeTeam(int cod, Team tm[],int len_team, char nome[]){
    for(int i=0;i<len_team; i++){
        if(tm[i].id==cod){
            strcpy(nome,tm[i].nome);
        }
    }
}

#endif // TEAM_H_INCLUDED
