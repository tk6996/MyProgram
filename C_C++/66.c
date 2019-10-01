#include<stdio.h>
int main()
{
    int i,j,b,k,n,ii,jj,t[3][3]={0},d=0,a=2;
    for(i=0;i<9;i++)
    {
        scanf("%d %d",&j,&k);
        if(i%2==0) t[j][k]=2;
        else t[j][k]=1;
        /*for(ii=0;ii<3;ii++)
        {
        for(jj=0;jj<3;jj++)
            {
            printf("%d",t[ii][jj]);
            }
        printf("\n");
        }*/
        if(d==0)
         {
            if(t[0][0]!=0)if(t[0][0]==t[0][1])if(t[0][1]==t[0][2]) {d++;if(t[0][0]==2)a=0;else a=1;/*printf("Win1");*/}
            if(t[1][0]!=0)if(t[1][0]==t[1][1])if(t[1][1]==t[1][2]) {d++;if(t[1][0]==2)a=0;else a=1;/*printf("Win2");*/}
            if(t[2][0]!=0)if(t[2][0]==t[2][1])if(t[2][1]==t[2][2]) {d++;if(t[2][0]==2)a=0;else a=1;/*printf("Win3");*/}
            if(t[0][0]!=0)if(t[0][0]==t[1][0])if(t[1][0]==t[2][0]) {d++;if(t[0][0]==2)a=0;else a=1;/*printf("Win4");*/}
            if(t[0][1]!=0)if(t[0][1]==t[1][1])if(t[1][1]==t[2][1]) {d++;if(t[0][1]==2)a=0;else a=1;/*printf("Win5");*/}
            if(t[0][2]!=0)if(t[0][2]==t[1][2])if(t[1][2]==t[2][2]) {d++;if(t[0][2]==2)a=0;else a=1;/*printf("Win6");*/}
            if(t[0][0]!=0)if(t[0][0]==t[1][1])if(t[1][1]==t[2][2]) {d++;if(t[0][0]==2)a=0;else a=1;/*printf("Win7");*/}
            if(t[0][2]!=0)if(t[0][2]==t[1][1])if(t[1][1]==t[2][0]) {d++;if(t[0][2]==2)a=0;else a=1;/*printf("Win8");*/}
         }
    }
    switch(a)
    {
       case 0 : printf("O");break;
       case 1 : printf("X");break;
       default : printf("-");
    }
}
   