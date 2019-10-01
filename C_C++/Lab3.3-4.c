#include<stdio.h>
int main()
{
    int x1,x2,i,gcd=1,count;
    scanf("%d %d",&x1,&x2);
    do{
    count=0;
    for(i=2;i<=x1;i++)
	    if(x1%i==0&&x2%i==0) {x1=x1/i;x2=x2/i;gcd=gcd*i;count++;}	
    }while(count>=1);
    printf("%d",gcd);
    return 0;
}