#include<stdio.h>
int Primenum(int,int*);
int main()
{
    int i,j,n,a[5000],k,o=0;
    scanf("%d",&n);
    k=Primenum(n,a);
    /*for(i=0;i<k;i++) printf("%d ",a[i]);
    printf("\n%d",k);*/
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(a[j]==n-a[i]) {printf("%d = %d + %d\n",n,a[i],a[j]);o++;}
        }
    }
    if(o==0) printf("Invalid");
}
int Primenum(int n,int *prt)
{
    int i,j,k=0;
    for(i=2;i<=n;i++)
    {
        for(j=2;j<n;j++)
        {
        if(i%j==0&&i!=j) goto end;
        }
        *(prt+k)=i;
        k++;
        end:;
    }
    return k;
}
