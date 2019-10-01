#include <iostream>
#include <functional>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T data, Node<T> *next = nullptr) : data(data), next(next) {}
};
template <typename T>
class Iteration
{
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};
template <typename T>
class IterationList : public Iteration<T>
{
    Node<T> *current;
public:
    IterationList(Node<T> *collection) : current(collection) {}
    T next()
    {
        T temp = current->data;
        current = current->next;
        return temp;
    }
    bool hasNext()
    {
        return current;
    }
};
template <typename T>
class List
{
    Node<T> *head;
public:
    List(Node<T> *head = nullptr) : head(head) {}
    Node<T> *getHead() const { return head; }
    void setHead(Node<T> *head) { this->head = head; }
    IterationList<T> iteration() { return IterationList<T>(this->head); }
    int size() const
    {
        Node<T> *ptr = head;
        int size = 0;
        while (ptr)
        {
            ptr = ptr->next;
            size++;
        }
        return size;
    }
    void insert(T data, int index = -1)
    {
        const int len = size();
        if (index < 0)
            index += len + 1;
        if (index >= 0 && index <= len)
        {
            if (index)
            {
                Node<T> *ptr = head;
                int round = len;
                while (--round > 0)
                {
                    ptr = ptr->next;
                }
                ptr->next = new Node<T>(data, ptr->next);
            }
            else
            {
                head = new Node(data, head);
            }
        }
        else
        {
            cerr << "Index Out Of Bound.\n";
        }
    }
    T remove(int index)
    {
        const int len = size();
        if (index < 0)
            index += len + 1;
    }
};

template <typename T>
class priorityQueueList
{
    function<bool(T, T)> compare;
    List<T> container;
};

int main()
{
    List<int> l;
    l.insert(4);
    l.insert(7);
    l.insert(47);
    l.insert(77);
    Iteration<int> &&iter = l.iteration();
    while (iter.hasNext())
    {
        cout << iter.next() << "\n";
    }

    return 0;
}
