#include <iostream>
using namespace std;
int main ()
{
    int x;
    do{
       cout<<"Please select  choice :";
       cin>>x;
       if(x==1)
         cout<<"1.Plus        (+)"<<endl;
       if(x==2)
         cout<<"2.Minus       (-)"<<endl;
       if(x==3)
         cout<<"3.Multiply    (*)"<<endl;
       if(x==4)
         cout<<"4.Divide      (/)"<<endl;
       if(x==5)
         cout<<"5.Power          "<<endl;
    }while(x<=1||x>=5);
        return 0;
}
