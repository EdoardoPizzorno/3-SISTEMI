#include <stdio.h>
#include <stdlib.h>
#define MAX 100+1
#define TRUE 1
#define FALSE 0

void es1(char s[]);
int es3(char s[],int v[]);

void lower(char s[]);

int main()
{
    char s[MAX];
    printf("Inserisci stringa: ");
    gets(s);
    //es1
    es1(s);
    //es2 - es3
    int max=10;
    int v[max];
    srand(time(NULL));
    for(int i=0;i<max;i++){
        v[i]=(rand()%max)+1;
    }
    printf("\nVettore numerico: ");
    for(int i=0;i<max;i++){
        printf("%d ",v[i]);
    }
    es3(s,v);
    return 0;
}
void lower(char s[]){
    for(int i=0;i<Len(s);i++){
        if(s[i]>96 && s[i]<123)
            s[i]-=32;
    }
}
int Len(char s[]){
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
void es1(char s[]){
    char num[MAX];
    char other[MAX];
    char car[MAX];
    int k=0;//indice per i numeri
    int j=0;//indice per gli altri caratteri
    int c=0;//indice per i caratteri dell'alfabeto
    for(int i=0;i<Len(s);i++){
        if(s[i]>64 && s[i]<91 || s[i]>96 && s[i]<123){
            car[c++]=s[i];
        }else if(s[i]>47 && s[i]<58){
            num[k++]=s[i];
        }else other[j++]=s[i];
    }
    other[j]='\0';
    num[k]='\0';
    car[c]='\0';
    printf("Caratteri: %s\nOther: %s\nNum: %s",car,other,num);
}
int es3(char s[],int v[]){
    int somN=0,k=0,maxL=0; //k è indice di s2
    for(int i=0;i<v[i];i++){
        somN+=v[i];
    }
    int len1=Len(s);
    char s2[somN+len1+1];
    if(Len(s2)>10)
        maxL=10;
    else maxL=Len(s);
    for(int i=0;i<maxL;i++){
        for(int j=0;j<v[i];j++)
            s2[k++]=s[i];
    }
    printf("\nStringa modificata: %s",s2);
}
