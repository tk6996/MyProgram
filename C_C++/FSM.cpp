#include<iostream>
using namespace std;
class playing;
void Tflipflop(int* state,int input)
{
    if(*state==0)
    {
        if(input==1)
        *state = 1;
    }
    else if(*state==1)
    {
        if(input==0)
        *state=0;
    }
}
int main(int argc, char const *argv[])
{
    int state=0,input;
    while(true)
    {
        cin >> input ;
        Tflipflop(&state,input%2);
         state ? cout << "odd" : cout << "even" ;
         cout << endl;
    }
    return 0;
}