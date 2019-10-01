#include<stdio.h>
int main()
{
    char a[100],b[100],c[100];
    int code=0;
    scanf("%s %s %s",a,b,c);
    for(int i=0;i<100;i++)
    {
        if(a[i]<b[i]) {break;}
        if(a[i]>b[i]) {code++;break;}
        if(a[i]=='\0'){break;}
        if(b[i]=='\0'){code++;break;}
    }
        for(int i=0;i<100;i++)
    {
        if(b[i]<c[i]) {break;}
        if(b[i]>c[i]) {code+=10;break;}
        if(b[i]=='\0'){break;}
        if(c[i]=='\0'){code+=10;break;}
    }
        for(int i=0;i<100;i++)
    {
        if(a[i]<c[i]) {break;}
        if(a[i]>c[i]) {code+=100;break;}
        if(a[i]=='\0'){break;}
        if(c[i]=='\0'){code+=100;break;}
    }
    if(code==0)
    printf("%s %s %s",a,b,c);
    if(code==10)
    printf("%s %s %s",a,c,b);
    if(code==1)
    printf("%s %s %s",b,a,c);
    if(code==101)
    printf("%s %s %s",b,c,a);
    if(code==110)
    printf("%s %s %s",c,a,b);
    if(code==111)
    printf("%s %s %s",c,b,a);

}
