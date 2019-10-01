#include<iostream>
using namespace std;
int main()
{
    int n,q,j=0,a[100];
    cin >> n;
    cin >> q;
    for(int i=0;i<q;i++)
    {

        if(n%2==0)
            a[i]=2+2*i;
        if(n%2==1)
            a[i]=1+2*i;
        j=j+a[i];
        cout<<a[i];
        if(i<q-1) cout<<" ";
        else cout<<endl;
    }
    cout<<j;
}
