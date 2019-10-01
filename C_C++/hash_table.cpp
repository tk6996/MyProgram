#include <new>
#include <functional>
#include <exception>
#include <iostream>
#include <map>
#undef __cpp_deduction_guides
template <typename Key, typename Value>
class HashTable
{
private:
    static const std::size_t DEFAULT_CAPACITY = 16U;
    Value defaultValue = NULL;
    template <typename K, typename V>
    struct HashNode
    {
        static inline std::size_t count = 0U;
        HashNode *next;
        const K &key;
        V &value;
        HashNode(const K &k, V &v) : key(k), value(v), next(NULL) { ++count; };
        ~HashNode() { --count; }
    };
    HashNode<Key, Value> **table;
    std::size_t (*hashFuncPtr)(const Key &);
    std::function<std::size_t(const Key &)> hashFuncObj;
    std::size_t tableSize;
    std::size_t hashKey(const Key &key)
    {
        return hashFuncPtr != NULL ? hashFuncPtr(key) % tableSize : hashFuncObj(key) % tableSize;
    }

public:
    HashTable(std::size_t (*hashFuncPtr)(const Key &), std::size_t tableSize = DEFAULT_CAPACITY) : hashFuncPtr(hashFuncPtr), tableSize(tableSize), hashFuncObj([](const Key &key) -> std::size_t { return reinterpret_cast<std::size_t>(&key); })
    {
        table = new HashNode<Key, Value> *[tableSize]();
    }
    HashTable(std::function<std::size_t(Key)> hashFuncObj = [](const Key &key) -> std::size_t { return reinterpret_cast<std::size_t>(&key); }, std::size_t tableSize = DEFAULT_CAPACITY) : hashFuncPtr(NULL), tableSize(tableSize), hashFuncObj(hashFuncObj)
    {
        table = new HashNode<Key, Value> *[tableSize]();
    }
    ~HashTable()
    {
        clear();
        delete[] table;
    }
    HashTable<Key, Value>& operator=(const HashTable<Key, Value> &other)
    {
        if (this != &other)
        {
            this->defaultValue = other.defaultValue;
            this->hashFuncPtr = other.hashFuncPtr;
            this->hashFuncObj = other.hashFuncObj;
            if (this->tableSize != other.tableSize)
            {
                this->tableSize = other.tableSize;
                clear();
                delete[] this->table;
                this->table = new HashNode<Key, Value> *[tableSize]();
            }
            for (std::size_t i = 0; i < tableSize; ++i)
            {
                if(other.table[i] != NULL)
                {
                    HashNode<Key,Value>* ptr = other.table[i];
                    HashNode<Key,Value>* this_ptr = this->table[i] = new HashNode<Key,Value>(ptr->key,ptr->value);
                    while (ptr->next != NULL)
                    {
                        ptr = ptr->next;
                        this_ptr = this_ptr->next = new HashNode<Key,Value>(ptr->key,ptr->value);
                    }
                }
                else
                    this->table[i] = NULL;
            }
        }
        return *this;
    }
    
    void append(const Key &key, const Value &value)
    {
        std::size_t hashNumber = hashKey(key);
        if (table[hashNumber] == NULL)
        {
            table[hashNumber] = new HashNode<Key, Value>(key, const_cast<Value &>(value));
            return;
        }
        HashNode<Key, Value> *ptr = table[hashNumber];
        while (ptr->key != key && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->key == key)
            ptr->value = value;
        else
            ptr->next = new HashNode<Key, Value>(key, const_cast<Value &>(value));
    }
    Value &remove(const Key &key)
    {
        std::size_t hashNumber = hashKey(key);
        if (table[hashNumber] == NULL)
            return defaultValue;
        HashNode<Key, Value> *ptr = table[hashNumber];
        HashNode<Key, Value> *pre = NULL;
        while (ptr->key != key && ptr->next != NULL)
        {
            pre = ptr;
            ptr = ptr->next;
        }
        if (ptr->key == key)
        {
            Value &temp = ptr->value;
            if (pre != NULL)
                pre->next = ptr->next;
            else
                table[hashNumber] = ptr->next;
            delete ptr;
            return temp;
        }
        else
            return defaultValue;
    }
    Value &operator[](const Key &key)
    {
        std::size_t hashNumber = hashKey(key);
        if (table[hashNumber] == NULL)
        {
            append(key, defaultValue);
            return defaultValue;
        }
        HashNode<Key, Value> *ptr = table[hashNumber];
        while (ptr->key != key && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->key == key)
            return ptr->value;
        else
        {
            append(key, defaultValue);
            return defaultValue;
        }
    }
    Value &at(const Key &key)
    {
        std::size_t hashNumber = hashKey(key);
        if (table[hashNumber] == NULL)
            throw std::out_of_range("key is not element");
        HashNode<Key, Value> *ptr = table[hashNumber];
        while (ptr->key != key && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->key == key)
            return ptr->value;
        else
            throw std::out_of_range("key is not element");
    }
    bool find(const Key &key)
    {
        std::size_t hashNumber = hashKey(key);
        if (table[hashNumber] == NULL)
            return false;
        HashNode<Key, Value> *ptr = table[hashNumber];
        while (ptr->key != key && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->key == key)
            return true;
        else
        {
            return false;
        }
    }
    bool empty()
    {
        for (std::size_t i = 0; i < tableSize; ++i)
        {
            if (table[i])
                return false;
        }
        return true;
    }
    std::size_t count()
    {
        return HashNode<Key, Value>::count;
    }
    std::size_t getsize()
    {
        return tableSize;
    }
    void clear()
    {
        for (std::size_t i = 0; i < tableSize; ++i)
        {
            HashNode<Key, Value> *ptr = table[i];
            while (ptr != NULL)
            {
                HashNode<Key, Value> *temp = ptr;
                ptr = ptr->next;
                delete temp;
            }
            table[i] = NULL;
        }
    }
};
int main()
{
    HashTable<std::string &, int> h;
    std::string &a = *new std::string("hello");
    std::string b = "World";
    std::cout << h.count() << std::endl;
    h.append(a, 5);
    std::cout << h.count() << std::endl;
    h[b] = 5;
    std::cout << h.count() << std::endl;
    HashTable<std::string &, int> hh = h;
    h.clear();
    std::cout << hh.count() << std::endl;
    std::cout << hh[b] << std::endl;
    delete &a;
    return 0;
}