#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(void)
{
    auto comp = [](const pair<int,double> *a,const pair<int,double> *b)->bool
    {
        return a->second > b->second;   
    };
    int K, M;
    priority_queue<pair<int,double>*,vector<pair<int,double>*>,decltype(comp)> factory(comp);
    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        int P, Q;
        scanf("%d %d", &P, &Q);
        factory.push(new pair<int, double>(Q, (double)P / Q));
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int x;
        scanf("%d", &x);
        double price = 0.0;
        while (x && !factory.empty())
        {
            if (x < factory.top()->first)
            {
                price+=factory.top()->second * x;
                factory.top()->first -= x;
                break;
            }
            else
            {
                price+=factory.top()->first*factory.top()->second;
                x-=factory.top()->first;
                factory.pop();
            }
        }
        printf("%.3lf\n",price);
    }
    return 0;
}