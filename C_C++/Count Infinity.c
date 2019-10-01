#include<stdio.h>
#include<conio.h>
int main()
{
    int x[100000][2],i,n,Mode[3][2],lock;
    printf("Program Count Number\n");
    printf("-999 to Exit\n");
    i=-1;Mode[0][1]=0;
    do
    {
        i++;
        printf("Enter Number %d: ",i+1);
        scanf("%d",&x[i][0]);
        for(n=0;n<=i;n++)
            {
        if(x[i][0]==x[n][0])
        {
            x[n][1]++;break;
        }
            }
        if(x[n][1]==0)
            {
                x[n][1]++;
            }
    }while(x[i][0]!=-999);
    printf("\n%19s\n","Result");
    printf("%8s%22s\n","Number","Count");
    for(n=0;n<=i;n++)
    {
    if(x[n][1]!=0)
    if(x[n][0]!=-999)
    printf("%5d\t%20d\n",x[n][0],x[n][1]);
    }

    for(n=0;n<=i;n++){
    if(x[n][0]!=-999){
    if(x[n][1]>Mode[0][1])
    {
       Mode[0][0]=x[n][0];Mode[0][1]=x[n][1];
       Mode[1][1]=0;
       Mode[2][1]=0;
       lock=0;
    }
    else
        {
        if (x[n][1]==Mode[0][1])
        {
            if(lock==0)
            {
                Mode[1][0]=x[n][0];Mode[1][1]=x[n][1];Mode[2][1]=0;lock++;
            }
            else
            if(lock==1)
            {
                Mode[2][0]=x[n][0];Mode[2][1]=x[n][1];lock++;
            }
            else{
                Mode[1][1]=0;
                Mode[2][1]=0;
                lock++;
                }

        }
        }
        }
        }
    if(Mode[0][1]>0&&lock<3){
    printf("\nMode is ");
    for(n=0;n<3;n++)
    {
    if(Mode[n][1]>0){
    printf("%d ",Mode[n][0]);
    }
    }
    }

    else printf("No Mode");
    getch();
    return 0;
}
