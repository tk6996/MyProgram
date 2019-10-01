class Queue():
    def __init__(self, list: list=None):
        if list:
            self.items = list
        else:
            self.items = []

    def enQueue(self, i):
        self.items.append(i)

    def deQueue(self):
        return self.items.pop(0)

    def isEmpty(self):
        return self.items == []

    def size(self):
        return len(self.items)

class Deque(Queue):
    def __init__(self,list=None):
        super().__init__(list)
    
    def enQueueFront(self,i):
        self.items.append()

    def deQueueRear(self):
        return self.items.pop()

    def getRear(self):
        return self.items[-1]

d = Deque([i for i in range(10)])
d.deQueue()
print(d.items)
d.deQueueRear()
print(d.items)
d.enQueue(777)
print(d.items)
d.enQueueFront(88)
print(d.items)


