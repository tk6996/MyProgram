#include<stdio.h>
int main()
{
	unsigned int x[10000][32],n[10000],d,c[10000];
	scanf("%d",&d);
    for(int k=0;k<d;k++) scanf("%d",&n[k]);
	for(int j=0;j<d;j++){
	for(int i=0;i<32;i++)
	{
        x[j][i]=n[j]%2;
        n[j]=n[j]/2;
	}
    for(int i=0;i<32;i++)
        if(x[j][i]==1) c[j]++;
    printf("%d",c[j]);
    printf("\n");
    }
	return 0;
}
