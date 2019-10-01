#include<stdio.h>
void main(){
    int n,i,j,k;
    printf("Number :");
    scanf("%d",&n);
    n=n+1;
    n=n*2;
    for(i=0;i<=n;i++){
        if(i<n/2)
            for(j=0;j<i;j++){
            printf("%d  ",j);}
        else
            for(k=n;k>i;k--){
            printf("%d  ",(k-n)*-1);}
        printf("\n");}}
