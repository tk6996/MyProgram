public class MyDoublyLinkedList<T> implements MyList<T> {
    private class Node {
        private T data;
        private Node next;
        private Node prev;

        public Node(T data, Node next, Node prev) {
            this.data = data;
            this.next = next;
            this.prev = prev;
        }

        public Node(T data) {
            this(data, null, null);
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

        public Node getPrev() {
            return prev;
        }

        public void setPrev(Node prev) {
            this.prev = prev;
        }

    }

    private Node head;
    private Node tail;
    private int size;

    @Override
    public void addHead(T data) {
        if (head == null) {
            tail = head = new Node(data);
        } else {
            head = new Node(data, head, null);
            head.getNext().setPrev(head);
        }
        size++;
    }

    @Override
    public void addTail(T data) {
        if (tail == null) {
            tail = head = new Node(data);
        } else {
            tail = new Node(data, null, tail);
            tail.getPrev().setNext(tail);
        }
        size++;
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
        if (index >= 0 && index < size) {
            Node temp = getNode(index);
            if (temp.getPrev() != null)
                temp.getPrev().setNext(temp.getNext());
            else
                head = temp.getNext();
            if (temp.getNext() != null)
                temp.getNext().setPrev(temp.getPrev());
            else
                tail = temp.getPrev();
            size--;
            return temp.getData();
        } else
            return null;
    }

    @Override
    public int getSize() {
        return size;
    }

    @Override
    public T get(int index) {
        return getNode(index).getData();
    }

    private Node getNode(int index) {
        Node ptr = null;
        if (index >= 0 && index < size) {
            if (size - index > index) {
                ptr = head;
                while (index-- > 0) {
                    ptr = ptr.getNext();
                }
            } else {
                ptr = tail;
                index = size - index;
                while (--index > 0) {
                    ptr = ptr.getPrev();
                }
            }
        }
        return ptr;
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
        if (index == size)
            addTail(data);
        else if (index == 0)
            addHead(data);
        else if (index > 0 && index < size) {
            Node temp = getNode(index);
            temp = new Node(data, temp, temp.getPrev());
            temp.getPrev().setNext(temp);
            temp.getNext().setPrev(temp);
            size++;
        }
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public boolean remove(T data) {
        Node temp = head;
        while (temp != null) {
            if (temp.getData() == data) {
                if (temp.getPrev() != null)
                    temp.getPrev().setNext(temp.getNext());
                else
                    head = temp.getNext();
                if (temp.getNext() != null)
                    temp.getNext().setPrev(temp.getPrev());
                else
                    tail = temp.getPrev();
                size--;
                return true;
            }
            temp = temp.getNext();
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
        Node temp = tail;
        while (temp != null) {
            if (temp.getData() == data) {
                if (temp.getPrev() != null)
                    temp.getPrev().setNext(temp.getNext());
                else
                    head = temp.getNext();
                if (temp.getNext() != null)
                    temp.getNext().setPrev(temp.getPrev());
                else
                    tail = temp.getPrev();
                size--;
                return true;
            }
            temp = temp.getPrev();
        }
        return false;
    }

    @Override
    public void set(int index, T data) {
        getNode(index).setData(data);
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
        MyList<Integer> list = new MyDoublyLinkedList<Integer>();
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