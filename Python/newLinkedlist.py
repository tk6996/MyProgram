class Node():
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


class SinglyLinkedList():
    def __init__(self, head=None):
        self.head = head

    def __str__(self):
        list_string = []
        ptr = self.head
        while ptr:
            list_string.append(ptr.data.__str__())
            ptr = ptr.next
        return ' '.join(list_string)

    def getTail(self):
        temp = self.head
        while temp.next:
            temp = temp.next
        return temp

    def getSize(self):
        size = 0
        temp = self.head
        while temp:
            temp = temp.next
            size += 1
        return size

    def isEmpty(self):
        return self.head == None

    def insert(self, index, data):
        size = self.getSize()
        index = size + index + 1 if index < 0 else index
        if 0 <= index <= size:
            if index == 0:
                self.head = Node(data, self.head)
            else:
                temp = self.head
                index -= 1
                while index:
                    temp = temp.next
                    index -= 1
                temp.next = Node(data, temp.next)
        else:
            raise IndexError

    def delete(self, index):
        size = self.getSize()
        index = size + index if index < 0 else index
        if 0 <= index < size:
            if index == 0:
                data = self.head.data
                self.head = self.head.next
            else:
                temp = self.head
                index -= 1
                while index:
                    temp = temp.next
                    index -= 1
                data = temp.next.data
                temp.next = temp.next.next
            return data
        else:
            raise IndexError

    def contains(self, data):
        temp = self.head
        while temp:
            if temp.data == data:
                return True
            temp = temp.next
        return False

    def remove(self, data):
        temp = self.head
        prev = None
        while temp:
            if temp.data == data:
                if prev:
                    prev.next = temp.next
                else:
                    self.head = self.head.next
                return True
            prev = temp
            temp = temp.next
        return False

    def appendHead(self, data):
        self.insert(0, data)

    def appendTail(self, data):
        self.insert(-1, data)

    def removeFrist(self):
        return self.delete(0)

    def removeTail(self):
        return self.delete(-1)


class StackImplementLinkedList():
    def __init__(self):
        self.head = Node
        self.size = 0

    def push(self, data):
        self.head = Node(data, self.head)
        self.size += 1

    def pop(self):
        temp = self.head
        self.head = self.head.next
        self.size -= 1
        return temp.data

    def top(self):
        return self.head.data

    def isEmpty(self):
        return self.size == 0

    def getSize(self):
        return self.size


class QueueImplementCircularLinkedList():
    def __init__(self):
        self.tail = None
        self.size = 0

    def enQueue(self, data):
        if self.tail:
            self.tail.next = Node(data, self.tail.next)
            self.tail = self.tail.next
        else:
            self.tail = Node(data)
            self.tail.next = self.tail
        self.size += 1

    def deQueue(self):
        temp = self.tail.next.data
        if self.tail is self.tail.next:
            self.tail = None
        else:
            self.tail.next = self.tail.next.next
        self.size -= 1
        return temp

    def getFront(self):
        return self.tail.next.data

    def getRear(self):
        return self.tail.data

    def isEmpty(self):
        return self.size == 0

    def getSize(self):
        return self.size


class DoublyNode():
    def __init__(self, data, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


class DequeImplementDoublyCiruclarHeaderLinkedList():
    def __init__(self):
        self.dummy = DoublyNode(None)
        self.dummy.next = self.dummy
        self.dummy.prev = self.dummy
        self.size = 0

    def enQueueFront(self, data):
        self.dummy.next = DoublyNode(data, self.dummy.next, self.dummy)
        self.dummy.next.next.prev = self.dummy.next
        self.size += 1

    def enQueueRear(self, data):
        self.dummy.prev = DoublyNode(data, self.dummy, self.dummy.prev)
        self.dummy.prev.prev.next = self.dummy.prev
        self.size += 1

    def deQueueFront(self):
        if not(self.dummy is self.dummy.next):
            temp = self.dummy.next.data
            self.dummy.next = self.dummy.next.next
            self.dummy.next.prev = self.dummy
            self.size -= 1
            return temp
        else:
            return None

    def deQueueRear(self):
        if not(self.dummy is self.dummy.prev):
            temp = self.dummy.prev.data
            self.dummy.prev = self.dummy.prev.prev
            self.dummy.prev.next = self.dummy
            self.size -= 1
            return temp
        else:
            return None

    def getFront(self):
        return self.dummy.next.data

    def getRear(self):
        return self.dummy.prev.data

    def isEmpty(self):
        return self.size == 0

    def getSize(self):
        return self.size


d = DequeImplementDoublyCiruclarHeaderLinkedList()
d.enQueueFront(88)
d.enQueueRear(777)
d.enQueueFront(788)
d.enQueueRear(1777)
print(d.deQueueFront())
while d.getSize():
    print(d.deQueueRear())
