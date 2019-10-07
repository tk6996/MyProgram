#from Python.myqueue import Queue
from myqueue import Queue
from random import random
def radixSort(lists : list) -> list:
    def digitForNumber(n : int) -> int:
        return digitForNumber(n//10) + 1 if n != 0 else 0
    digits =  digitForNumber(max(lists,key=digitForNumber))
    print(digits)
    for d in range(digits):
        qRadix = [ Queue() for _ in range(10) ]            
        while len(lists):
            val = lists.pop(0)
            qRadix[(val//10**d)%10].enQueue(val)
        for q in qRadix:
            lists.extend(q.items)
    return lists
l = [int(random()*100000) for _ in range(1000)]
print(radixSort(l))