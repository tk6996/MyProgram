#include<stdio.h>
void main(){
    int i,j,k;
    for(i=0;i<=9;i++){
        if(i<5)
            for(j=0;j<i;j++){
            printf("%d  ",j);}
        else
            for(k=10;k>i;k--){
            printf("%d  ",(k-10)*-1);}
        printf("\n");}}

