#ifndef GRANPREMI_H_INCLUDED
#define GRANPREMI_H_INCLUDED
#include "string.h"

#define LEN_GP 30
#define MAX_PIL_GARA 15

typedef int bool;

typedef struct granpremio{
    int idGP;
    char nome[LEN_GP];
    int lung;
    int nGiri;
} Granpremi;

int punteggi[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int caricaGranPremiDaFile(char file_name[], Granpremi gp[]){
    int cnt = 0;
    FILE* fp;
    char row_file[BUFFER];
    char spl[BUFFER];

    fp = fopen(file_name, "r");

    if (fp != NULL){
        while(!feof(fp)){
            fgets(row_file, BUFFER, fp);
            //printf("%s\n", row_file);
            /// idGP
            splittaString(row_file, spl, 0, ';');
            gp[cnt].idGP = atoi(spl);
            /// nome
            splittaString(row_file, spl, 1, ';');
            strcpy(gp[cnt].nome, spl);
            /// lung
            splittaString(row_file, spl, 2, ';');
            gp[cnt].lung = atoi(spl);
            /// nGiri
            splittaString(row_file, spl, 3, ';');
            gp[cnt].nGiri = atoi(spl);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file\n");
    fclose(fp);

    return cnt;
}
void elencoGP(Granpremi gp[], int len)
{
    int i;
    printf("STAMPA ELENCO GRAN PREMI\n");
    printf("ID\tLUNG\tGIRI\tNOME\n");

    for(i=0; i<len; i++){
        printf("%d\t%d\t%d\t%s\n",
               gp[i].idGP, gp[i].lung, gp[i].nGiri, gp[i].nome);
    }
}
void generaGPSingolo(Piloti pil[], int len_pil, Scuderie sc[], int len_sc, Granpremi gp[], int len_gp)
{
    int idGP, idPil;
    int vPil[MAX_PIL_GARA] = {0}; // Azzero array
    int i, j;
    bool trovato;
    srand(time(NULL));

    /// 1. Ricerca e stampa GP
    idGP = rand() % len_gp;
    printf("VIA AL %s\n", gp[idGP].nome);
    /// 2. Solo MAX_PIL_GARA possono partecipare
    for(i=0; i<MAX_PIL_GARA; i++){
        do{
            idPil = rand() % len_pil;
            trovato = FALSE;
            j = 0;
            // Inizio ricerca idPil in vPil
            while(j < MAX_PIL_GARA && vPil[j] != idPil)
                j++;

            if(j<MAX_PIL_GARA)
                trovato = TRUE;
            else
            { // Pilota NON TROVATO
                vPil[i] = idPil;
                /// punteggi[] => {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
                pil[idPil].totGare++;
                if (i < 10)
                {
                    pil[idPil].punti += punteggi[i]; /****************/
                    /*
                    int pos = getPosScudByID(pil[idPil].codScuderia, sc, len_sc);
                    sc[pos].totPunti += punteggi[i];
                    */
                    sc[getPosScudByID(pil[idPil].codScuderia, sc, len_sc)].totPunti += punteggi[i]; /***********/
                }
                printf("%d - %s - %d\n", (i+1), pil[idPil].nome, pil[idPil].punti);
            }

        }while(trovato == TRUE);
    }
}
#endif // GRANPREMI_H_INCLUDED
