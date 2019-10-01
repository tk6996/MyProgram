#include<stdio.h>
main()
{
    int x[10000],i=-1,n,m,y[10000],j;
    printf("Program Slot Number\n");
    printf("-999 to Exit\n");
    do
    {
        i++;
        printf("Enter Number %d : ",i+1);
        scanf("%d",&x[i]);
        if(x[i]!=-999)
            {
            for(n=0;n<=i;n++)
            {
                j=0;
                if(x[i]>=y[n])
                    {
                        for(m=i;m>n;m--)
                            {
                                y[m]=y[m-1];
                            }
                    y[m]=x[i];j=1;break;
                    }
            }
            if(j!=1){y[i]=x[i];j=0;}
            }
    }while(x[i]!=-999);
    printf("\nResult\n");
    printf("Slot more to few is ");
    for(n=0;n<i;n++)
    {
        printf("%d ",y[n]);
    }
}
