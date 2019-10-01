#include <iostream>
#include <vector>
#include "Matrix.cpp"
using namespace std;
int main()
{
    vector<vector<long double>> A={{1.0,4.0,9.0},{0.0,8.0,5.0},{-9.0,11.0,7.0}};
    cout << Determinant(A)<<endl;
    PrintMatrix(A);
    PrintMatrix(Adjoint(A));
    return 0;
}