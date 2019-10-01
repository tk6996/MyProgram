#include<iostream>
using namespace std;
int main()
{
    int n;
    cout <<"Enter Number : ";
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>n-i) cout << "*";
            else cout << " ";
        }
        for(int k=i;k>1;k--) cout << '*';
        cout << endl;
    }
}