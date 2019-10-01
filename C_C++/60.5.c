#include<stdio.h>
int main()
{
    char t[10],w[9];
    int i,j=0;
    for(i=0;i<9;i++)
    scanf("%c",&t[i]);
    /////////
    if(t[0]==t[1])if(t[1]==t[2]) {w[j]=t[0];j++;}
    if(t[3]==t[4])if(t[4]==t[5]) {w[j]=t[3];j++;}
    if(t[6]==t[7])if(t[7]==t[8]) {w[j]=t[6];j++;}
    if(t[0]==t[3])if(t[3]==t[6]) {w[j]=t[0];j++;}
    if(t[1]==t[4])if(t[4]==t[7]) {w[j]=t[1];j++;}
    if(t[2]==t[5])if(t[5]==t[8]) {w[j]=t[2];j++;}
    if(t[0]==t[4])if(t[4]==t[8]) {w[j]=t[0];j++;}
    if(t[6]==t[4])if(t[4]==t[2]) {w[j]=t[6];j++;}
    if(j==0)printf("-");
    else
    {
        printf("%c",w[0]);
    for(i=1;i<j;i++)
        {
        if(w[i]==w[0]) continue;
        printf("\b-");
        }
    }

}
