#from Python.mystack import Stack
from mystack import Stack


def checkMarkUp(megsage: str):
    stack = Stack()
    itr = megsage.find('<')
    while itr != -1:
        tail = megsage.find('>', itr+1)
        if tail == -1:
            return False
        if megsage[itr+1] != '/':
            stack.push(megsage[itr+1:tail])
        else:
            if stack.isEmpty() or stack.pop() != megsage[itr+2:tail]:
                return False
        itr = megsage.find('<', tail+1)
    if not stack.isEmpty():
        return False
    return True


print(checkMarkUp(''.join(open("Read.txt", "r"))))
