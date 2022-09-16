#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

void caricaVet(int v[],int b[], int n);
void stampaVet(int v[], int n, char nome);

int main()
{
    // C# int[] v
    int a[MAX], b[MAX];
    int n;
    float c[MAX];
    printf("Quanti valori vuoi inserire? (MAX 10)");
    scanf("%d",&n);
    caricaVet(a,b,n);
    printf("Stampa del vettore A\n");
    stampaVet(a,n,'a');
    printf("Stampa del vettore B\n");
    stampaVet(b,n,'b');
    return 0;
}
void caricaVet(int a[],int b[],int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        /*printf("Inserisci valore in pos %d: ",i);
        scanf("%d",&v[i]); */
        a[i]=(rand()%10)+1;
        b[i]=sqrt(a[i]);
    }
}
void stampaVet(int v[], int n, char nome){
    for(int i=0;i<n;i++)
        printf("Elemento in posizione %i: %d\n",i,v[i]);
}
