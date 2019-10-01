class Queue() :
    def __init__(self):
        self.items = []
    def enqueue(self,data):
        self.items.append(data)
    def dequeue(self):
        return self.items.pop(0)
    def size(self):
        return len(self.items)


class PrevNode():
    def __init__(self,data,parent = None):
        self.data = data
        self.parent = parent

def bfsM3D2(target) :
    q = Queue()
    s = set()
    p = PrevNode(1) 
    q.enqueue(p)
    d = None
    while(q.size() > 0):
        val = q.dequeue()
        if val.data == target :
            d = val
            break
        if val.data in s:
            continue
        s.add(val.data)
        q.enqueue(PrevNode(val.data*3,val))
        q.enqueue(PrevNode(val.data//2,val))
    print(d.data , '=',end = ' ')
    printSolution(d)

def printSolution(node) :
    if node.parent :
        printSolution(node.parent)
        if node.data > node.parent.data :
            print('*',3,end=' ')
        else :
            print('//',2,end=' ')
    else :
        print(node.data,end=' ')

bfsM3D2(int(input()))


    