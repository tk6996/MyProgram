#include<iostream>
using namespace std;
int main()
{
    int m=0,n=0,x=0,y=0,sum=0;
    cout<<"Borrow book       Enter :1"<<endl;
    cout<<"Don't Borrow book Enter :2"<<endl;
    cout<<"Sum up            Enter :0"<<endl<<endl;
    do
    {
        m=m+1;
        cout<<m<<".Enter Number = ";
        cin>>n;

            if(n==1)
                x=x+1;
            if(n==2)
                y=y+1;
            if(n<0||n>2)
                cout<<"Error!!"<<endl;
    }while(n!=0);
    cout<<endl;
    cout<<"Borrow = "<<x<<endl;
    cout<<"Don't Borrow = "<<y<<endl;
    sum=x+y;
    cout<<"People amount = "<<sum<<endl;
    return 0;
}
