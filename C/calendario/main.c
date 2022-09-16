// Stampa in forma tabellare il calendario di un mese
// dell'anno 2022
//
//       GEN 2022
// LU MA ME GI VE SA DO
//                 1  2
//  3  4

#include <stdio.h>
#include <stdlib.h>

int main()
 {
  int inpMese,totGiorni,i,gSett,day,inpGiorno;
  int gMese[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  char mesi[12][4] = {"GEN","FEB","MAR","APR","MAG","GIU","LUG","AGO","SET","OTT","NOV","DIC"};
  char settimana[7][3] = {"LU","MA","ME","GI","VE","SA","DO"};


  //input del mese - PRIMO ESERCIZIO
  system("color c");
  printf("PRIMO ESERCIZIO\n\n");
  do
   {
    printf("Mese (1-->GEN, 2-->FEB ...): ");
    scanf("%d",&inpMese);
    if((inpMese<1)||(inpMese>12))
      printf("Il mese deve essere compreso tra 1 e 12\n");
   }while((inpMese<1)||(inpMese>12));
   inpMese--; // inpMese diventa l'indice del vettore mesi

   // giorni settimana: 0-LU 1-MA 2-ME ...
   totGiorni=5;  // il 1o gennaio 2022 è sabato
   // calcolo dei giorni passati dall'inizio dell'anno
   for(i=0;i<inpMese;i++)
     totGiorni+=gMese[i];
   gSett=totGiorni%7;   // giorno della settimana del primo del mese
   printf("Il primo di %s cade di %s\n\n",mesi[inpMese],settimana[gSett]);
   //tabella
   printf("      %s 2022\n",mesi[inpMese]);
   for(i=0;i<7;i++)
     printf("%s ",settimana[i]);
   printf("\n");
   for(i=0;i<gSett;i++)
     printf("   ");
   for(day=1;day<=gMese[inpMese];day++){
        if(((gSett-1)+day)%7==0)
            printf("\n");
        if(day<=9)
            printf(" %i ",day);
        else
            printf("%i ",day);
    }
    printf("\n");
    system("pause");
    system("cls");


    //esercizio 2
    system("color 9");
    printf("SECONDO ESERCIZIO\n\n");
    for(int k=0;k<12;k++)
    {
        totGiorni=5;
        for(i=0;i<k;i++)
            totGiorni+=gMese[i];
        gSett=totGiorni%7;
        printf("      %s 2022\n",mesi[k]);
        for(i=0;i<7;i++)
            printf("%s ",settimana[i]);
        printf("\n");
        for(i=0;i<gSett;i++)
            printf("   ");
        for(day=1;day<=gMese[k];day++)
        {
            if(gSett%7==0)
                printf("\n");
            gSett++;
            printf("%2d ",day);
        }
        printf("\n\n");
    }
    printf("\n");
    system("pause");
    system("cls");


    //esercizio 3
    system("color 6");
    printf("TERZO ESERCIZIO\n\n");
    do
    {
        do{
        printf("Mese: (1-->GEN, 2-->FEB ..): ");
        scanf("%d",&inpMese);
        if((inpMese<1)||(inpMese>12))
            printf("Il mese deve essere compreso tra 1 e 12\n");
        }while((inpMese<1) || (inpMese>12));
        do{
            printf("Inserisci un giorno: ");
            scanf("%d",&inpGiorno);
        if((inpGiorno<1)||(inpGiorno>31))
            printf("Il giorno deve essere compreso tra 1 e 31\n");
        }while((inpGiorno<1) || (inpGiorno>31));
        inpMese--;
    }while(inpGiorno>gMese[inpMese]);

    totGiorni=5;
    for(i=0;i<inpMese;i++)
        totGiorni+=gMese[i];
    totGiorni+=inpGiorno-1;
    printf("%d settimana",totGiorni/7);
    gSett=totGiorni%7;
    printf("\ngiorno %s",settimana[gSett]);


  return 0;
 }
