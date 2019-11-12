from random import randint


class BinarySearchTree:
    class Node:
        def __init__(self, data, left=None, right=None):
            self.data = data
            self.left = left
            self.right = right

    def __init__(self):
        self.root = None
        self.size = 0

    def __len__(self):
        return self.size

    def _addnode(self, node, data):
        if node is None:
            node = BinarySearchTree.Node(data)
        else:
            if data < node.data:
                node.left = self._addnode(node.left, data)
            else:
                node.right = self._addnode(node.right, data)
        return node

    def add(self, data):
        self.root = self._addnode(self.root, data)
        self.size += 1

    def _removenode(self, node, data):
        if node is not None:
            if data < node.data:
                node.left = self._removenode(node.left, data)
            elif data > node.data:
                node.right = self._removenode(node.right, data)
            else:
                if node.left is not None and node.right is not None:
                    temp = node.right
                    while temp.left is not None:
                        temp = temp.left
                    node.data = temp.data
                    node.right = self._removenode(node.right, node.data)
                else:
                    node = node.left if node.left is not None else node.right
        else:
            self.size += 1
        return node

    def remove(self, data):
        self.root = self._removenode(self.root, data)
        self.size -= 1

    def __traversal(self, node, key):
        if node is not None:
            if key < 0:
                print(node.data, end=' ')
            self.__traversal(node.left, key)
            if key == 0:
                print(node.data, end=' ')
            self.__traversal(node.right, key)
            if key > 0:
                print(node.data, end=' ')

    def preorder(self):
        self.__traversal(self.root, -1)
        print()

    def inorder(self):
        self.__traversal(self.root, 0)
        print()

    def postorder(self):
        self.__traversal(self.root, 1)
        print()

    def levelorder(self):
        if self.root is None:
            return
        queue = []
        while queue != []:
            node = queue.pop(0)
            print(node.data, end=' ')
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        print()
    def print90Degree(self):
        def __print90(node,level):
            if node is not None :
                __print90(node.right,level+1)
                print("   "*level,node.data,sep='')
                __print90(node.left,level+1)
        __print90(self.root,0)

class AVLTree(BinarySearchTree):
    class AVLNode(BinarySearchTree.Node):
        def __init__(self, data, left=None, right=None):
            super().__init__(data, left, right)
            self.__height = 0

        @property
        def height(self):
            return self.__height

        def setHeight(self):
            lh = self.left.height if self.left is not None else -1
            rh = self.right.height if self.right is not None else -1
            self.__height = max(lh,rh) + 1
        def balanceCheck(self):
            lh = self.left.height if self.left is not None else -1
            rh = self.right.height if self.right is not None else -1
            return rh - lh

    def __init__(self):
        super().__init__()

    def __rightRotate(self, node):
        if node is None or node.left is None:
            return node
        temp = node.left
        node.left = node.left.right
        temp.right = node
        temp.setHeight()
        temp.right.setHeight()
        return temp

    def __leftRotate(self, node):
        if node is None or node.right is None:
            return node
        temp = node.right
        node.right = node.right.left
        temp.left = node
        temp.setHeight()
        temp.left.setHeight()
        return temp

    def rebalance(self, node):
        if node is not None:
            balance = node.balanceCheck()
            if balance < -1:
                if node.left.balanceCheck() == 1:
                    node.left = self.__leftRotate(node.left)
                node = self.__rightRotate(node)
            elif balance > 1:
                if node.right.balanceCheck() == -1:
                    node.right = self.__rightRotate(node.right)
                node = self.__leftRotate(node)
            else :
                node.setHeight()
        return node

    def _addnode(self, node, data):
        if node is None:
            return AVLTree.AVLNode(data)
        node = super()._addnode(node, data)
        return self.rebalance(node)
    
    def _removenode(self, node, data):
        node = super()._removenode(node, data)
        return self.rebalance(node)
    
    def __str__(self):
        if self.root is None:
            return ""
        string = ''
        queue = [self.root]
        height = self.root.height
        while any(queue):
            queue2 = []
            while len(queue) > 0:
                temp = queue.pop(0)
                if  temp is not None :
                    queue2.append(None if temp.left is None else temp.left)
                    queue2.append(None if temp.right is None else temp.right)
                else :
                    queue2.append(None)
                    queue2.append(None)
                string += ("".center(3))*(2**height - 1)
                string += temp.data.__str__().center(3) if temp else "".center(3)
                string += ("".center(3))*(2**height - 1)
                string += "".center(3)
            string += '\n'
            height -= 1
            queue = queue2
        return string

t = AVLTree()
a = [i for i in range(31)]
for _ in range(31):
    t.add(a.pop(randint(0,len(a)-1)))
print(t)