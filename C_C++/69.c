#include<stdio.h>
int main()
{
   int i,tank[4],money;
   for(i=0;i<4;i++)
   {
       scanf("%d",&tank[i]);
   }
   
    money=tank[0]*40 + tank[1]*42 + tank[2]*50 + tank[3]*48;
    if(money<=20000&&tank[0]+tank[1]+tank[2]+tank[3]<=100) printf("%d %dM %d %dM %d %dM %d %dM SUM = %dM",tank[0],tank[0]*40,tank[1],tank[1]*42,tank[2],tank[2]*50,tank[3],tank[3]*48,money);
    else printf("Can't buy");
}