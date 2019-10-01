#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(void)
{
    int k, m, n;
    scanf("%d %d %d", &k, &n, &m);
    vector<vector<int>> graph(n);
    vector<int> enegy(n,-1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1].push_back(b - 1);
    }
    int last;
    enegy[0] = k;
    for(int i=0;i<graph.size();++i)
    {
        if(enegy[i] > 0)
        for(auto itr2 : graph[i])
        {
            enegy[itr2] = max(enegy[itr2],enegy[i]-1);
        }
        if(enegy[i]>=0) last = i;
    }
    printf("%d", last+1);
    return 0;
}