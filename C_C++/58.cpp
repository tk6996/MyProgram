#include<stdio.h>
int main()
{
    char cha[1000],a[1000],A[1000],n[1000];
    int i,j=0,k=0,l=0,m=0;
    scanf("%s",cha);
    for(i=0;i<1000;i++)
    {
        if(cha[i]=='\0')break;
        j++;
    }
    for(i=0;i<j;i++)
    {
        if(cha[i]>='a'&&cha[i]<='z') {a[k] = cha[i];k++;}
        if(cha[i]>='A'&&cha[i]<='Z') {A[l] = cha[i];l++;}
        if(cha[i]>='0'&&cha[i]<='9') {n[m] = cha[i];m++;}
    }
    a[k]='\0';A[l]='\0';n[m]='\0';
    if(k!=0)
    {
        printf("%s",a);
    }
    else printf("-");
    printf("\n");
        if(l!=0)
    {
        printf("%s",A);
    }
    else printf("-");
    printf("\n");
        if(m!=0)
    {
        printf("%s",n);
    }
    else printf("-");
}
