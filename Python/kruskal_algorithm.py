import random
class Edge():
    def __init__(self, u: int, v: int, w: int):
        self.u = u
        self.v = v
        self.w = w

    def __lt__(self, value):
        return self.w < value.w

    def __str__(self):
        return '%d ===== %d ===== %d' % (self.u, self.w, self.v)


class Node():
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class priorityQueueList():

    def __init__(self):
        self.head = None

    def add(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            ptr = self.head
            pre = None
            while ptr:
                if data < ptr.data:
                    if not pre:
                        self.head = Node(data, self.head)
                    else:
                        pre.next = Node(data, pre.next)
                    break
                pre = ptr
                ptr = ptr.next
            else:
                pre.next = Node(data)

    def removeFrist(self):
        re = self.head.data
        self.head = self.head.next
        return re


class Graph():
    def __init__(self, V):
        self.V = V
        self.lists = tuple([] for _ in range(V))

    def addEdge(self, u: int, v: int, w: int):
        self.lists[u].append((v, w))
        self.lists[v].append((u, w))

    def __str__(self):
        string = ''
        for i in range(self.V):
            for edge in self.lists[i]:
                if i <= edge[0]:
                    string += '%d ===== %d ===== %d\n' % (
                        i+1, edge[1], edge[0]+1)
        return string


def kruskal(g: Graph, edges) -> Graph:
    mincost = 0
    edge_count = 0
    p = []
    h = []
    for i in range(g.V):
        p.append(i)
        h.append(0)

    def findSet(i: int, p: list):
        if p[i] != i:
            return findSet(p[i], p)
        else:
            return i

    def unionSet(u: int, v: int, p: list, h: list):
        a = findSet(u, p)
        b = findSet(v, p)
        if h[a] < h[b]:
            p[a] = b
        else:
            p[b] = a
            if h[a] == h[b]:
                h[a] += 1

    while edge_count < g.V - 1:
        edge = edges.removeFrist()
        if findSet(edge.u, p) != findSet(edge.v, p):
            unionSet(edge.u, edge.v, p, h)
            mincost += edge.w
            g.addEdge(edge.u, edge.v, edge.w)
            edge_count += 1
    return mincost


p = priorityQueueList()
a, b = input().split(' ')
V = int(a)
E = int(b)
allcost = 0
for _ in range(E):
    a, b, c = input().split(' ')
    p.add(Edge(int(a) - 1, int(b) - 1, int(c)))
    allcost += int(c)
#p = a.head
# while p:
#    print(p.data)
#    p = p.next
g = Graph(V)
m = kruskal(g, p)
print(g)
print("deletecost =", allcost - m)
