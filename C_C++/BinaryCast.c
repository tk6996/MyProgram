#include <stdio.h>
int main(void)
{
    int size = 0;
    char a[5];
    while (size < 5)
        if((a[size] = getchar()) && (a[size]>='A' && a[size]<='Z')) size++;
    for (int i = 0; i < size; i++)
        {
            printf("0b");
            for(int j = 6 ; j >= 0 ; j--)
                printf("%d",a[i] >> j & 1);
            printf("\n");
        }
        return 0;
}