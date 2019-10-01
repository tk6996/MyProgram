#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    unsigned char cor = 1;
    int n;
    scanf("%d",&n);
    int **table = malloc(sizeof(*table)*n);
    unsigned char *called = calloc(sizeof(called),n*n);
    for (int i = 0; i < n; i++)
    {
        table[i] = malloc(sizeof(table)*n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d",table[i]+j);
            if(called[table[i][j]-1]) cor=0;
            else called[table[i][j]-1] = 1;
        }
    }
    int sum=0,temp=0;
    for (int k = 0; k < n; k++)
    {
        sum += table[k][k];
        temp+= table[k][n-k-1];
    }
    if(sum != temp) cor=0;
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp+=table[i][j];
        }
        if(sum != temp) cor=0;
    }
    if(cor) puts("Yes"); else puts("No");
    return 0;
}