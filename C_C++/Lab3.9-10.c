#include<stdio.h>
int main()
{
    int x,y,c,x1,x2,i,gcd,count,max=1,a,b;
    for(x=2;x<=200;x++)
        {
            for(y=2;y<x;y++)
            {
                gcd=1;x1=x;x2=y;
                do{
                count=0;
                for(i=2;i<=x1;i++)
	                if(x1%i==0&&x2%i==0) {x1=x1/i;x2=x2/i;gcd=gcd*i;count++;}	
                }while(count>=1);
                if(max<gcd) {max=gcd;a=x;b=y;}
            }
        }
    printf("%d %d",a,b);
    return 0;
}