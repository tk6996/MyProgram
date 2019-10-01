#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            //map the key to the node in the linked list
    int cp;                         //capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0;       //get function
};
class LRUCache : public Cache
{
public:
    LRUCache(int capacity = 5) { cp = capacity; head = NULL;tail = NULL;}
    virtual void set(int key, int val)
    {
        Node *node = new Node(key, val);
        mp[key] = node;
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
            if (mp.size() > cp)
            {
                mp.erase(tail->key);
                Node *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }
    }
    virtual int get(int a)
    {
        auto cur = mp.find(a);
        if (cur != mp.end())
            {
                if(cur->second == head || cur->second == tail)
                {
                    if(cur->second == head){
                        return cur->second->value;        
                    }
                    else
                    {
                        tail = tail->prev;
                        if(!tail) tail->next = NULL;
                    }
                }
                else
                {
                    cur->second->prev->next = cur->second->next;
                    cur->second->next->prev = cur->second->prev; 
                }
                int k = cur->first,v = cur->second->value;
                mp.erase(cur);
                set(k,v);
                return cur->second->value;
            }
        else
            return -1;
    }
};
int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}