import random
import math


class BST():
    class node:
        def __init__(self, data, left=None, right=None):
            self.__data = data
            self.__left = None if left is None else left
            self.__right = None if right is None else right

        def __str__(self):
            return str(self.__data)

        def getData(self):  # accessor
            return self.__data

        def getLeft(self):  # accessor
            return self.__left

        def getRight(self):  # accessor
            return self.__right

        def setData(self, data):  # mutator
            self.__data = data

        def setLeft(self, left):  # mutator
            self.__left = left

        def setRight(self, right):  # mutator
            self.__right = right

    def __init__(self):
        self.root = None

    def addI(self, data):
        if self.root is None:
            self.root = BST.node(data)
            return
        ptr = self.root
        while ptr:
            if data < ptr.getData():
                if ptr.getLeft() is None:
                    ptr.setLeft(BST.node(data))
                    break
                else:
                    ptr = ptr.getLeft()
            else:
                if ptr.getRight() is None:
                    ptr.setRight(BST.node(data))
                    break
                else:
                    ptr = ptr.getRight()

    def inOrder(self):
        def __inOrderNode(root):
            if root:
                __inOrderNode(root.getLeft())
                print(root,end=" ")
                __inOrderNode(root.getRight())
        __inOrderNode(self.root)
        print()

    def add(self, data):
        def __addNode(root, data):
            if root is None:
                root = BST.node(data)
            elif data < root.getData():
                root.setLeft(__addNode(root.getLeft(), data))
            else:
                root.setRight(__addNode(root.getRight(), data))
            return root
        self.root = __addNode(self.root, data)

    def printSideway(self):
        def __printSidewayNode(root, layer=0):
            if root:
                __printSidewayNode(root.getRight(), layer+1)
                for _ in range(layer):
                    print(end='   ')
                print(root.getData())
                __printSidewayNode(root.getLeft(), layer+1)
        __printSidewayNode(self.root)

    def preOrder(self):
        def __preOrderNode(root):
            if root:
                print(root,end=" ")
                __preOrderNode(root.getLeft())
                __preOrderNode(root.getRight())
        __preOrderNode(self.root)
        print()

    def postOrder(self):
        def __postOrderNode(root):
            if root:
                __postOrderNode(root.getLeft())
                __postOrderNode(root.getRight())
                print(root,end=" ")
        __postOrderNode(self.root)
        print()
    
    def search(self, data):
        ptr = self.root
        while ptr :
            if data < ptr.getData():
                ptr = ptr.getLeft()
            elif data > ptr.getData():
                ptr = ptr.getRight()
            else :
                break
        return ptr 
    
    def path(self,data):
        ptr = self.root
        lists = []
        while ptr :
            lists.append(ptr.__str__())
            if data < ptr.getData():
                ptr = ptr.getLeft()
            elif data > ptr.getData():
                ptr = ptr.getRight()
            else :
                return ' '.join(lists)
        else :
            return None
    def delete(self,data):
        def __deleteNode(root,data):
            if root is not None :
                if data < root.getData():
                    root.setLeft(__deleteNode(root.getLeft(),data))
                elif data > root.getData():
                    root.setRight(__deleteNode(root.getRight(),data))
                else :
                    if root.getLeft() and root.getRight() :
                        temp = root.getRight()
                        while temp.getLeft():
                            temp = temp.getLeft()
                        root.setData(temp.getData())
                        root.setRight(__deleteNode(root.getRight(),temp.getData()))
                    elif root.getLeft() :
                        root = root.getLeft()
                    else :
                        root = root.getRight()
            return root
        self.root = __deleteNode(self.root,data)    

# l = [int(e) for e in input("insert integers : ").split()]
# print(l)
# t = BST()
# for ele in l:
#     t.addI(ele)
# print("preOrder",end=" ")
# t.preOrder()
# print("inOrder",end=" ")
# t.inOrder()
# print("postOrder",end=" ")
# t.postOrder()
# t.printSideway()
# t.delete(15)
# t.delete(18)
# t.inOrder()
# t.printSideway()