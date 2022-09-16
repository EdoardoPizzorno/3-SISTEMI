#ifndef SCUDERIE_H_INCLUDED
#define SCUDERIE_H_INCLUDED

#define LEN_SCUDERIA 30
#define LEN_MONOPOSTO 20
#define BUFFER 100

typedef struct scuderia{
    int idScuderia;
    char nome[LEN_SCUDERIA];
    char monoposto[LEN_MONOPOSTO];
    float rating;
    int totPunti;
} Scuderie;


int caricaScuderieDaFile(char file_name[], Scuderie sc[]){
    int cnt = 0;
    FILE* fp;
    char row_file[BUFFER];
    char spl[BUFFER];

    fp = fopen(file_name, "r");

    if (fp != NULL){
        while(!feof(fp)){
            fgets(row_file, BUFFER, fp);
            //printf("%s\n", row_file);
            /// idScuderia
            splittaString(row_file, spl, 0, ';');
            sc[cnt].idScuderia = atoi(spl);
            /// Nome
            splittaString(row_file, spl, 1, ';');
            strcpy(sc[cnt].nome, spl);
            /// Monoposto
            splittaString(row_file, spl, 2, ';');
            strcpy(sc[cnt].monoposto, spl);
            /// Rating
            splittaString(row_file, spl, 3, ';');
            sc[cnt].rating = atof(spl);
            /// Punti
            splittaString(row_file, spl, 4, ';');
            sc[cnt].totPunti = atoi(spl);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file\n");
    fclose(fp);

    return cnt;
}

void elencoScuderie(Scuderie sc[], int len)
{
    int i;
    printf("STAMPA ELENCO SCUDERIE\n");
    printf("ID\tRATING\tPUNTI\tMONOPOSTO\t\tSCUDERIA\n");

    for(i=0; i<len; i++){
        printf("%d\t%.2f\t%d\t%s\t\t%s\n",
               sc[i].idScuderia, sc[i].rating, sc[i].totPunti,
               sc[i].monoposto, sc[i].nome);
    }
}
void getNomeScudByID(Scuderie sc[], int len_sc, int codScud, char ret[])
{
    int i = 0;
    while(i < len_sc && sc[i].idScuderia != codScud)
        i++;

    if (i < len_sc)
        strcpy(ret, sc[i].nome);
    else
        strcpy(ret, "Non trovato");
}

int getPosScudByID(int codScudPil, Scuderie sc[], int len_sc)
{
    int i=0;
    while(i<len_sc && codScudPil != sc[i].idScuderia)
        i++;

    return i;
}

#endif // SCUDERIE_H_INCLUDED
