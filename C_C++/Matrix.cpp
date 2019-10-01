#include <vector>
#include <iostream>
using namespace std;
vector<vector<long double>> Mutiply_Matrix(vector<vector<long double>> matrix1,vector<vector<long double>> matrix2);
long double Determinant(vector<vector<long double>> matrix);
long double Minor(vector<vector<long double>> matrix,int row,int col);
long double Cofactor(vector<vector<long double>> matrix,int row,int col);
vector<vector<long double>> Transpose(vector<vector<long double>> matrix);
vector<vector<long double>> Adjoint(vector<vector<long double>> matrix);
vector<vector<long double>> Inverse_Matrix(vector<vector<long double>> matrix);
void PrintMatrix(vector<vector<long double>> matrix);
vector<vector<long double>> Mutiply_Matrix(vector<vector<long double>> matrix1,vector<vector<long double>> matrix2)
{
    vector<vector<long double>> M;
    int m1=matrix1.size();
    int n1=matrix1[0].size();
    int m2=matrix2.size();
    int n2=matrix2[0].size();
    if(n1!=m2) return M;
    for(size_t y=0;y<m1;y++)
    {
        vector<long double> N;
        for(size_t x=0;x<n2;x++)
        {
            long double sum=0;
            for(size_t z=0;z<n1;z++)
            {
                sum+=matrix1[y][z]*matrix2[z][x];
            }
            N.push_back(sum);
        }
        M.push_back(N);
    }
    return M;
}
long double Determinant(vector<vector<long double>> matrix)
{
    if(matrix.size()==0) return 0.0l;
    if(matrix.size()==1) return matrix[0][0];
    long double sum{};
    for(size_t i = 0; i < matrix[0].size(); i++)
    {
        sum+=(matrix[0][i]*Cofactor(matrix,0,i));
    }
    return sum;
};
long double Minor(vector<vector<long double>> matrix,int row,int col)
{
    vector<vector<long double>> m;
    for(size_t i = 0; i < matrix.size(); i++)
    {
        vector<long double> n;
        for(size_t j = 0; j < matrix[i].size(); j++)
        {
            if(i==row | j==col) continue;
            n.push_back(matrix[i][j]);
        }
        if(!n.empty()) m.push_back(n);
    }
    return Determinant(m);
}
long double Cofactor(vector<vector<long double>> matrix,int row,int col)
{
    return (row+col)%2 ? -1*Minor(matrix,row,col) : Minor(matrix,row,col);
}
vector<vector<long double>> Transpose(vector<vector<long double>> matrix)
{
    vector<vector<long double>> tran;
    for(size_t j=0;j<matrix[0].size();j++)
    {
        vector<long double> sub;
        for(size_t i=0;i<matrix.size();i++)
        {
            sub.push_back(matrix[i][j]);
        }
        tran.push_back(sub);
    }
    return tran;
}
vector<vector<long double>> Adjoint(vector<vector<long double>> matrix)
{
    vector<vector<long double>> M;
    for(size_t i = 0; i < matrix.size(); i++)
    {
        vector<long double> N;
        for(size_t j = 0; j < matrix[i].size(); j++)
        {
            N.push_back(Cofactor(matrix,i,j));
        }
        M.push_back(N);
    }
    return Transpose(M);
}
vector<vector<long double>> Inverse_Matrix(vector<vector<long double>> matrix)
{
    if(matrix.size()==0) return {{}};
    if(matrix.size()!=matrix[0].size()) return {{}};
    long double det = Determinant(matrix);
    if(det==0.0l) return {{}};
    vector<vector<long double>> adj = Adjoint(matrix);
    for(size_t i = 0; i< matrix.size(); i++)
    {
        for(size_t j = 0; j< matrix[i].size(); j++)
        {
            adj[i][j]/=det;
        }
    }
    return adj;
}
void PrintMatrix(vector<vector<long double>> matrix)
{
    for(vector<vector<long double>>::iterator itr1=matrix.begin();itr1!=matrix.end();itr1++)
    {
        for(vector<long double>::iterator itr2=itr1->begin();itr2!=itr1->end();itr2++)
        {
            cout << *itr2 << ends;
        }
        cout << endl;
    }
}