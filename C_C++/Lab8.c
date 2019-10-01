#include<stdio.h>
#include<string.h>
int main()
{
    char STRING[100];
    int i,j=0,k=0;
    struct c
    {
        char m;
        int n;
    } cha[100];
    scanf("%s",STRING);
    for(i=0;i<strlen(STRING);i++)
    {
        if(STRING[i]>='0'&&STRING[i]<='9')
        {
            if(k==0) cha[j].n=0;
            cha[j].n=cha[j].n*10+STRING[i]-'0';
            k=1;
        }
        else
        {
            if(k==0) cha[j].n=1;
            cha[j].m=STRING[i];j++;k=0;
        }
    }
    for(i=0;i<j;i++)
    {
        while(cha[i].n)
        {
            printf("%c",cha[i].m);
            cha[i].n--;
        }
    }
    return 0;
}