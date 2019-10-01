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

if __name__ == '__main__' :
    string = input()
    s = Stack()
    error = False
    for char in string :
        if not error :
            if char in '([{' :
                s.push(char)
            elif char in ')]}' :
                if s.isEmpty() :
                   error = True 
                elif char == ')' : 
                    error = (s.pop() != '(')
                elif char == ']' : 
                    error = (s.pop() != '[')
                else : 
                    error = (s.pop() != '{')
        else :
            break
    if error :
        print('MISMATCH')
    elif not s.isEmpty() :
        print('MISMATCH open paren. exceed')
    else :
        print('MATCH')
