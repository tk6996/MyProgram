#include<stdio.h>
void main(){
    int n,i,j,k;
    printf("Number of line ==>  ");
    scanf("%d",&n);
    n=n*2;
    printf("\n");
    for(i=1;i<n;i+=2){
        for(j=n;j-1>i;j-=2){
            printf(" ");}
        for(k=0;k<i;k+=1){
            printf("*");}
        printf("\n");}}
