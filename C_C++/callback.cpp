#include <iostream>
#include <cstdlib>
#include <cstdarg>
using namespace std;
void println() {cout<<endl;}
template<typename First, typename ... Strings>
void println(First arg, const Strings&... rest) {
    cout<<arg;
    println(rest...);
}
int main() {
    println("Hello"," ", 5," ","World");
    return 0;
}
