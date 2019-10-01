#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
vector<vector<int>> mutiply_matrix(vector<vector<int>> A,vector<vector<int>> B)
{
    vector<vector<int>> M;
    int m1=A.size();
    int n1=A[0].size();
    int m2=B.size();
    int n2=B[0].size();
    if(n1!=m2) return M;
    for(unsigned y=0;y<m1;y++)
    {
        vector<int> N;
        for(unsigned x=0;x<n2;x++)
        {
            int sum=0;
            for(unsigned z=0;z<n1;z++)
            {
                sum+=A[y][z]*B[z][x];
            }
            N.push_back(sum);
        }
        M.push_back(N);
    }
    return M;
}
int main(void)
{
    vector<vector<int>> A={{-70,1,3,-7},{50,-44,7,9}};
    vector<vector<int>> B={{2,6},{7,9},{8,8},{44,-112}};
    vector<vector<int>> C=mutiply_matrix(A,B);
    for(auto i:C)
    {
        for(auto j:i)
        {
            cout<< j << " ";
        }
        cout<< endl;
    }
    return 0;
}