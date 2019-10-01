#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int checkError(char s[])
{
    int i,j=0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]<'0'||s[i]>'9') {j=1;break;}
    }
    return j;
}
int main()
{
    char N[80],input[100];
    float x[10000],*y,am=0,slot[10000],median,gm=1,nf,hm=0,count[2][10000],mode[2][3],Max,Min,QF[4],QD[2],s[10000],s2[10000],MD=0,Var=0,SDS,VarS,SDP,VarP,CR,CQD,CMD,CVP,CVS;
    int n=0,m,l,k=0,New,lock=0,QI[4];
    y=&x[0];
    printf("Program Statistics\n");
    printf("Enter Name File : ");
    scanf("%[^\n]s",N);
    printf("Exit When Enter \"Exit\"\n\n");
    do
    {

    printf("Enter Number%5d:",n+1);
    scanf("%s",input);
    if(!strcmp("Exit",input)) break;
    if(!checkError(input)){x[n]=atof(input);n++;}
    else {printf("Error Enter Press Enter again\n");}
    }while(1);
    printf("\n%s\n",N);
    if(n>0){
    // Show input for(m=0;m<n;m++) printf("\n%f",x[m]);
        //Arithmetic Mean
    for(m=0;m<n;m++)
        am=am+*(y+m);
    am=am/n;
    printf("\nArithmetic Mean is %.2f",am);
        //Median
    for(m=0;m<n;m++)
    {
            for(l=m;l>=0;l--)
            {
                if(*(y+m)>slot[l-1]){slot[l]=*(y+m);break;}
                slot[l]=slot[l-1];
            }
            if(*(y+m)<slot[0])slot[0]=*(y+m);
    }
    if((n%2)==0)
    {
        median=(slot[(n-1)/2]+slot[(n+1)/2])/2.0;
    }
    else median=slot[(n)/2];
    /*show Number Order for(m=0;m<n;m++){printf("\n%.2f",slot[m]);}*/
    printf("\nMedian is %.2f",median);
        //Mode
    for(m=0;m<n;m++)
    {
        New=0;
        for(l=0;l<k;l++)
            {
                if(slot[m]==count[0][l])
                {
                    count[1][l]++;New++;break;
                }
            }
        if(New==0)
            {
                count[0][k]=slot[m];count[1][k]=1;k++;
            }
    }
    /*Count Number
    printf("\nNumber\tCount");
    for(m=0;m<k;m++)
    {
        printf("\n%.2f\t%.0f",count[0][m],count[1][m]);

    }*/
    for(m=0;m<k;m++)
    {
        if(count[1][m]>=mode[1][0]){
                                    if(count[1][m]>mode[1][0])lock=0;
                                    if(lock==0){mode[1][0]=count[1][m];mode[0][0]=count[0][m];mode[0][1]=mode[0][2]=0;}
                                    if(lock==1){mode[1][1]=count[1][m];mode[0][1]=count[0][m];}
                                    if(lock==2){mode[1][2]=count[1][m];mode[0][2]=count[0][m];}
                                    if(lock>2) {mode[0][1]=mode[0][2]=0;}lock++;}
    }
    /*Lock Check printf("\n lock is %d",lock);*/
    if(lock>2){printf("\nNo Mode");}
    if(lock<=2){
    printf("\nMode is");
    for(m=0;m<lock;m++){printf(" %.2f\t",mode[0][m]);}
    }
        //Geometric Mean
        for(m=0;m<n;m++)
        gm=gm*(*(y+m));
        nf=n;
        gm=pow(gm,1/nf);
        printf("\nGeometric Mean is %.2f",gm);
        //Harmonic Mean
        for(m=0;m<n;m++)
        hm=hm+1/x[m];
        hm=nf/hm;
        printf("\nHarmonic Mean is %.2f",hm);
    if(x[1]>-999999){
        //Mid-Range
        Min=slot[0];Max=slot[n-1];
        printf("\nMin is %.2f\tMax is %.2f",Min,Max);
        printf("\nRange is %.2f",Max-Min);
        printf("\tMid-Range is %.2f",(Min+Max)/2.0);
        //Quartile Deviation
        QF[0]=floor((n+1)/4.0)-1;QI[0]=QF[0];
        QF[1]=ceil((n+1)/4.0)-1;QI[1]=QF[1];
        QD[0]=slot[QI[0]]+((slot[QI[1]]-slot[QI[0]])*(((n+1)/4.0)-floor((n+1)/4.0)));
        printf("\nQuartile 1 is %.2f",QD[0]);
        QF[2]=floor(3*(n+1)/4.0)-1;QI[2]=QF[2];
        QF[3]=ceil(3*(n+1)/4.0)-1;QI[3]=QF[3];
        QD[1]=slot[QI[2]]+((slot[QI[3]]-slot[QI[2]])*((3*(n+1)/4.0)-floor(3*(n+1)/4.0)));
        printf("\tQuartile 3 is %.2f",QD[1]);
        printf("\nQuartile Deviation is %.2f",(QD[1]-QD[0])/2);
        //Mean Deviation
        for(m=0;m<n;m++)
        {
            s[m]=slot[m]-am;
        }
        for(m=0;m<n;m++)
        {
            s2[m]=pow(s[m],2);
        }
        for(m=0;m<n;m++)
            MD=MD+(pow(s2[m],0.5));
        MD=MD/n;
        printf("\nMean Deviation is %.2f",MD);
        //Standard Deviation & Variance
        for(m=0;m<n;m++)
            Var=Var+s2[m];
        VarP=Var/n;VarS=Var/(n-1);
        SDP=pow(VarP,0.5);SDS=pow(VarS,0.5);
        printf("\nStandard Deviation (Population) is %.2f\nStandard Deviation (Sample) is %.2f",SDP,SDS);
        printf("\nVariance (Population) is %.2f\nVariance (Sample) is %.2f",VarP,VarS);
        //Coefficient
        CR=(Max-Min)/(Max+Min);
        CQD=(QD[1]-QD[0])/(QD[1]+QD[0]);
        CMD=MD/am;
        CVP=SDP/am;
        CVS=SDS/am;
        printf("\nCoefficient of Range is %.2f",CR);
        printf("\nCoefficient of Quartile Deviation is %.2f",CQD);
        printf("\nCoefficient of Mean Deviation is %.2f",CMD);
        printf("\nCoefficient of Variation (Population) is %.2f",CVP);
        printf("\nCoefficient of Variation (Sample) is %.2f",CVS);
}
} else printf("No Data");
    printf("\n");
    system("pause"); 
    return 0;
}
