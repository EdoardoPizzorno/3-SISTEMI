#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main(void)
{
    int a;
    printf("NUMERI CASUALI\n");
    srand(time(NULL));
    for(int i=0;i<10;i++)
        printf("%d\n", (rand()%10));
    return 0;
}
