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


def lift(linkedlist: List, newindex: int) -> Node:
    newHead = None
    if newindex > 0 and newindex < linkedlist.size():
        ptr = linkedlist.head
        for _ in range(newindex - 1):
            ptr = ptr.next
        newHead = ptr.next
        ptr.next = None
    elif newindex == linkedlist.size():
        newHead = linkedlist.head
        linkedlist.head = None
    return newHead


def bottomUp(linkedlist: List, percent: int, scrambleStack: Stack = None) -> None:
    listlen = linkedlist.size()
    newindex = percent * listlen // 100
    if newindex > 0 and newindex < listlen:
        oldhead = linkedlist.head
        tail = linkedlist.head = lift(linkedlist, newindex)
        while tail.next:
            tail = tail.next
        tail.next = oldhead
    if scrambleStack:
        scrambleStack.push((bottomUp.__name__, percent))


def deBottomUp(linkedlist: List, percent: int) -> None:
    listlen = linkedlist.size()
    percent = 100 - percent
    newindex = (percent * listlen // 100) + (1 if ((percent *
                                                    listlen / 100) - (percent * listlen // 100)) else 0)
    if newindex > 0 and newindex < listlen:
        oldhead = linkedlist.head
        tail = linkedlist.head = lift(linkedlist, newindex)
        while tail.next:
            tail = tail.next
        tail.next = oldhead


def riffleShuffle(linkedlist: List, percent: int, scrambleStack: Stack = None) -> None:
    listlen = linkedlist.size()
    newindex = percent * listlen // 100
    if newindex > 0 and newindex < listlen:
        ptr = linkedlist.head
        ptr2 = lift(linkedlist, newindex)
        ptrNext = ptr.next
        while ptr2:
            ptr.next = ptr2
            ptr = ptr2
            ptr2 = ptrNext
            ptrNext = ptr.next
    if scrambleStack:
        scrambleStack.push((riffleShuffle.__name__, percent))


def deRiffleShuffle(linkedlist: List, percent: int) -> None:
    listlen = linkedlist.size()
    amountList = percent * listlen // 100
    if amountList > 0 and amountList < listlen:
        numList = 1
        ptr = linkedlist.head
        head2 = ptr2 = linkedlist.head.next
        while numList < amountList and numList < listlen - amountList:
            ptr.next = ptr2.next
            ptr = ptr.next
            ptr2.next = ptr.next
            ptr2 = ptr2.next
            numList += 1
        if numList == amountList:
            ptr.next = None
        else:
            ptr.next = ptr2.next
            ptr2.next = None
        tail = ptr
        while tail.next:
            tail = tail.next
        tail.next = head2


def deScramble(linkedlist: List, scrambleStack: Stack):
    for _ in range(scrambleStack.size()):
        func, percen = scrambleStack.pop()
        if func == "bottomUp":
            deBottomUp(linkedlist, percen)
        elif func == "riffleShuffle":
            deRiffleShuffle(linkedlist, percen)
        print(linkedlist)


def linkedListToListStr(linkedlist: List) -> list:
    ptr = linkedlist.head
    newList = []
    while ptr:
        newList.append(str(ptr.data))
        ptr = ptr.next
    return newList


if __name__ == '__main__':
    RANGE = 12
    node = None
    for i in range(RANGE, 0, -1):
        node = Node(i, node)
    list1 = List(node)
    scrambleStack = Stack()
    print(list1)
    bottomUp(list1, 50, scrambleStack)
    print(list1)
    riffleShuffle(list1, 30, scrambleStack)
    print(list1)
    deScramble(list1, scrambleStack)
