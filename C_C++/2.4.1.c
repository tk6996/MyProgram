#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main(){
    int i,j;
    for(i=2;i<=13;i+=2){
    system("cls");
    for(j=1;j<=12;j++){
    printf("%d * %d= %d\t %d* %d= %d\n",i,j,i*j,i+1,j,(i+1)*j);}
    printf("\n");
    getch();}}

