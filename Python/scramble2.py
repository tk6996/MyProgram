import math


class Stack():
    def __init__(self, list=None):
        if list:
            self.items = list
        else:
            self.items = []

    def push(self, i):
        self.items.append(i)

    def size(self):
        return len(self.items)

    def isEmpty(self):
        return self.items == []

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items)-1]


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
    def __init__(self, head: Node = None):
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


def lift(srclist: List, percent: int, ceil: bool = False) -> List:
    times = percent * srclist.size() / 100
    times = math.ceil(times) if ceil else math.floor(times)
    newList = List()
    while times > 0:
        newList.append(srclist.removeHead())
        times -= 1
    return newList


def bottomUp(list1: List, percent: int, scrambleStack: Stack = None) -> None:
    list2 = lift(list1, percent)
    if list2.isEmpty():
        return None
    if list1.isEmpty():
        list1.head = list2.head
        return None
    tail = list1.head
    while tail.getNext():
        tail = tail.getNext()
    tail.setNext(list2.head)
    if scrambleStack:
        scrambleStack.push((bottomUp.__name__, percent))


def deBottomUp(list1: List, percent: int) -> None:
    list2 = lift(list1, 100 - percent, True)
    if list2.isEmpty():
        return None
    if list1.isEmpty():
        list1.head = list2.head
        return None
    tail = list1.head
    while tail.getNext():
        tail = tail.getNext()
    tail.setNext(list2.head)


def riffleShuffle(list1: List, percent: int, scrambleStack: Stack = None) -> None:
    list2 = lift(list1, percent)
    if list2.isEmpty():
        return None
    if list1.isEmpty():
        list1.head = list2.head
        return None
    newList = List()
    while not (list1.isEmpty() and list2.isEmpty()):
        if not list2.isEmpty():
            newList.append(list2.removeHead())
        if not list1.isEmpty():
            newList.append(list1.removeHead())
    list1.head = newList.head
    if scrambleStack:
        scrambleStack.push((riffleShuffle.__name__, percent))


def deRiffleShuffle(list1: List, percent: int) -> None:
    times = math.ceil((100-percent) * list1.size() / 100)
    fristmin = (list1.size() - times >= times)
    times = min(list1.size() - times, times)
    list2 = List()
    list3 = List()
    while times > 0:
        list2.append(list1.removeHead())
        list3.append(list1.removeHead())
        times -= 1
    tail = list2.head if fristmin else list3.head
    while tail.getNext():
        tail = tail.getNext()
    tail.setNext(list1.head)
    newList = List()
    while not list2.isEmpty():
        newList.append(list2.removeHead())
    while not list3.isEmpty():
        newList.append(list3.removeHead())
    list1.head = newList.head


def deScramble(linkedlist: List, scrambleStack: Stack):
    for _ in range(scrambleStack.size()):
        func, percen = scrambleStack.pop()
        if func == "bottomUp":
            deBottomUp(linkedlist, percen)
        elif func == "riffleShuffle":
            deRiffleShuffle(linkedlist, percen)
        print(linkedlist)


if __name__ == '__main__':
    RANGE = 10
    node = None
    for i in range(RANGE, 0, -1):
        node = Node(i, node)
    list1 = List(node)
    scrambleStack = Stack()
    print(list1)
    bottomUp(list1, 12, scrambleStack)
    print(list1)
    riffleShuffle(list1, 44, scrambleStack)
    print(list1)
    bottomUp(list1, 70, scrambleStack)
    print(list1)
    riffleShuffle(list1, 50, scrambleStack)
    print(list1)
    riffleShuffle(list1, 15, scrambleStack)
    print(list1)
    bottomUp(list1, 47, scrambleStack)
    print(list1)
    bottomUp(list1, 7, scrambleStack)
    print(list1)
    riffleShuffle(list1, 10, scrambleStack)
    print(list1)
    riffleShuffle(list1, 77, scrambleStack)
    print('----------------------------------------')
    print(list1)
    # print(linkedListToListStr(list1))
    print('----------------------------------------')
    deScramble(list1, scrambleStack)
