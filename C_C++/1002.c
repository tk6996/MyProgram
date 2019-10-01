#include<stdio.h>

int main()
{
int a,n,m,i=0,v=0,x=0,l=0,c=0;

scanf("%d",&a);


for(m=1;m<=a;m++)
{
n = m/100;
if(n==1)c++;
if(n==2)c+=2;
if(n==3)c+=3;

n = m%100;
n = n/10;
if(n == 1)x++;
if(n == 2)x+=2;
if(n == 3)x+=3;
if(n == 4){x+=1; l++;}
if(n == 5)l++;
if(n == 6){x+=1; l++;}
if(n == 7){l++; x+=2;}
if(n == 8){x+=3; l++;} 
if(n == 9){x++; c++;}

n = m%10;
if(n == 1)i++;
if(n == 2)i+=2;
if(n == 3)i+=3;
if(n == 4){i+=1; v++;}
if(n == 5)v++;
if(n == 6){v+=1; i++;}
if(n == 7){v++; i+=2;}
if(n == 8){i+=3; v++;} 
if(n == 9){x++; i++;}
}

printf("%d %d %d %d %d",i,v,x,l,c);

return 0; 
}