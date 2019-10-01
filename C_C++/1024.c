#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MIN(a, b) (a) < (b) ? a : b
#define MAX(a, b) (a) > (b) ? a : b
int main(void)
{
    int delta_min = INT_MAX;
    int index_2, index_3;
    int numOfFactories;
    int profitsAll = 0;
    scanf("%d", &numOfFactories);
    int *factories = calloc(numOfFactories, sizeof(*factories));
    for (int i = 0; i < numOfFactories; i++)
    {
        scanf("%d", factories + i);
        profitsAll += factories[i];
    }
    for (int i = 1, sum1 = 0; i < numOfFactories - 1; i++)
    {
        sum1 += factories[i - 1];
        for (int j = i + 1, sum2 = 0; j < numOfFactories; j++)
        {
            sum2 += factories[j - 1];
            int sum3 = profitsAll - sum1 - sum2;
            int mi = MIN(sum1, MIN(sum2, sum3));
            int ma = MAX(sum1, MAX(sum2, sum3));
            if (abs(ma - mi) < delta_min)
            {
                delta_min = abs(ma - mi);
                index_2 = i;
                index_3 = j;
            }
        }
    }
    printf("%d %d", index_2 + 1, index_3 + 1);
    free(factories);
}