import java.util.Comparator;

public class AVLTree<T> extends BinarySearchTree<T> {

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
        }
        return root;
    }

    @Override
    protected TreeNode addNode(TreeNode root,T data) {
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
        for (int i = 0; i < 30; i++) {
            int r = rd.nextInt(100);
            System.out.println(r);
            t.add(r);
        }
        System.out.println(java.util.Arrays.toString(t.inOrder()));
        System.out.println(java.util.Arrays.toString(t.preOrder()));
        System.out.println(java.util.Arrays.toString(t.postOrder()));
        System.out.println(java.util.Arrays.toString(t.levelOrder()));
        System.out.println(t);

    }
}
