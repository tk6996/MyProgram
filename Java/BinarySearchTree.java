import java.util.Comparator;

public class BinarySearchTree<T> {
    protected class TreeNode {
        private T data;
        private TreeNode left;
        private TreeNode right;

        public TreeNode(T data, TreeNode left, TreeNode right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }

        public TreeNode(T data) {
            this(data, null, null);
        }

        public T getData() {
            return data;
        }

        public void setData(T data) {
            this.data = data;
        }

        public TreeNode getLeft() {
            return left;
        }

        public void setLeft(TreeNode left) {
            this.left = left;
        }

        public TreeNode getRight() {
            return right;
        }

        public void setRight(TreeNode right) {
            this.right = right;
        }

        @Override
        public String toString() {
            return data.toString();
        }

        public int getHeight() {
            int leftHeight = left != null ? left.getHeight() : -1;
            int rightHeight = right != null ? right.getHeight() : -1;
            return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
        }

        public int getSize() {
            return ((this.left != null) ? left.getSize() : 0) + 1 + ((this.right != null) ? right.getSize() : 0);
        }

        public TreeNode rotateLeft() {
            TreeNode temp = right;
            if (temp != null) {
                this.setRight(this.getRight().getLeft());
                temp.setLeft(this);
                return temp;
            } else
                return this;
        }

        public TreeNode rotateRight() {
            TreeNode temp = left;
            if (temp != null) {
                this.setLeft(this.getLeft().getRight());
                temp.setRight(this);
                return temp;
            } else
                return this;
        }
    }

    protected TreeNode root;
    protected Comparator<? super T> comparator;

    protected TreeNode addNode(TreeNode root, T data) {
        if (root != null) {
            if (comparator.compare(data, root.getData()) < 0)
                root.setLeft(addNode(root.getLeft(), data));
            else
                root.setRight(addNode(root.getRight(), data));
        } else
            root = new TreeNode(data);
        return root;
    }

    public void add(T data) {
        this.root = addNode(this.root, data);
    }

    public BinarySearchTree(Comparator<? super T> comparator) {
        this.root = null;
        this.comparator = comparator;
    }

    public boolean contain(T data) {
        TreeNode temp = this.root;
        while (temp != null) {
            if (comparator.compare(data, temp.getData()) < 0)
                temp = temp.getLeft();
            else if (comparator.compare(data, temp.getData()) > 0)
                temp = temp.getRight();
            else
                return true;
        }
        return false;
    }

    protected TreeNode removeNode(TreeNode root, T data) {
        if (root != null) {
            if (comparator.compare(data, root.getData()) < 0)
                root.setLeft(removeNode(root.getLeft(), data));
            else if (comparator.compare(data, root.getData()) > 0)
                root.setRight(removeNode(root.getRight(), data));
            else {
                if (root.getLeft() != null && root.getRight() != null) {
                    if (root.getLeft().getHeight() > root.getRight().getHeight()) {
                        TreeNode temp = root.getLeft();
                        while (temp.getRight() != null)
                            temp = temp.getRight();
                        root.setData(temp.getData());
                        root.setLeft(removeNode(root.getLeft(), root.getData()));
                    } else {
                        TreeNode temp = root.getRight();
                        while (temp.getLeft() != null)
                            temp = temp.getLeft();
                        root.setData(temp.getData());
                        root.setRight(removeNode(root.getRight(), root.getData()));
                    }
                } else if (root.getLeft() != null)
                    root = root.getLeft();
                else
                    root = root.getRight();
            }
        }
        return root;
    }

    public boolean remove(T data) {
        if (contain(data)) {
            this.root = removeNode(this.root, data);
            return true;
        } else
            return false;
    }

    public int getSize() {
        return this.root.getSize();
    }

    public T[] inOrder() {
        Object[] array = new Object[getSize()];
        OrderNode(this.root, array, 0, 0);
        return (T[]) array;
    }

    public T[] preOrder() {
        Object[] array = new Object[getSize()];
        OrderNode(this.root, array, 0, -1);
        return (T[]) array;
    }

    public T[] postOrder() {
        Object[] array = new Object[getSize()];
        OrderNode(this.root, array, 0, 1);
        return (T[]) array;
    }

    public T[] levelOrder() {
        Object[] array = new Object[getSize()];
        int maxSize = 1;
        int pos = 0;
        Object[] queue = new Object[maxSize];
        queue[0] = root;
        while (queue[0] != null) {
            Object[] temp = new Object[maxSize <<= 1];
            int index = 0;
            for (Object o : queue) {
                TreeNode n = (TreeNode) o;
                if (n == null)
                    break;
                else {
                    array[pos++] = n;
                    if (n.getLeft() != null)
                        temp[index++] = n.getLeft();
                    if (n.getRight() != null)
                        temp[index++] = n.getRight();
                }
            }
            queue = temp;
        }
        return (T[]) array;
    }

    private int OrderNode(TreeNode root, Object[] array, int pos, int pattern) {
        if (root != null) {

            if (pattern == -1)
                array[pos++] = root.getData();
            pos = OrderNode(root.getLeft(), array, pos, pattern);
            if (pattern == 0)
                array[pos++] = root.getData();
            pos = OrderNode(root.getRight(), array, pos, pattern);
            if (pattern == 1)
                array[pos++] = root.getData();
        }
        return pos;
    }

    public void rotateLeftChild() {
        this.root = this.root.rotateRight();
    }

    public void rotateRightChild() {
        this.root = this.root.rotateLeft();
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
                TreeNode n = (TreeNode) o;
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
        BinarySearchTree<Integer> t = new BinarySearchTree<Integer>((Integer data1, Integer data2) -> {
            return Integer.compare(data1, data2);
        });
        t.add(10);
        t.add(7);
        t.add(110);
        t.add(32);
        t.add(10);
        t.add(9);
        t.add(1);
        t.add(45);
        System.out.println(java.util.Arrays.toString(t.inOrder()));
        System.out.println(java.util.Arrays.toString(t.preOrder()));
        System.out.println(java.util.Arrays.toString(t.postOrder()));
        System.out.println(java.util.Arrays.toString(t.levelOrder()));
        System.out.println(t);
        t.rotateRightChild();
        System.out.println(t);
        t.rotateLeftChild();
        System.out.println(t);

    }
}