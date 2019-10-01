interface MyList<T> {
    void addHead(T data);

    void addTail(T data);

    boolean contains(T data);

    T delete(int index);

    int getSize();

    T get(int index);

    int indexOf(T data);

    void insert(int index, T data);

    boolean isEmpty();

    boolean remove(T data);

    T removeHead();

    T removeTail();

    boolean removeLast(T data);

    void set(int index, T data);
}