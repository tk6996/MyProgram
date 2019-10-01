class Stack():
    def __init__(self, list=None, capacity=4):
        if list:
            self.items = list
            self.capacity = len(list) * 2
        else:
            self.items = []
            self.capacity = capacity

    def push(self, i):
        if self.size() < self.capacity:
            self.items.append(i)

    def size(self):
        return len(self.items)

    def isEmpty(self):
        return self.items == []

    def isFull(self):
        return self.size() == self.capacity

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items)-1]


def arrive(car: int, apark: Stack):
    if not apark.isFull():
        apark.push(car)
        print("car %d arrive \t space left %d" %
              (car, apark.capacity - apark.size()))
    else:
        print("car %d cannot arrive : SOI FULL" % (car))


def depart(car: int, apark: Stack, bpark: Stack):
    if apark.isEmpty():
        print("car %d cannot depart: soi empty" % (car))
    else:
        if car in apark.items:
            print("car %d depart :" % (car), end='\n\t')
            while apark.peek() != car:
                bpark.push(apark.pop())
                print(" pop", bpark.peek(), end=',')
            print(" pop", apark.pop(), end='')
            while not bpark.isEmpty():
                apark.push(bpark.pop())
                print(", push", apark.peek(), end='')
            print("\n\t space left %d" % (apark.capacity - apark.size()))
        else:
            print("car %d cannot depart: No car %d" % (car, car))


def printSoi(apark: Stack):
    print("print soi =", apark.items)


if __name__ == '__main__':
    apark = Stack(capacity=4)
    bpark = Stack(capacity=4)
    depart(6, apark, bpark)
    arrive(1, apark)
    arrive(2, apark)
    arrive(3, apark)
    arrive(4, apark)
    arrive(5, apark)
    printSoi(apark)
    depart(7, apark, bpark)
    depart(2, apark, bpark)
    arrive(7, apark)
    arrive(10, apark)
    depart(7, apark, bpark)
    printSoi(apark)
