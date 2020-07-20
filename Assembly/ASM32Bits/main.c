#include <stdio.h>

long long unsigned factorial(unsigned);


int main(int argc, char **argv)
{
    unsigned n;
    long long unsigned f;
    printf("factorial of... ? ");
    scanf("%u", &n);

    f = factorial(n);

    printf("factorial(%u) is %Lu\n", n, f);
    return 0;
}
