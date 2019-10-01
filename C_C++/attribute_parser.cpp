#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;
struct Tag {
  vector<Tag *> next;
  string name;
  unordered_map<string, string> data;
  ~Tag(){
    while(!next.empty())
    {
      delete next.back();
      next.pop_back();
    }
  }
};
vector<Tag *> root;
void expression(string command) {
  command = command.substr(command.find('<')+1,command.find('>')-(command.find('<')+1));
  // cout << command << endl;
  if (command[0] != '/') {
    stringstream ss(command);
    Tag *tag = new Tag();
    ss >> tag->name;
    while (!ss.eof()) {
      string attribute_name, equal, value;
      ss >> attribute_name >> equal >> value;
      tag->data.insert({attribute_name, value.substr(1, value.length() - 2)});
      // cout << tag->name << ' ' << attribute_name << ' ' <<
      // tag->data[attribute_name] << endl;
    }
    root.back()->next.push_back(tag);
    root.push_back(tag);
  }
  else {
      command.erase(command.begin());
      auto tag = find_if(root.begin(), root.end(), [command](Tag* cur)->bool{
          return cur->name == command;
      });
      if(tag != root.end()) root.erase(tag);
  }
}
string interact(string ref)
{
  char at = 0;
  Tag* ptr = root.back();
  do
  {
    int ind = ref.find_first_of(".~");
    string tag = ref.substr(0,ind);
    auto access = find_if(ptr->next.begin(),ptr->next.end(),[tag](Tag* cur)->bool{return cur->name == tag;});
    if(access == ptr->next.end()) return "Not Found!";
    ptr = *access;
    //cout << tag << endl;
    at = ref.at(ind);
    ref = ref.substr(ind+1);
  } while (at != '~');
  return  ptr->data[ref] != "" ? ptr->data[ref] : "Not Found!";
}
int main() {
  int N, Q;
  root.push_back(new Tag());
  cin >> N >> Q;
  getchar();
  for (int i = 0; i < N; ++i) {
    string rl;
    getline(cin, rl);
    expression(rl); 
  }
  for(int i =0 ; i < Q; ++i)
  {
    string rl;
    getline(cin, rl);
    cout << interact(rl) << endl;
  }
  delete root.back();
  return 0;
}