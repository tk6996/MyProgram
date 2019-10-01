#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *Sum(char *a,char *b);
char *Diff(char *a,char *b);
int main(int argc, char const *argv[])
{
    char A[101],B[101];
    scanf("%s %s",A,B);
    char *sum = Sum(A,B);
    char *different = Diff(A,B);
    printf("Sum = %s \nDifferent = %s",sum,different);
    free(sum);
    free(different);
    return 0;
}
char *Sum(char *a,char *b)
{
    char *sum = (char*)malloc(102);
    int index=0,index_a = strlen(a)-1,index_b = strlen(b)-1;
    char t=0;
    while(index_a >= 0 && index_b >= 0)
    {
        sum[index]=(a[index_a--]-'0')+(b[index_b--]-'0')+t;
        if(sum[index]>9) {t=1;sum[index]-=10;}else t=0;
        index++;
    }
    while(index_a >= 0)
    {
        sum[index]=(a[index_a--]-'0')+t;
        if(sum[index]>9) {t=1;sum[index]-=10;}else t=0;
        index++;
    }
    while(index_b >= 0)
    {
        sum[index]=(b[index_b--]-'0')+t;
        if(sum[index]>9) {t=1;sum[index]-=10;}else t=0;
        index++;
    }
    if(t) {sum[index]=1;index++;sum[index]=0;}
    else {sum[index]=0;}
    int i=0,j=index-1;
    while(i<j)
    {
        sum[i]^=sum[j];
        sum[j]^=sum[i];
        sum[i]^=sum[j];
        i++;j--;
    }
    for(int i=0;i<index;i++) sum[i]+='0';
    return sum;
}
char *Diff(char *a,char *b)
{
    int symbol = 0;
    if(strlen(a)<strlen(b)) 
    {
        char *temp = a;
        a = b;
        b = temp; 
        symbol = 1;
    }
    if(strlen(a)==strlen(b))
    {
        for(int i = 0; i < strlen(a) ; i++)
        {
            if(a[i]<b[i]) {
                char *temp = a;
                a = b;
                b = temp;
                symbol = 1;
                break;
            }
            if(a[i]>b[i]) break;
        }
    } 
    char *diff = (char*)malloc(101);
    int index=0,index_a = strlen(a)-1,index_b = strlen(b)-1;
    char t=0;
    while(index_a >=0 && index_b >=0 ){
        diff[index] = (a[index_a--]-'0') - (b[index_b--]-'0') + t;
        if(diff[index]<0) {t=-1;diff[index]+=10;}else t=0;
        index++;
    }
    while(index_a >=0){
        diff[index] = (a[index_a--]-'0') + t;
        if(diff[index]<0) {t=-1;diff[index]+=10;}else t=0;
        index++;
    }
    while(index_b >=0){
        diff[index] = (b[index_b--]-'0') + t;
        if(diff[index]<0) {t=-1;diff[index]+=10;}else t=0;
        index++;
    }
    if(diff[index-1]==0) index--;
    if(symbol) {diff[index]='-';index++;diff[index]=0;}
    else {diff[index]=0;}
    int i=0,j=index-1;
    while(i<j)
    {
        diff[i]^=diff[j];
        diff[j]^=diff[i];
        diff[i]^=diff[j];
        i++;j--;
    }
    if(diff[0]!='-'){diff[0]+='0';}
    for(int i=1;i<index;i++) {diff[i]+='0';}
    return diff;
}