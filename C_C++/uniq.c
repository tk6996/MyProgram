#include<stdio.h>
#include<string.h>
int uniq(char *);
int main()
{
    char a[100],b[100],*p,*q,ac[100],bc[100];
    int i;
    p=a;q=b;
    scanf("%s",p);
    scanf("%s",q);
    uniq(p);
    uniq(q);
    printf("%s\n%s",p,q);
}
int uniq(char *cha)
{
    int i,j=0;
    char d=' ';
    for(i=0;i<=strlen(cha);i++)
    {
        if(d!=*(cha+i))
        {
            *(cha+j)=*(cha+i);
            d=*(cha+j);
            j++;
        }
    }
    cha[j]='\0';
}