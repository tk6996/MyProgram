#include<stdio.h>
int main()
{
	char sen[100],pal[100],x=0;
	scanf("%s",sen);
	for(int i=0;i<100;i++)
		if(sen[i]!='\0') 	x++;
		else break;
	for(int i=0;i<x;i++)
		printf("%c",sen[i]);
	//printf("Char have %d",x);
}
