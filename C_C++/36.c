#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,n,a[1000],p[2][1000],O,A,L,z,F1,F2;
    double g,k,d=0,h=1,s,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&p[j][i]);
        }
    }
    //for(i=0;i<n;i++) printf("%d %d\n",p[0][i],p[1][i]); ------ Test Output---
    //for(i=0;i<n;i++) { a[i]=p[0][i]/p[1][i];d=d+a[i];}
        for(i=0;i<n;i++)
    {
        h=h*p[1][i];
    }
        for(i=0;i<n;i++)
        {
            a[i]=p[0][i]*(h/p[1][i]);
            d=d+a[i];
        }
        k=d/h;
        g=ceil(k);
        s=floor(k);
        l=d-(s*h);
           // printf("%lf %lf %lf %lf\n",d,s,h,l);
        A=h;
        L=l;
        do
        {
            O=0;
         for(i=2;i<=L;i++)
        {
            if(L%i==0&&A%i==0)
            {
                L=L/i;A=A/i;O++;   // printf("\n\n\n 5\n");
            }
        }
        }while(O!=0);
    printf("%.0lf\n",g);
    if(A-L!=A)
    printf("%d/%d",A-L,A);
    else
    printf("%d",0);
}

