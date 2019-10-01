public class MySinglyLinkedList<T> implements MyList<T> {

    private class Node {
        private T data;
        private Node next;

        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }

        public Node(T data) {
            this(data, null);
        }

        public T getData() {
            return data;
        }

        public void setData(T data) {
            this.data = data;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node next) {
            this.next = next;
        }

    }

    private Node head;
    private Node tail;
    private int size;

    @Override
    public void addHead(T data) {
        head = new Node(data, head);
        if (tail == null)
            tail = head;
        size++;
    }

    @Override
    public void addTail(T data) {
        if (tail == null)
            addHead(data);
        else {
            tail.setNext(new Node(data));
            tail = tail.getNext();
            size++;
        }
    }

    @Override
    public boolean contains(T data) {
        Node ptr = head;
        while (ptr != null) {
            if (ptr.getData() == data)
                return true;
            ptr = ptr.getNext();
        }
        return false;
    }

    @Override
    public T delete(int index) {
        T val = null;
        if (index >= 0 && index < size) {
            Node prev = getNodePrev(index);
            if (prev != null) {
                val = prev.getNext().getData();
                if (prev.getNext() == tail)
                    tail = prev;
                prev.setNext(prev.getNext().getNext());
            } else {
                val = head.getData();
                head = head.getNext();
                if (head == null)
                    tail = null;
            }
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
        T val = null;
        if (index == 0)
            val = head.getData();
        else if (index > 0 && index < size)
            val = getNodePrev(index).getNext().getData();
        return val;
    }

    private Node getNodePrev(int index) {
        if (index == 0 || index >= size)
            return null;
        else {
            Node prev = head;
            while (--index > 0) {
                prev = prev.getNext();
            }
            return prev;
        }
    }

    @Override
    public int indexOf(T data) {
        Node ptr = head;
        int index = 0;
        while (ptr != null) {
            if (ptr.getData() == data)
                return index;
            ptr = ptr.getNext();
            index++;
        }
        return -1;
    }

    @Override
    public void insert(int index, T data) {
        if (index == 0)
            addHead(data);
        else if (index == size)
            addTail(data);
        else if (index > 0 && index < size) {
            Node prev = getNodePrev(index);
            prev.setNext(new Node(data, prev.getNext()));
            size++;
        }
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public boolean remove(T data) {
        Node ptr = head;
        Node prev = null;
        while (ptr != null) {
            if (ptr.getData() == data) {
                if (prev == null) {
                    head = head.getNext();
                    if (head == null)
                        tail = null;
                } else {
                    if (ptr == tail)
                        tail = prev;
                    prev.setNext(ptr.getNext());
                }
                size--;
                return true;
            }
            prev = ptr;
            ptr = ptr.getNext();
        }
        return false;
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
        Node ptr = head;
        Node prev = null;
        Node delprev = null;
        boolean del = false;
        while (ptr != null) {
            if (ptr.getData() == data)
            {
                del = true;
                delprev = prev;
            }
            prev = ptr;
            ptr = ptr.getNext();
        }
        if (del) {
            if (delprev == null) {
                head = head.getNext();
                if (head == null)
                    tail = null;
            } 
            else {
                if (delprev.getNext() == tail)
                    tail = delprev;
                delprev.setNext(delprev.getNext().getNext());
            }
            size--;
            return true;
        }
        else
            return false;
    }

    @Override
    public void set(int index, T data) {
        if (index == 0)
            head.setData(data);
        else if (index > 0 && index < size)
            getNodePrev(index).getNext().setData(data);
    }

    @Override
    public String toString() {
        StringBuilder sBuilder = new StringBuilder();
        Node temp = head;
        while (temp != null) {
            sBuilder.append(temp.getData().toString()).append(" ");
            temp = temp.getNext();
        }
        return sBuilder.toString();
    }

    public static void main(String[] args) {
        MyList<Integer> list = new MySinglyLinkedList<Integer>();
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