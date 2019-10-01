#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
using p = pair<string,int>;
int main(int argc, char const *argv[])
{
    map<string,int> m;
    m.insert(p("Hello",5));
    m.insert(p("C++",7));
    m.insert(p("And",9));
    m.insert(p("World",11));
    for_each(m.begin(),m.end(),[](pair<string,int> a){cout<<a.first << " " << a.second<<ends;});
    cout<<m.at("C++");
    return 0;
}
