#include<stdio.h>
int main()
{
    int i,n,num[10],j=0,k,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(num[j]>num[j+1]){temp=num[j];num[j]=num[j+1];num[j+1]=temp;}
        }
    }
    for(i=0;i<n;i++)
    {
        if(num[i]!=0){temp=num[i];num[i]=num[0];num[0]=temp;break;}
    }
    for(i=0;i<n;i++) 
    {
        printf("%d",num[i]);
    }
    
}
