#include<iostream>
using namespace std;
class A
{
public :     
    virtual void f()=0;
};
class B : public A
{
public : 
    void f()
    {
        cout<<"class 2";
    }
};
class C : public B
{
public :
    void f()
    {
        cout<<"class 3";
    }
};
int main(int argc, char const *argv[])
{
    //A *a = new A();
    B *b = new B();
    B *c = new C();
    //a->f();
    //cout<<endl;
    b->f();
    cout<<endl;
    c->f();
    return 0;
}
