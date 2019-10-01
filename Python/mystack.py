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
        return self.items[-1]


if __name__ == '__main__':
    s = Stack()
    print(s.isEmpty())
    s.push('A')
    print(s.items)
    s.push('B')
    print(s.items)
    s.push('C')
    print(s.items)
    print("size =",s.size())
    print(s.pop())
    print(s.items)
    print(s.peek())
    print(s.pop())
    print(s.isEmpty())
    print(s.pop())