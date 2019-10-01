interface Stack<T>{
    void push(T data);
    T pop();
    T top();
    boolean isFull();
    boolean isEmpty();
    int getSize();
}
public class StackImpArray<T> implements Stack<T>
{
    public static final int CAPACITY = 16;
    private Object[] items;
    private int size = 0;
    public StackImpArray()
    {
        items = new Object[CAPACITY];
    }
    @Override
    public void push(T data) {
        if(!isFull())
        {
            items[size++] = (Object) data;
        }
        else
        {
            System.out.println("Stack is Full");
        }
    }

    @Override
    public T pop() {
        if(!isEmpty())
        {
            return (T) items[--this.size];
        }
        else
        {
            System.out.println("Stack is Empty");
            return null;
        }
    }

    @Override
    public T top() {
        if(!isEmpty())
        {
            return (T) items[size-1];
        }
        else
        {
            System.out.println("Stack is Empty");
            return null;
        }
    }

    @Override
    public boolean isFull() {
        return size == CAPACITY;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public int getSize() {
        return size;
    }
    public static void main(String[] args) {
        StackImpArray<Integer> S = new StackImpArray<Integer>();
        System.out.println(S.isFull()+" "+S.isEmpty());
        S.push(4);
        S.push(7);
        S.push(11);
        S.push(1);
        S.push(74);
        System.out.println(S.top());
        S.push(9);
        while (!S.isEmpty()) {
            System.out.println(S.pop());
        }
    }
}