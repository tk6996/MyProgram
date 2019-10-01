#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define for_range(var, start, stop, step) for (var = start; var < stop; var += step)
#define swap(a,b) {int temp = a; \
        a = b;\
        b = temp;\
}
int mangetChange[200001];
void threeMedian(int *arr,int start ,int end)
{
    int *p1 = &arr[start];
    int *p2 = &arr[(end + start) / 2];
    int *p3 = &arr[end-1];
    if(*p1 > *p3)swap(*p1,*p2);
    if(*p2 > *p3)swap(*p2,*p3);
    if(*p1 > *p2)swap(*p1,*p2);
    swap(*p2,*p3);
}
void quickSort(int *arr,int start, int end)
{
    if (start >= end)
        return ;
    threeMedian(arr,start,end);
    int pviot = end - 1;
    int i = start;
    int j = pviot - 1;
    while (i <= j)
    {
        if(arr[i] > arr[pviot])
        {
            swap(arr[i],arr[j]);
            j--;
        }
        else
            i++;
    }
    swap(arr[i],arr[pviot]);
    quickSort(arr,start,i);
    quickSort(arr,i+1,end);
}
int binarySearch(int *arr, int key, int start, int end)
{
    if (start >= end)
        return start - 1;
    int mid = (end + start) / 2;
    return arr[mid] == key ? mid : key < arr[mid] ? binarySearch(arr, key, 0, mid) : binarySearch(arr, key, mid + 1, end);
}
int main(void)
{
    int N, M, Q, i;
    scanf("%d %d %d", &N, &M, &Q);
    for_range(i, 0, M, 1)
    {
        scanf("%d %d", mangetChange + (2 * i), mangetChange + (2 * i) + 1);
        mangetChange[(2 * i) + 1] += mangetChange[2 * i];
    }
    int change = 2 * M;
    quickSort(mangetChange,0,change);
    int count = 0;
    for_range(i, 0, change, 1)
    {
        if (i && mangetChange[i - 1] == mangetChange[i])
        {
            mangetChange[count - 1] = 0;
            count -= 2;
            mangetChange[i - 1] = 0;
            mangetChange[i] = 0;
        }
        else
        {
            mangetChange[count] = mangetChange[i];
        }
        count++;
    }
    change = count;
    for_range(i, 0, Q, 1)
    {
        int val;
        scanf("%d", &val);
       // printf("%d\n", binarySearch(mangetChange, val, 0, change));
        if (!change)
        {
            printf("%d\n", N);
        }
        else if (val < mangetChange[0])
            printf("%d\n", mangetChange[0] - 1);
        else if (val >= mangetChange[change-1])
            printf("%d\n", N - mangetChange[change - 1] + 1);
        else {
            val = binarySearch(mangetChange, val , 0, change);
            printf("%d\n",mangetChange[val + 1] - mangetChange[val]);
        }
    }
    return 0;
}