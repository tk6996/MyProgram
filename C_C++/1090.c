#include <stdio.h>
#include <stdlib.h>
static size_t arr[100001];
int main(void)
{
    size_t n,count=0;
    int last=-1;
    scanf("%llu",&n);
    for (size_t i = 0; i < n; i++)
    {
        int index;
        scanf("%d",&index);
        arr[index]++;
        if(last<index) last = index;
    }
    int des ;
    scanf("%d",&des);
    int frist = (des - last) < 0 ? 0 : (des - last);
    if(!frist) last = des;
    while (frist < last)
    {
        count+=arr[frist++]*arr[last--];
    }
    if(frist==last) count+=(arr[frist]-1)*(arr[frist])/2;
    printf("%llu",count);
    return 0;
}