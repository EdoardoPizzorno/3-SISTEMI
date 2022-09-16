#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,x=0,cont1=1,cont2=0;

    printf("GIOCO 1vs1 INDOVINA IL NUMERO\n");
    for(int i=1;i<=2;i++)
    {
        if(i==1)
            printf("GIOCATORE 1, inserisci il numero segreto: ",i);
        else
            printf("\nGIOCATORE 2, indovina il numero: ",i);
        scanf("%i",&n);
        if(i==1)
            printf("\nGIOCATORE 2, devi indovinare il numnero segreto\n");
        else
            printf("\nGIOCATORE 1, devi indovinare il numero segreto\n");
        do
        {
            printf("Tentativo numero %i: ",cont1);
            scanf("%i",&x);
            if(x==n)
                printf("Hai indovinato con %i tentativi \n",cont1);
            else
            {
                cont1++;
                if(x>n)
                    printf("Valore troppo alto\n");
                else
                    printf("Valore troppo basso\n");
            }
        }
        while(x!=n);
        if(i==1)
            cont2=cont1;
    }
    printf("GIOCATORE 1 --> %i tentativi\nGIOCATORE 2 --> %i tentativi\n",cont1,cont2);
    if(cont1==cont2)
        printf("\nPAREGGIO!\n");
    else
    {
        if(cont2>cont1)
            printf("\nGIOCATORE 1 HA VINTO!!!\n");
        else
            printf("\nGIOCATORE 2 HA VINTO!!!\n");
    }
    return 0;
}
