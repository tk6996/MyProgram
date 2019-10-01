#include<stdio.h>
void main(){
    int m,n,A,B,C,D,E,F;
    float i;
    printf("Menu\n");
    printf("1. Hamburger    25  Baht\n");
    printf("2. Cheeseburger 30  Baht\n");
    printf("3. Fishburger	28  Baht\n");
    printf("4. Coke         20  Baht\n");
    printf("5. Fanta        20  Baht\n");
    printf("6. French Fries 25  Baht\n");
    printf("7. End\n\n");
    m=0,i=0,A=0,B=0,C=0,D=0,E=0,F=0;
    while(n!=7){
    printf("Enter menu 1-7 : ");
    scanf("%d",&n);
    switch(n){
        case 1 :i=i+25;A=A+1;break;
        case 2 :i=i+30;B=B+1;break;
        case 3 :i=i+28;C=C+1;break;
        case 4 :i=i+20;D=D+1;break;
        case 5 :i=i+20;E=E+1;break;
        case 6 :i=i+25;F=F+1;break;
        default:;}}
             printf("  Menu           Amount       Cost(Bath)\n");
    if(A!=0){m=m+1;printf("%d.Hamburger         %d            %d     \n",m,A,A*25);}
    if(B!=0){m=m+1;printf("%d.Cheeseburger      %d            %d     \n",m,B,B*30);}
    if(C!=0){m=m+1;printf("%d.Fishburger        %d            %d     \n",m,C,C*28);}
    if(D!=0){m=m+1;printf("%d.Coke              %d            %d     \n",m,D,D*20);}
    if(E!=0){m=m+1;printf("%d.Fanta             %d            %d     \n",m,E,E*20);}
    if(F!=0){m=m+1;printf("%d.French Fries      %d            %d     \n",m,F,F*25);}
    printf("\nCost = %.2f\n",i);
    printf("Tax = %.2f",i/10);
    printf("\nCost All = %.2f",i+i/10);}
