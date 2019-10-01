#include<iostream>
using namespace std;
int main()
{
    int n,win=0,lose=0,draw=0,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if((x==0&&y==2)||(x==2&&y==5)||(x==5&&y==0)) win++;
        if((x==2&&y==0)||(x==5&&y==2)||(x==0&&y==5)) lose++;
        if((x==0&&y==0)||(x==2&&y==2)||(x==5&&y==5)) draw++;
    }
    cout<<"Win : "<<win<<endl<<"Lose : "<<lose<<endl<<"Draw : "<<draw;
}
