#include<stdio.h>
int main()
{
    char cha[100],pal[100];
    char *p,*q;
    int num=-1,i,k=0;
    p=cha;q=pal;
    scanf("%s",p);
    do{num++;}
    while(*(p+num)!='\0');
    num++;
    for(i=1;i<num;i++){ *(q+i-1)=*(p+num-i-1);
    *(q+num-1)='\0';
    for(i=0;i<num;i++){if(*(q+i)==*(p+i)) continue;k=1;}
    if(k==1)
    printf("Not Palindrome");
    else
    printf("Palindrome");
    return 0;
}