#include<stdio.h>
#include<string.h>
int swap(char*,int,int);
int main()
{
    char str[100],str2[100];
    int n,x=0,p1,p2;
    scanf("%s",str);
    scanf("%s",str2);
    n=strlen(str);
    while(x<strlen(str2))
    {
        switch(str2[x])
        {
            case 'A' : p1=0;p2=1;break;
            case 'B' : p1=n-1;p2=n-2;break;
            case 'C' : p1=0;p2=n-1;break;
            default:;
        }
        swap(str,p1,p2);
        x++;
    }
    printf("%s",str);
    return 0;
}
int swap(char *str,int p1,int p2)
{
    char temp;
    temp=*(str+p1);
    *(str+p1)=*(str+p2);
    *(str+p2)=temp;
    return 0;
}