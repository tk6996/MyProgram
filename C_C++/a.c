#include<stdio.h>
void func(int nb, void (*f)(int)) {
    int i;
    for (i = 0; i < nb; i++) f(i);
}

int main()
{
    for(int i=0;i<5;({
        void callback(int v) { printf("%d\n", v); }
        callback(i++);
    }))
    {
        printf("Time :");
    };
}