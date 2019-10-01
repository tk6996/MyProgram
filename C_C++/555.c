#include <stdio.h>
int main ()
{
    int a,i,j,x;
    scanf ("%d",&a);
    for (i=1;i<=a;i++){
        for (j=1;j<=a;j++){
            x=i+j;
            if (x%2==0){
                printf("*");
            }
            else {printf("_");}
        }
        printf ("\n");
    }
    return 0;
}