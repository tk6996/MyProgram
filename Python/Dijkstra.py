class Graph():
    class Vertex():
        def __init__(self, des, w):
            self.des = des
            self.w = w

    def __init__(self, size):
        self.lists = [[] for i in range(size)]

    def add(self, src, des, w):
        self.lists[src].append(self.Vertex(des, w))

    def routineprint(self):
        for i in range(len(self.lists)):
            for j in self.lists[i]:
                print(i, "--", j.w, "-->", j.des)

    def dijkstra(self, src, des):
        path = []
        sets = set([i for i in range(len(self.lists))])
        known = [float('inf') for i in range(len(self.lists))]
        parent = [-1 for i in range(len(self.lists))]
        current = src
        known[current] = 0
        while des in sets:
            sets.remove(current)
            for v in self.lists[current]:
                if (v.des in sets) and (known[current] + v.w < known[v.des]):
                    known[v.des] = known[current] + v.w
                    parent[v.des] = current
            min_val = float('inf')
            for i in range(len(self.lists)):
                if (i in sets) and (known[i] < min_val):
                    min_val = known[i]
                    current = i
        p = des
        path.append(p)
        while p != src :
            path = [parent[p]] + path
            p = parent[p]
        print("Shortest path =",known[des])
        print("path :",path)

g = Graph(7)
g.add(0, 1, 2)
g.add(1, 4, 10)
g.add(4, 6, 6)
g.add(6, 5, 1)
g.add(2, 5, 5)
g.add(2, 0, 4)
g.add(0, 3, 1)
g.add(1, 3, 3)
g.add(3, 4, 2)
g.add(3, 6, 4)
g.add(3, 5, 8)
g.add(3, 2, 2)
g.routineprint()
g.dijkstra(1, 5)
