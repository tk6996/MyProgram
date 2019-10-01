public class MyArrayList<T extends Object> implements MyList<T> {
    private Object[] container;
    private int size;
    private int capacity = 1;
    
    public MyArrayList() {
        container = new Object[capacity];
    }

    @Override
    public void addHead(T data) {
        insert(0, data);
    }

    @Override
    public void addTail(T data) {
        insert(size, data);
    }

    @Override
    public boolean contains(T data) {
        for (int i = 0; i < size ; i++) {
            if(data == (T)container[i])
                return true;
        }
        return false;
    }

    @Override
    public T delete(int index) {
        T val = null;
        if(index >= 0 && index < size)
        {
            val = (T)container[index];
            System.arraycopy(container,index+1,container,index,size - index - 1);
            size--;
        }
        return val;
    }

    @Override
    public int getSize() {
        return size;
    }

    @Override
    public T get(int index) {
        if (index >= 0 && index < size)
            return (T) container[index];
        else
            return null;
    }

    @Override
    public int indexOf(T data) {
        for (int i = 0; i < size ; i++) {
            if(data == (T)container[i])
                return i;
        }
        return -1;
    }

    @Override
    public void insert(int index, T data) {
        if(index >= 0 && index <= size)
        {
            if (size == capacity) {
                capacity *= 2;
                Object temp[] = new Object[capacity];
                System.arraycopy(container,0,temp,0,size);
                container = temp;
            }
            System.arraycopy(container,index,container,index+1,size - index);
            container[index] = data;
            size++;
        }
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public boolean remove(T data) {
        return delete(indexOf(data)) != null;
    }

    @Override
    public T removeHead() {
        return delete(0);
    }

    @Override
    public T removeTail() {
        return delete(size - 1);
    }

    @Override
    public boolean removeLast(T data) {
        for (int i = size - 1; i >= 0; i--) {
            if(data == (T)container[i])
            {
                delete(i);
                return true;
            }
        }
        return false;
    }

    @Override
    public void set(int index, T data) {
        if (index >= 0 && index < size)
            container[index] = data;
    }

    @Override
    public String toString() {
        StringBuilder sBuilder = new StringBuilder();
        for(int i = 0; i < size ; i++) {
            sBuilder.append(((T)container[i]).toString()).append(" ");
        }
        return sBuilder.toString();
    }

    public static void main(String[] args) {
        MyList<Integer> list = new MyArrayList<Integer>();
        list.addHead(3);
        System.out.println(list + " size = " + list.getSize());
        list.addHead(5);
        System.out.println(list + " size = " + list.getSize());        
        list.addTail(7);
        System.out.println(list + " size = " + list.getSize());
        list.insert(1, 4);
        System.out.println(list + " size = " + list.getSize());
        list.insert(2, 11);
        System.out.println(list + " size = " + list.getSize());
        list.addHead(7);
        System.out.println(list + " size = " + list.getSize());
        list.delete(3);
        System.out.println(list + " size = " + list.getSize());
        list.addTail(77);
        System.out.println(list + " size = " + list.getSize());
        System.out.println(list + " remove = "+ list.removeHead() +" size = " + list.getSize());
    }
}