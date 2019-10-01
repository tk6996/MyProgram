def fac(n):
    return n * fac(n-1) if n > 1 else 1

def sum1ToN(n):
    return n + sum1ToN(n-1) if n > 1 else 1


def printNto1(n):
    print(n)
    if n > 1:
        printNto1(n-1)


def print1toN(n):
    if n > 1:
        print1toN(n-1)
    print(n)


def fib(n):
    return fib(n-1) + fib(n-2) if n > 2 else 1


def binarySearch(lo, hi, x, l):
    if lo >= hi:
        return None
    mi = (hi+lo)//2
    if x < l[mi]:
        return binarySearch(lo, mi, x, l)
    elif x > l[mi]:
        return binarySearch(mi+1, hi, x, l)
    else:
        return mi


def move(n, src, des, buf):
    if n == 1:
        print('Move disk %d from %s ==> %s' % (n, src, des))
        return None
    move(n-1, src, buf, des)
    print('Move disk %d from %s ==> %s' % (n, src, des))
    move(n-1, buf, des, src)


def sum1(n, l):
    return sum1(n-1, l) + l[n-1] if n > 0 else 0


def sum2(st, en, l):
    return l[st] + sum2(st+1, en, l) if st < en else 0


def sum3(l):
    return l[0] + sum3(l[1:]) if l else 0


def printlistForw(l, i=0):
    print(l[i])
    if i < len(l) - 1:
        printlistForw(l, i + 1)


def printlistBkw(l, i=0):
    if i < len(l) - 1:
        printlistBkw(l, i + 1)
    print(l[i])


def app(n, l=None):
    if l == None:
        l = []
    if n > 1:
        app(n-1, l)
    l.append(n)
    return l


def appb(n, l=None):
    if l == None:
        l = []
    l.append(n)
    if n > 1:
        app(n-1, l)
    return l


class node():
    def __init__(self, d, nxt=None):
        self.data = d
        if nxt is None:
            self.next = None
        else:
            self.next = nxt


def printList(l: node):
    print(l.data)
    if l.next:
        printList(l.next)


def createLLL(n, i=0):
    return node(n[i], createLLL(n, i + 1)) if i < len(n) else None


def createLL(n, i=1):
    return node(i, createLL(n, i + 1)) if i <= n else None


def knapsack(K, B):
    ans = []

    def pickup(K, B, picks):
        nonlocal ans
        if B == []:
            return None
        val = B.pop(0)
        picks.append(val)
        if K - val == 0:
            ans.append(picks[::])
        elif K - val > 0:
            pickup(K-val, B[::], picks)
        picks.pop()
        pickup(K, B, picks)
    pickup(K, B[::], [])
    return ans


print(knapsack(20, [20, 10, 5, 5, 3, 2, 20, 10]))