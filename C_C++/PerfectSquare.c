#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c,ans1,ans2;
	scanf("%d %d %d",&a,&b,&c);
	ans1 = (-b+sqrt(b*b-4*a*c))/2/a;
	ans2 = (-b-sqrt(b*b-4*a*c))/2/a;
	//printf("%d %d %d",a,b,c);
	//scanf("%d %d",&ans1,&ans2);
	if (ans1<0&&ans2>0)
	{
		printf("%d,%d",ans2,ans1);
	}
	else if (ans2<0&&ans1>0)
	{
		printf("%d,%d",ans1,ans2);
	}
	else if(ans1<=ans2)
	{
		printf("%d,%d",ans1,ans2);
	}
	else
	printf("%d,%d",ans2,ans1);
	return 0;
}
