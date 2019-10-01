#include<stdio.h>
int row(int num)
{
    return (num/10 != 0) ? row(num/10)+1 : 1 ; 
}
size_t powInt(int base,int exp)
{
    if(exp==0) return 1;
    for(int i=1 ; i<exp ; i++)
    {
        base *= base;
    }
    return base;
}
size_t Answer(int target,int digits)
{
    int row_Ans = row(target);
    size_t Ans=0;
    while(row_Ans){
        int cur_dig = target/(int)powInt(10,row_Ans);
        if(digits-cur_dig < 0)
        {
            cur_dig--;
        }
        else
        {
            digits-=cur_dig;
            Ans +=  cur_dig*powInt(10,row_Ans);
            row_Ans--;   
        }
    }
}
int main(int argc, char const *argv[])
{
    int a,k,t;
    size_t ans[100000];
    scanf("%d",t);
    for(int i=0; i<t; i++)
    {
        scanf("%llu %llu",a,k);
        ans[i] = Answer(a,k);
    }
    return 0;
}
