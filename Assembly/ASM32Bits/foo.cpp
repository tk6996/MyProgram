#include<stdio.h>

extern "C" int bar(int param);

// void bar(int param)
// {
// 	printf("%p",&param);
// }
void foo(void) {
	int i;
	scanf("%d",&i);
	printf("%d\n",bar(i));
	printf("Pass");
}

int main(){foo();return 0;}