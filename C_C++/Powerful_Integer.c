#include<stdio.h>
void push(int i,int *stack,int *size)
{
    stack[*size]=i;
    (*size)++;
}
void display(int x,int y,int bound,int *stack,int *size)
{
    int a=1;
    while(a<bound)
    {
        int b=1;
        while(a+b<=bound){
            push(a+b,stack,size);
            b*=y;
        }
        a*=x;
    }
}
void shellSort(int data[],int size);
int main(int argc, char const *argv[])
{
    int x,y,bound;
    int stack[10000];
    int size=0;
    scanf("%d %d %d",&x,&y,&bound);
    display(x,y,bound,stack,&size);
    shellSort(stack,size);
    for(size_t i = 0; i < size; i++)
    {
        if(i>0) if(stack[i-1]==stack[i]) continue;
        printf("%d ",stack[i]);
    }
    return 0;
}
void shellSort(int data[],int size)
{   
    for(int gap=size/2;gap>0;gap/=2)
    {
        for(int i=gap;i<size;i++)
        {
            int temp=data[i];
            int j;
            for(j=i;j>=gap;j-=gap)
            {
                data[j]=data[j-gap];
                if(data[j-gap]<=temp) break;
            }
            data[j]=temp;
        }
    }
}