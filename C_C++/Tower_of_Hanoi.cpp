#include<iostream>
#include<stack>
#include<functional>
#include<exception>
using namespace std;
int counter=0;
stack<char> A,B,C;
void show_current()
{
    function<string (stack<char>)> tower = [&tower](stack<char> t)->string {
        if(t.empty()) return "";
        const char val = t.top();
        t.pop();
        return tower(t).append(1,val);
    };
    cout<< "Tower A : "<< tower(A) << endl;
    cout<< "Tower B : "<< tower(B) << endl;
    cout<< "Tower C : "<< tower(C) << endl;
    cout<< "=========================="<<endl;
}
void tower_move(stack<char> &source,stack<char> &buffer,stack<char> &destination,int layer)
{
    if(layer<1) {
        if(layer<0) 
        {
            struct Minus_exception : public exception{
                const char * what () const throw ()
                {
    	            return "Minus Move Exception";
                }
            };
            throw Minus_exception();
        }
        return;
    }
    auto move_obj = [](stack<char> &source,stack<char> &destination){
        char temporary = source.top();
        source.pop();
        destination.push(temporary);
        show_current();
    };
    if(layer==1)
    {
        move_obj(source,destination);
        return;
    }
    tower_move(source,destination,buffer,layer-1);
    move_obj(source,destination);
    tower_move(buffer,source,destination,layer-1);
}
int main(int argc, char const *argv[])
{
    cout << "Tower Of Hanoi Enter Level : ";
    int level = 0;
    cin >> level;
    for(int i=level-1;i>=0;i--) A.push('A'+i);
    cout << "=========================="<<endl;
    show_current();
    try{
        tower_move(A,B,C,A.size());
    }
    catch(exception& e)
    {
        cerr<<e.what();
    }
    return 0;
}