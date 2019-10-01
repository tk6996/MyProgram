#include <stdio.h>
int main(void)
{
    int size = 0;
    char a[4];
    while (size < 4)
        if((a[size] = getchar()) && (a[size]>='A' && a[size]<='Z')) size++;
    for (int i = 0; i < size; i++)
        for (int j = 0; j <= a[i] - 'A'; j++)
            putchar(a[i]);
    return 0;
}