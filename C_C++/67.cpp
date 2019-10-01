#include<iostream>
using namespace std;
int main()
{
    int n,m,q,o;
    cin>>n>>m;
    q=m-n*2;
    o=q/2;
    if(o<=q&&q%2==0)
    cout<<o<<endl<<n-o;
    else cout<<"Impossible";
}