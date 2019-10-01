#include<stdio.h>
int main(int argc, char const *argv[])
{
    int x,y,k,count=0,stack[100][2],i,b=1,min,max;
    printf(" *** Solving equation 1/x + 1/y = 1/k ***\n");
    printf(" *** x, y and k are counting numbers. ***\n");
    printf("Enter k : ");
    scanf("%d",&k);
    if(k<=0) 
    {
        printf(" ===> INVALID k <===");
        return 0;
    }
    min=k+1;max=(k+1)*(k);
    for(x=min;x<=max && b;x++)
    {
        for(y=max;y>=min;y--)
        {
            if((x+y)*k==(x*y))
            {
                stack[count][0] = x;
                stack[count][1] = y;
                min=x;
                max=y;
                if(x==y){b=0;}
                count++;
                break;
            }
        }
    }
    count+=count-1;
    for(i = 0; i < count; i++)
    {
        if(i<count/2)
            printf("%2d. 1/%d + 1/%d = 1/%d\n",i+1,stack[i][0],stack[i][1],k);
        else
            printf("%2d. 1/%d + 1/%d = 1/%d\n",i+1,stack[count-i-1][1],stack[count-i-1][0],k);
    }
    if(count==1) printf("There is %d solution.",count);
    else printf("There are %d solutions.",count);
    return 0;
}
