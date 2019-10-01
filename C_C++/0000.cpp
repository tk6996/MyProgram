#include<cstdio>
#include<cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    int W,H,n;
    int filter[3000]={0};
    scanf("%d %d %d",&W,&H,&n);
    for(int i=0;i<n;i++)
    {
        int x,a;
        scanf("%d %d",&x,&a);
        for(int j=x;j<x+a;j++)
        {
            if(j>W) break;
            filter[j]++;
        }
    }
    int Areacount100=0,Areacount50=0;
    for(int i=0;i<W;i++)
    {
        if(filter[i]==1) Areacount50+=H;
        if(filter[i]==0) Areacount100+=H;
    }
    printf("%d %d",Areacount100,Areacount50);
    return 0;
}