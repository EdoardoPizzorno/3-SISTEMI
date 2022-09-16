#ifndef PILOTI_H_INCLUDED
#define PILOTI_H_INCLUDED
#define LEN_NAZIONALITA 3

typedef struct pilota{
    int idPilota;
    char nomePilota[LEN_NOME];
    char nazione[LEN_NAZIONALITA];
    int punti;
    int codTeam;
}Piloti;

int caricaPiloti(char nf[], Piloti p[]){
    FILE *fp;

    fp=fopen(nf,"r");

    char row_file[BUFFER];
    char sp1[BUFFER];

    int i=0;

    if(fp!=NULL){
        while(!feof(fp)){
            fgets(row_file,BUFFER,fp);

            splittaString(row_file,sp1,0,';');
            p[i].idPilota=atoi(sp1);

            splittaString(row_file,sp1,1,';');
            strcpy(p[i].nomePilota ,sp1);

            splittaString(row_file,sp1,2,';');
            strcpy(p[i].nazione,sp1);

            splittaString(row_file,sp1,3,';');
            p[i].punti=atoi(sp1);

            splittaString(row_file,sp1,4,';');
            p[i].codTeam=atoi(sp1);

            i++;
        }
    }

    fclose(fp);

    return i;
}
void es1(int len_pil, int len_team, Piloti p[], Team t[]){
    printf("ID\tPUNTI\tCOD_TEAM\tNAZIONE\tNOME PIL\tNOME TEAM\n");

    char team[BUFFER];

    for(int i=0;i<len_pil-1;i++){
        getNomeTeam(len_team, t, p[i].codTeam, team);
        printf("%d\t%s\t%s\t%d\t%s\n",p[i].idPilota, p[i].nomePilota, p[i].nazione, p[i].punti, team);
    }
}
void es2(char nazioneInput[], int len, Piloti p[]){
    int trovato=FALSE;
    for(int i=0;i<len-1;i++){
        if(strcmp(p[i].nazione,nazioneInput)==0){
            trovato=TRUE;
            printf("%s\n",p[i].nomePilota);
        }
    }
    if(trovato==FALSE)
        printf("Nessuna nazione trovata con %s\n",nazioneInput);
}

void es3(int number, int len_pil, Piloti p[], int len_team, Team t[]){
    ordinaPilotiPUNTI(p,len_pil);
    FILE* fp;
    fp=fopen("File/esercizio_3.txt","w");

    int superato=FALSE;
    int ids[len_pil];
    int j=0;
    int i=0;

    while(superato==0 && i!=len_pil){
        if(p[i].punti<number){
            ids[j++]=p[i].idPilota;
            i++;
        }
        else{
            if(p[i].punti>number){
                superato=TRUE;
            }else i++;
        }
    }
    cercaPiloti(ids, t, p, j, len_team);
    fclose(fp);
}
void cercaPiloti(int ids[], Team t[], Piloti p[], int j, int len_team, int len_pil){
    char team[BUFFER];
    for(int i=0;i<j;i++){
        if(ids[i]==p[i].idPilota){
            getNomeTeam(len_team,t,p[i].codTeam,team);
            printf("%d\t%s\t%s\t%s\t%d", p[i].idPilota, p[i].nomePilota, team , p[i].nazione, p[i].punti);
        }
    }
}
void ordinaPilotiPUNTI(Piloti p[],int len){
    int posmin=0;
    for(int i=0;i<=len-2;i++)
    {
        posmin=i;
        for(int j=i+1;j<=len-1;j++)
            if(p[posmin].punti<p[j].punti)
                posmin=j;
        if(posmin!=i)
        {
            Piloti aus=p[i];
            p[i]=p[posmin];
            p[posmin]=aus;
        }
    }
}
void es4(char nf[], Piloti p[], Team t[], int len_team, int len_pil){
    ordinaPilotiPUNTI(p,len_pil);
    FILE* fp;
    fp=fopen(nf,"w");

    char team[BUFFER];

    getNomeTeam(len_team, t, p[0].codTeam, team);
    fprintf(fp,"%d;%s;%s;%s;%d", p[0].idPilota, p[0].nomePilota, team , p[0].nazione, p[0].punti);

    fclose(fp);
}
#endif // PILOTI_H_INCLUDED
