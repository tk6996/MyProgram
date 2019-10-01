#include <stdio.h>
int max_to_min(int*,int);
int min_to_max(int*,int);
int printnum(int*,int);
int main()
{
    int num[100000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    min_to_max(num,n);
    printnum(num,n);
    max_to_min(num,n);
    printf("\n"); 
    printnum(num,n);
    return 0;
}
int max_to_min(int *num,int n)
{
    int i,j,temp;
    for(j=0;j<n-1;j++)
    {
        for(i=0;i<n-1;i++)
        {
            if(*(num+i)<*(num+i+1)) 
            {
                temp=*(num+i);
                *(num+i)=*(num+i+1);
                *(num+i+1)=temp;
            }
        }
    }
    return 0;
}
int min_to_max(int *num,int n)
{
    int i,j,temp;
    for(j=0;j<n-1;j++)
    {
        for(i=0;i<n-1;i++)
        {
            if(*(num+i)>*(num+i+1)) 
            {
                temp=*(num+i);
                *(num+i)=*(num+i+1);
                *(num+i+1)=temp;
            }
        }
    }
    return 0;
}
int printnum(int*num,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",*(num+i));
    }
    return 0;
}