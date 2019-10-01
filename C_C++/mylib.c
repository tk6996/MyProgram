#include <stdio.h>
#include "mylib.h"
void printbit(void *address, int bytes)
{
    for (int i = bytes - 1; i >= 0; --i)
    {
        int mem = *(((char *)address) + i);
        for (int bit = 7; bit >= 0; --bit)
        {
            printf("%d", 0b1 & (mem >> bit));
        }
    }
}