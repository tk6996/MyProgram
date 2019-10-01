#include<iostream>
using namespace std;
int main()
{
    int temp,i,co=0,ci=0,j,x=0,y=0,n,d,a[1000],b[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>d;
        if(d>=0) {a[x]=d; x++;co++;}
        if(d<0) {b[y]=d; y++;ci++;}
    }
    //bubble sort
    for(j=0;j<x-1;j++)
    for(i=0;i<x-1;i++)
    {
        if(a[i]<a[i+1]) {temp=a[i];a[i]=a[i+1];a[i+1]=temp;}
    }
    for(j=0;j<y-1;j++)
    for(i=0;i<y-1;i++)
    {
        if(b[i]>b[i+1]) {temp=b[i];b[i]=b[i+1];b[i+1]=temp;}
    }
    /*for(int j=0;j<x;j++) cout<<a[j]<<" ";
    cout<<endl;
    for(int j=0;j<y;j++) cout<<b[j]<<" ";*/
    int A1,A2,A3,A4,Min;
    if(co>2){A1=a[x-1]*a[x-2]*a[x-3];Min=A1;} 
    if(co>1&&ci>0){A2=a[0]*a[1]*b[0];if(Min>A2) Min=A2;}
    if(co>0&&ci>1){A3=a[x-1]*b[y-1]*b[y-2];if(Min>A3) Min=A3;}
    if(ci>2){A4=b[0]*b[1]*b[2]; if(Min>A4) Min=A4;}
    cout<<Min;
}
