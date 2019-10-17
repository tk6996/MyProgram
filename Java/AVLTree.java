import java.util.Comparator;

public class AVLTree<T> extends BinarySearchTree<T> {

    private class AVLTreeNode extends TreeNode
    {
        private int height;
		public AVLTreeNode(T data, BinarySearchTree<T>.TreeNode left, BinarySearchTree<T>.TreeNode right) {
            super(data, left, right);
            this.height = 1;
		}

		public AVLTreeNode(T data) {
			super(data);
		}
        public void setHeight()
        {
            this.height = super.getHeight();
        }
        @Override
        public int getHeight()
        {
            return this.height;
        }
        @Override
        public TreeNode rotateLeft() {
            AVLTreeNode root = (AVLTreeNode)super.rotateLeft();
            root.setHeight();
            return root;
        }
        @Override
        public TreeNode rotateRight() {
            AVLTreeNode root = (AVLTreeNode)super.rotateRight();
            root.setHeight();
            return root;
        }
    }
    protected int balanceValue(TreeNode root) {
        int leftHeight = root.getLeft() != null ? root.getLeft().getHeight() : -1;
        int rightHeight = root.getRight() != null ? root.getRight().getHeight() : -1;
        return  rightHeight - leftHeight;
    }

    public AVLTree(Comparator<? super T> comparator) {
        super(comparator);
    }

    private TreeNode reBalance(TreeNode root) {
        if (root != null) {
            if (balanceValue(root) == -2) {
                if (balanceValue(root.getLeft()) == 1)
                    root.setLeft(root.getLeft().rotateLeft());
                root = root.rotateRight();
            }
            if (balanceValue(root) == 2) {
                if (balanceValue(root.getRight()) == -1)
                    root.setRight(root.getRight().rotateRight());
                root = root.rotateLeft();
            }
            ((AVLTreeNode)root).setHeight();
        }
        return root;
    }

    @Override
    protected TreeNode addNode(TreeNode root,T data) {
        if(root == null)
            return new AVLTreeNode(data);
        root = super.addNode(root,data);
        root = reBalance(root);
        return root;
    }

    @Override
    protected TreeNode removeNode(TreeNode root,T data) {
        root = super.removeNode(root,data);
        root = reBalance(root);
        return root;
    }

    public static void main(String[] args) {
        AVLTree<Integer> t = new AVLTree<Integer>((Integer data1, Integer data2) -> {
            return Integer.compare(data1, data2);
        });
        java.util.Random rd = new java.util.Random(174);
        long st = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            int r = rd.nextInt();
           // System.out.println(r);
            t.add(r);
        }
        System.out.println("Timing = " + (System.currentTimeMillis() - st));
    }
}
