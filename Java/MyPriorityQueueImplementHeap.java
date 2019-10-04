import java.util.Comparator;

public class MyPriorityQueueImplementHeap<T> implements MyPriorityQueue<T> {

    private class Node {
        private T data;
        private Node left;
        private Node right;

        public Node(T data) {
            this.data = data;
        }

        public T getData() {
            return data;
        }

        public void setData(T data) {
            this.data = data;
        }

        public Node getLeft() {
            return left;
        }

        public void setLeft(Node left) {
            this.left = left;
        }

        public Node getRight() {
            return right;
        }

        public void setRight(Node right) {
            this.right = right;
        }

        public int getSize() {
            return ((this.left != null) ? this.left.getSize() : 0) + 1
                    + ((this.right != null) ? this.right.getSize() : 0);
        }
        public int getMinHeight(){
            if (this.left == null || this.right == null)
                return 0;
            else
                return this.right.getMinHeight() < this.left.getMinHeight() ? this.right.getMinHeight() + 1 : this.left.getMinHeight() + 1 ;
        }
    }

    private Comparator<? super T> comparator;

    private Node root;

    public MyPriorityQueueImplementHeap(Comparator<? super T> c) {
        comparator = c;
    }

    @Override
    public void add(T data) {
        if (root == null) {
            root = new Node(data);
        } else {
            addheapify(root, data);
        }
    }

    private boolean addheapify(Node parent, T data) {
        if (parent.getMinHeight() > 0) {
            if (parent.getLeft().getMinHeight() > parent.getRight().getMinHeight()) {
                if (addheapify(parent.getRight(), data)) {
                    boolean c = comparator.compare(parent.getData(), parent.getRight().getData()) < 0;
                    if (c) {
                        T temp = parent.getData();
                        parent.setData(parent.getRight().getData());
                        parent.getRight().setData(temp);
                    }
                    return c;
                } else
                    return false;
            } else {
                if (addheapify(parent.getLeft(), data)) {
                    boolean c = comparator.compare(parent.getData(), parent.getLeft().getData()) < 0;
                    if (c) {
                        T temp = parent.getData();
                        parent.setData(parent.getLeft().getData());
                        parent.getLeft().setData(temp);
                    }
                    return c;
                } else
                    return false;
            }
        } else if (parent.getLeft() == null) {
            parent.setLeft(new Node(data));
            boolean c = comparator.compare(parent.getData(), parent.getLeft().getData()) < 0;
            if (c) {
                T temp = parent.getData();
                parent.setData(parent.getLeft().getData());
                parent.getLeft().setData(temp);
            }
            return c;
        } else {
            parent.setRight(new Node(data));
            boolean c = comparator.compare(parent.getData(), parent.getRight().getData()) < 0;
            if (c) {
                T temp = parent.getData();
                parent.setData(parent.getRight().getData());
                parent.getRight().setData(temp);
            }
            return c;
        }
    }

    @Override
    public boolean contains(T data) {
        return getNode(data) != null;
    }

    private Node getNode(T data) {

        int maxSize = 1;
        Object[] queue = new Object[maxSize];
        queue[0] = root;
        while (queue[0] != null) {
            Object[] temp = new Object[maxSize <<= 1];
            int index = 0;
            for (Object o : queue) {
                Node n = (Node) o;
                if (n == null)
                    break;
                else {
                    if (n.getData().equals(data))
                        return n;
                    else {
                        if (n.getLeft() != null)
                            temp[index++] = n.getLeft();
                        if (n.getRight() != null)
                            temp[index++] = n.getRight();
                    }
                }
            }
            queue = temp;
        }
        return null;
    }

    @Override
    public boolean isEmpty() {
        return root == null;
    }

    private void heapify(Node root) {
        if (root != null) {
            boolean lheap, rheap;
            if (root.getLeft() != null && comparator.compare(root.getData(), root.getLeft().getData()) < 0) {
                lheap = true;
                T temp = root.getData();
                root.setData(root.getLeft().getData());
                root.getLeft().setData(temp);
            } else
                lheap = false;
            if (root.getRight() != null && comparator.compare(root.getData(), root.getRight().getData()) < 0) {
                rheap = true;
                T temp = root.getData();
                root.setData(root.getRight().getData());
                root.getRight().setData(temp);
            } else
                rheap = false;
            if (lheap)
                heapify(root.getLeft());
            if (rheap)
                heapify(root.getRight());
        }

    }

    @Override
    public boolean remove(T data) {
        Node curr = getNode(data);
        if (curr != null) {
            removeTop(curr);
            return true;
        } else
            return false;
    }

    private T removeLast(Node parent) {
        if (parent == null)
            return null;
        T data;
        while (parent.getMinHeight() > 1) {
            if (parent.getLeft().getMinHeight() > parent.getRight().getMinHeight())
                parent = parent.getLeft();
            else
                parent = parent.getRight();
        }
        if (parent.getRight() != null) {
            data = parent.getRight().getData();
            parent.setRight(null);
        } else if (parent.getLeft() != null) {
            data = parent.getLeft().getData();
            parent.setLeft(null);
        } else {
            data = root.getData();
            if (root == parent)
                root = null;
            parent = null;
        }
        return data;
    }

    private T removeTop(Node root) {
        T data = root.data;
        root.setData(removeLast(root));
        heapify(root);
        return data;
    }

    @Override
    public T peek() {
        return root.data;
    }

    @Override
    public T poll() {
        return removeTop(root);
    }

    @Override
    public int getSize() {
        return root.getSize();
    }

    @Override
    public String toString() {
        StringBuilder sBuilder = new StringBuilder();
        int maxSize = 1;
        Object[] queue = new Object[maxSize];
        queue[0] = root;
        while (queue[0] != null) {
            Object[] temp = new Object[maxSize <<= 1];
            int index = 0;
            for (Object o : queue) {
                Node n = (Node) o;
                if (n == null)
                    break;
                else {
                    sBuilder.append(n.getData().toString()).append(" ");
                    if (n.getLeft() != null)
                        temp[index++] = n.getLeft();
                    if (n.getRight() != null)
                        temp[index++] = n.getRight();
                }
            }
            sBuilder.append("\n");
            queue = temp;
        }
        return sBuilder.toString();
    }

    public static void main(String[] args) {
        MyPriorityQueue<Integer> p = new MyPriorityQueueImplementHeap<Integer>((Integer data1, Integer data2) -> {
            return data2.compareTo(data1);
        });
        for (int i = 0; i < 40; i++) {
            p.add(i);
        }
        System.out.println(p);
        for (int i = 0; i < 40; i++) {
            System.out.println(p.poll());
        }
    }
}