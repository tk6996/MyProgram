public interface MyPriorityQueue<T> {
    void add(T data);

    boolean contains(T data);

    boolean isEmpty();

    boolean remove(T data);

    T peek();

    T poll();

    int getSize();
}