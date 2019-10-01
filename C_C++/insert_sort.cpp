// insert - sort
#include <iostream>
#include <vector>
using namespace std;
int main(int argc,char* argv[])
{
    vector <int> num,lesstomore;
    int n=1;
    while(n)
    {
        cin >> n;
        if(n)
        {
        num.push_back(n);
        }
    }
    
    for(int i=0;i<num.size();i++)
    {
        int k;
        lesstomore.push_back(0);
        for(k=i;k>0;k--)
        {
            lesstomore[k] = lesstomore[k-1];
            if(num[i]>lesstomore[k-1]) break;
        }
        lesstomore[k] = num[i];
    }
    for(auto i =lesstomore.begin() ; i!=lesstomore.end();i++)
    {
        cout << *i << " ";
    }
    return 0;
}