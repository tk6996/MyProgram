#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d", &n);
	int sum=0;
	for (i = 1; i <= 12; i++)
	{
		sum += n * i;
	}
	printf("%d", sum);
}