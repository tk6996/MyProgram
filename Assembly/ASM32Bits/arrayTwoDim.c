#include<stdio.h>
extern void printArrayTwoDim(int arr[8][8]);
int main()
{
    int a[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            a[i][j] = (i << 3) + j;
        }
    }
    printArrayTwoDim(a);
}