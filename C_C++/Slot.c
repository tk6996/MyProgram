#include<stdio.h>
#include<conio.h>
main()
{
    int x[10000],i=-1,n,m,y[10000],j,M;
    float Median=0;
    printf("Program Slot Number\n");
    printf("Enter 1 for few to more\n");
    printf("Enter 2 for more to few\n");
    printf("Choose the Mode :");
    scanf("%d",&M);
    while(M<1||M>2)
            {
            printf("Error\nChoose the Mode :");
            scanf("%d",&M);
            }
    printf("\n-999 to Exit\n");
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
                if(x[i]<=y[n]&&M==1)
                    {
                        for(m=i;m>n;m--)
                            {
                                y[m]=y[m-1];
                            }
                    y[m]=x[i];j=1;break;
                    }
                                if(x[i]>=y[n]&&M==2)
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
    switch(M)
    {
        case '1' : printf("Slot few to more is ");break;
        case '2' : printf("Slot more to few is ");break;
        default : ;
    }
    for(n=0;n<i;n++)
    {
        printf("%d ",y[n]);
    }
        if((i+1)%2==0)
        Median=y[i/2];
        else
        Median=(y[(i-1)/2]+y[(i+1)/2])/2.0;
        printf("\nMedian is %.1f",Median);
        getch();
        return 0;
}
