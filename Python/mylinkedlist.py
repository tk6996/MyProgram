class Node():
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

    def __str__(self):
        return self.data.__str__()

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self, data):
        self.data = data

    def setNext(self, next):
        self.next = next


class List():
    def __init__(self, head=None):
        self.head = head

    def __str__(self):
        list_string = []
        ptr = self.head
        while ptr:
            list_string.append(ptr.getData().__str__())
            ptr = ptr.getNext()
        return ' '.join(list_string)

    def size(self):
        l = 0
        ptr = self.head
        while ptr:
            ptr = ptr.getNext()
            l += 1
        return l

    def isEmpty(self):
        return self.head == None

    def append(self, data):
        if self.head:
            ptr = self.head
            while ptr.getNext():
                ptr = ptr.getNext()
            ptr.setNext(Node(data))
        else:
            self.head = Node(data)

    def addHead(self, data):
        self.head = Node(data, self.head)

    def isIn(self, data):
        ptr = self.head
        while ptr:
            if ptr.data == data:
                return True
            ptr = ptr.getNext()
        return False

    def before(self, data):
        ptr = self.head
        if ptr:
            while ptr.getNext():
                if ptr.getNext().data == data:
                    return ptr
                ptr = ptr.getNext()
        return None

    def remove(self, data):
        if self.isIn(data):
            pre = self.before(data)
            if pre:
                re = pre.getNext()
                pre.setNext(pre.getNext().getNext())
            else:
                re = self.head
                self.head = self.head.getNext()
            return re
        else:
            return None

    def removeTail(self):
        ptr = self.head
        pre = None
        if ptr:
            while ptr.getNext():
                pre = ptr
                ptr = ptr.getNext()
            if pre:
                pre.setNext(None)
            else:
                self.head = None
            return ptr
        else:
            return None

    def removeHead(self):
        if self.head:
            ptr = self.head
            self.head = self.head.getNext()
            return ptr
        else:
            return None


if __name__ == '__main__':
    n4 = Node('D')
    n3 = Node('C', n4)
    n2 = Node('B', n3)
    n1 = Node('A', n2)
    l1 = List(n1)
    print('before',l1)
    print('size',l1.size())
    print('is Empty',l1.isEmpty())
    l1.append('N')
    print('append N',l1,sep='     ')
    l1.addHead('H')
    print("appendHead H",l1,sep='    ')
    print('is In C',l1.isIn('C'))
    print('is In J',l1.isIn('J'))
    print('before C is',l1.before('C'))
    print('before H is',l1.before('H'))
    print('removetail',l1.removeTail())
    print(l1)
    print('removehead',l1.removeHead())
    print(l1)
    print('remove D')
    l1.remove('D')
    print(l1)