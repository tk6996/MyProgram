class BinaryTreeNode():
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return self.data.__str__()


def addi(root: BinaryTreeNode, data) -> BinaryTreeNode:
    if root is not None:
        if data < root.data:
            root.left = addi(root.left, data)
        else:
            root.right = addi(root.right, data)
    else:
        root = BinaryTreeNode(data)
    return root


def inorder(root: BinaryTreeNode) -> None:
    if root is not None:
        inorder(root.left)
        print(root, end=' ')
        inorder(root.right)


def add(root: BinaryTreeNode, data):
    if root is not None:
        node = root
        while node is not None:
            if data < node.data:
                if node.left is not None:
                    node = node.left
                else:
                    node.left = BinaryTreeNode(data)
                    break
            else:
                if node.right is not None:
                    node = node.right
                else:
                    node.right = BinaryTreeNode(data)
                    break
    else:
        root = BinaryTreeNode(data)
    return root


def printSideWay(root, level):
    if root is not None:
        printSideWay(root.right, level+1)
        print('   '*level, root)
        printSideWay(root.left, level+1)


def height(root):
    return max(height(root.left), height(root.right)) + 1 if root is not None else -1


def path(root, data):
    print(root, end=' ')
    if root is not None:
        if data < root.data:
            path(root.left, data)
        elif data > root.data:
            path(root.right, data)


def search(root, data):
    if root is not None:
        if data < root.data:
            root = search(root.left, data)
        elif data > root.data:
            root = search(root.right, data)
    return root


def depth(root, data):
    if root is not None:
        if data < root.data:
            d = depth(root.left, data) + 1
        elif data > root.data:
            d = depth(root.right, data) + 1
        else:
            d = 0
        return d if d != -1 else -1
    else:
        return -1


def minNode(root):
    if root is not None:
        return minNode(root.left) if root.left is not None else root


l = [14, 4, 9, 7, 15, 3, 18, 16, 20, 5, 16]
print("input : ", l)

r = None
for ele in l:
    r = add(r, ele)

print("inorder:", end=' ')
inorder(r)
print()

print("printSideWay:")
printSideWay(r, 0)

print("height of ", r, '=', height(r))

d = 5
print("path: ", d, '=', end=' ')
path(r, d)
print()

d = 9
t = search(r, d)
print(t)

d = 18
print("depth of node data ", d, '=', depth(r, d))

print('smallest data =', minNode(r))
