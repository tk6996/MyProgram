#include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(j=0;j<n;j++)
        {
            if(j==0)
            for(i=0;i<n;i++)
            {
                printf("%c",'a'+i);
            }
            if(j>0&&j<n-1)
                for(i=0;i<n;i++)
                {
                if(i==0)
                printf("%c",'a'+j);
                if(i>0&&i<n-1) printf(" ");
                if(i==n-1)
                printf("%c",'a'+n-1-j);
                }


            if(j==n-1)
            for(i=n;i>0;i--)
            {
                printf("%c",'a'+i-1);
            }
            printf("\n");
        }


}
