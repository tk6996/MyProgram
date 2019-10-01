#include<stdio.h>
int Primenum(int,int*);
int main()
{
    int i,j,n,a[5000],k,p,o=0,d[100];
    scanf("%d",&n);
    k=Primenum(n,a);
    /*for(i=0;i<k;i++) printf("%d ",a[i]);
    printf("\n%d",k);*/
    p=n;
    frist: 
    for(i=0;i<k;i++)
    {
        if(p%a[i]==0){d[o]=a[i];p=p/a[i];o++;goto frist;}
    }
    printf("%d = %d ",n,d[0]);
    for(i=1;i<o;i++) printf("x %d ",d[i]);
}
int Primenum(int n,int *prt)
{
    int i,j,k=0,s=0;
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
