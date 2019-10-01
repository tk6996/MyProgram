#include<stdio.h>
int main()
{
    int i,j=1,k;
    for(k=1;k<=12*12;k++)
    {
        if(k%12==0) i=k/12;
        else i=k/12+1;
        printf("%-6d",i*j);
        if(j<12) { j++;}
        else {j=1; printf("\n");}
    }
    return 0;
}