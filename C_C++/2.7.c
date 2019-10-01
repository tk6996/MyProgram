#include<stdio.h>
void main(){
    int n;
    float i;
    printf("Menu\n");
    printf("1. Hamburger    25  Baht\n");
    printf("2. Cheeseburger 30  Baht\n");
    printf("3. Fishburger	28  Baht\n");
    printf("4. Coke         20  Baht\n");
    printf("5. Fanta        20  Baht\n");
    printf("6. French Fries 25  Baht\n");
    printf("7. End\n\n");
    i=0;
    while(n!=7){
    printf("Enter menu 1-7 : ");
    scanf("%d",&n);
    switch(n){
        case 1 :i=i+25;break;
        case 2 :i=i+30;break;
        case 3 :i=i+28;break;
        case 4 :i=i+20;break;
        case 5 :i=i+20;break;
        case 6 :i=i+25;break;
        default:;}}
    printf("\nCost = %.2f\n",i);
    printf("Tax = %.2f",i/10);}
