#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=-n;i<=n;i++)
    {   
        for(j=-n;j<=n;j++)
        {   
        if(i<=0){
            if(j<=0){if(i<=j) printf("%d",n+i);else printf("%d",n+j);}
            else{if(-i>j) printf("%d",n+i);else printf("%d",n-j);}
            }
        else{   
            if(j<=0){if(i>-j) printf("%d",n-i);else printf("%d",n+j);}
            else{if(i>=j) printf("%d",n-i);else printf("%d",n-j);}
        }
        }
        printf("\n");
    }
}