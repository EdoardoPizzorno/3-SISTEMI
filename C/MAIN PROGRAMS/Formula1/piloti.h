#ifndef PILOTI_H_INCLUDED
#define PILOTI_H_INCLUDED
#define LEN_NOME 20
#define BUFFER 100

#define TRUE 1
#define FALSE 0


typedef int bool;

typedef struct pilota{
    int idPilota;
    char nome[LEN_NOME];
    int codScuderia;
    int totGare;
    int punti;
} Piloti;



 int caricaPilotiDaFile(char file_name[], Piloti p[]){
    FILE* fp;
    char row_file[BUFFER];
    char spl[BUFFER];
    int cnt = 0;

    fp = fopen(file_name, "r");
    if (fp != NULL)
    {
        while(!feof(fp))
        {
            //fscanf(fp, "%s", row_file);
            fgets(row_file, BUFFER, fp);
            //printf("%s\n", row_file);
            /* row_file => 1;Hammilton L.;1;0;0 */

            /// idPilota
            splittaString(row_file, spl, 0, ';');
            p[cnt].idPilota = atoi(spl);
            /// Nome
            splittaString(row_file, spl, 1, ';');
            strcpy(p[cnt].nome, spl);
            /// codScuderia
            splittaString(row_file, spl, 2, ';');
            p[cnt].codScuderia = atoi(spl);
            /// totGare
            splittaString(row_file, spl, 3, ';');
            p[cnt].totGare = atoi(spl);
            /// totPunti
            splittaString(row_file, spl, 4, ';');
            p[cnt].punti = atoi(spl);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file...\n");

    fclose(fp);
    return cnt;
 }

 void elencoPiloti(Piloti p[], int len_p, Scuderie sc[], int len_sc)
 {
    int i;
    char scud[BUFFER];
    printf("STAMPA ELENCO PILOTI\n");
    printf("ID\tGARE\tPUNTI\tNOME\t\t\tSCUDERIA\n");
    for(i=0; i<len_p; i++){
        getNomeScudByID(sc, len_sc, p[i].codScuderia, scud);
        printf("%d\t%d\t%d\t%s\t\t\t%s\n",
               p[i].idPilota, p[i].totGare, p[i].punti,
               p[i].nome, scud);
    }
 }
 void ordinaPilotiPerPunti(Piloti p[], int len_p)
 {
    /// APPLICO ALGORITMO DI ORDINAMENTO PER SELEZIONE
    int i, j, posmin;
    Piloti ausPil;

    for(i=0; i<=len_p-2; i++)
    {
        posmin = i;
        for(j = i+1; j<=len_p-1; j++)
        {
            if (p[posmin].punti < p[j].punti)
                posmin = j;
        }
        if(posmin != i)
        {
            /// SWAP PILOTA
            ausPil = p[i];
            p[i] = p[posmin];
            p[posmin] = ausPil;
        }
    }
 }
 void classificaPiloti(Piloti p[], int len_p, Scuderie sc[], int len_sc)
 {
    /// ID - GARE - PUNTI - NOME - SCUDERIA

    printf("STAMPA CLASSIFICA PILOTI\n");
    ordinaPilotiPerPunti(p, len_p);
    elencoPiloti(p, len_p, sc, len_sc);

 }
void stampaPilotiSuFile(Piloti p[], int len_p)
{
    FILE* fp;
    int i;

    fp = fopen("File/stampa_piloti.csv", "w");

    fprintf(fp, "CLASSIFICA PILOTI\n");
    for(i=0; i<len_p; i++)
        fprintf(fp, "%d;%s;%d;%d\n", p[i].idPilota, p[i].nome, p[i].totGare, p[i].punti);

    fclose(fp);
    printf("Stampa su file terminata\n");

    system("stampa_piloti.csv");
}
#endif // PILOTI_H_INCLUDED
