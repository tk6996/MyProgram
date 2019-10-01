#include<stdio.h>
int main()
{
    int N,n[100],m[100],j=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    scanf("%d",&n[i]);
    m[0]=n[N-1];
    for(int i=N-1;i>=0;i--)
    {
        if(m[j]<n[i]) {j++;m[j]=n[i];}
    }
    printf("%d\n",j+1);
    for(int i=0;i<=j;i++)
    printf("%d ",m[j-i]);
}
