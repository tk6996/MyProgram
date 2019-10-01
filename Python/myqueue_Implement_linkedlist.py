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
            list_string.append(ptr.data.__str__())
            ptr = ptr.next
        return ' '.join(list_string)

    def size(self):
        l = 0
        ptr = self.head
        while ptr:
            ptr = ptr.next
            l += 1
        return l

    def isEmpty(self):
        return self.head == None

    def append(self, data):
        if self.head:
            ptr = self.head
            while ptr.next:
                ptr = ptr.next
            ptr.next = Node(data)
        else:
            self.head = Node(data)

    def addHead(self, data):
        self.head = Node(data, self.head)

    def isIn(self, data):
        ptr = self.head
        while ptr:
            if ptr.data == data:
                return True
            ptr = ptr.next
        return False

    def before(self, data):
        ptr = self.head
        if ptr:
            while ptr.next:
                if ptr.next.data == data:
                    return ptr
                ptr = ptr.next
        return None

    def remove(self, data):
        if self.isIn(data):
            pre = self.before(data)
            if pre:
                re = pre.next
                pre.next = pre.next.next
            else:
                re = self.head
                self.head = self.head.next
            return re
        else:
            return None

    def removeTail(self):
        ptr = self.head
        pre = None
        if ptr:
            while ptr.next:
                pre = ptr
                ptr = ptr.next
            if pre:
                pre.next = None
            else:
                self.head = None
            return ptr
        else:
            return None

    def removeHead(self):
        if self.head:
            ptr = self.head
            self.head = self.head.next
            return ptr
        else:
            return None

class Queue_Linked_List():
    def __init__(self,list_var : List = None ):
        if list_var : 
            front = list_var.head
            tail = front
            while tail.next :
                tail = tail.getNext()
            tail.setNext(front) 
            self.tail = tail
        else :
            self.tail = None
    def enQueue(self, i):
        if self.tail :
            front =  self.tail.getNext()
            self.tail.setNext(Node(i,front))
            self.tail = self.tail.getNext() 
        else :
            self.tail = Node(i)
            self.tail.setNext(self.tail) 
    def deQueue(self):
        if self.tail is self.tail.next :
            value = self.tail.getData()
            self.tail = None
            return value
        else :
            value = self.tail.getNext().getData()
            self.tail.setNext(self.tail.getNext().getNext())
            return value
    def isEmpty(self):
        return not self.tail
    def size(self):
        pointer = self.tail
        size = 1
        while not (pointer.getNext() is self.tail) :
            size += 1
            pointer = pointer.getNext()
        return size

q = Queue_Linked_List()
for i in range(10):
    q.enQueue(i)
print(q.size())
while not q.isEmpty():
    print(q.deQueue())