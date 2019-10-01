#include<stdio.h>
int main()
{
    int m,n;
    char d;
    float f;
    m=0;n=0;
    do{
    n=n+1;
    printf("Data %d. = ",n);
    scanf("%s",d);
    m=m+1;
    f=d;
    }while(f>=0||f<0);
}
