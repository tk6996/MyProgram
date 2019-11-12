import random


class MinHeap:
    class BinaryTree:
        def __init__(self, data, left=None, right=None):
            self.data = data
            self.left = left
            self.right = right
            self._minheight = 0
            self._maxheight = 0

        def setHeight(self):
            minleft = self.left.getMinHeight() if self.left else -1
            minright = self.right.getMinHeight() if self.right else -1
            self._minheight = min(minleft, minright) + 1
            maxleft = self.left.getMaxHeight() if self.left else -1
            maxright = self.right.getMaxHeight() if self.right else -1
            self._maxheight = max(maxleft, maxright) + 1

        def getMinHeight(self) -> int:
            return self._minheight

        def getMaxHeight(self) -> int:
            return self._maxheight

        def __str__(self) -> str:
            return self.data.__str__()

    def __init__(self):
        self.root = None

    def _swapData(self, node1, node2):
        temp = node1.data
        node1.data = node2.data
        node2.data = temp

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
        def __print90(node, level):
            if node is not None:
                __print90(node.right, level+1)
                print("   "*level, node.data, sep='')
                __print90(node.left, level+1)
        __print90(self.root, 0)

    def add(self, data):
        self.root = self._addNode(self.root, data)

    def _addNode(self, node, data):
        if node is not None:
            if node.getMinHeight() > 0:
                if node.left.getMinHeight() <= node.right.getMinHeight():
                    node.left = self._addNode(node.left, data)
                    if node.left.data < node.data:
                        self._swapData(node, node.left)
                else:
                    node.right = self._addNode(node.right, data)
                    if node.right.data < node.data:
                        self._swapData(node, node.right)
            else:
                if node.left is None:
                    node.left = self._addNode(node.left, data)
                    if node.left.data < node.data:
                        self._swapData(node, node.left)
                else:
                    node.right = self._addNode(node.right, data)
                    if node.right.data < node.data:
                        self._swapData(node, node.right)
            node.setHeight()
        return MinHeap.BinaryTree(data) if node is None else node

    def _heapify(self, node):
        if node is None:
            return None
        minNode = node
        if (node.left is not None) and (node.left.data < minNode.data):
            minNode = node.left
        if (node.right is not None) and (node.right.data < minNode.data):
            minNode = node.right
        if minNode is not node:
            self._swapData(node, minNode)
            self._heapify(minNode)

    def _removelastNode(self, node, lastdata=[]):
        if node is None:
            return None
        elif node.getMaxHeight() == 0:
            lastdata.append(node.data)
            return None
        else:
            if node.getMinHeight() > 0:
                if node.left.getMaxHeight() > node.right.getMaxHeight():
                    node.left = self._removelastNode(node.left, lastdata)
                else:
                    node.right = self._removelastNode(node.right, lastdata)
            elif node.right is not None:
                node.right = self._removelastNode(node.right, lastdata)
            else:
                node.left = self._removelastNode(node.left, lastdata)
            node.setHeight()
            return node

    def popMin(self):
        if self.root is None:
            return None
        lastdata = []
        self.root = self._removelastNode(self.root, lastdata)
        if self.root is None:
            return lastdata.pop()
        else:
            temp = self.root.data
            # print("*",lastdata[-1],"*")
            self.root.data = lastdata.pop()
            self._heapify(self.root)
            return temp

    def isEmpty(self):
        return self.root is None

    def __str__(self):
        if self.isEmpty():
            return ""
        string = ''
        queue = [self.root]
        height = self.root.getMaxHeight()
        while any(queue):
            queue2 = []
            while len(queue) > 0:
                temp = queue.pop(0)
                if temp is not None:
                    queue2.append(None if temp.left is None else temp.left)
                    queue2.append(None if temp.right is None else temp.right)
                else:
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


def Heapsort(array: list):
    heap = MinHeap()
    newarray = []
    for itr in array:
        heap.add(itr)
    # heap.print90Degree()
    # print(heap)
    while not heap.isEmpty():
        newarray.append(heap.popMin())
    return newarray


arr = [random.randint(-99, 999) for _ in range(13)]
print(Heapsort(arr))
