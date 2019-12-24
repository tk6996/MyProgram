class Graph():
    def __init__(self, size):
        self.size = size
        self.adjancecyMatrix = [[0 for _ in range(size)] for _ in range(size)]

    def __str__(self):
        return '\n'.join([str(i) for i in self.adjancecyMatrix])

    def add(self, src, des, weight):
        self.adjancecyMatrix[src][des] = weight

    def depthFirstTraversal(self, start):
        notvisited = set([i for i in range(self.size)])
        dft = []
        stack = [start]
        while stack != [] :
            current = stack.pop()
            if not (current in notvisited) :
                continue
            notvisited.remove(current)
            dft.append(current)
            temp = []
            for i in notvisited:
                if self.adjancecyMatrix[current][i] > 0:
                    temp.append([i, self.adjancecyMatrix[current][i]])
            if temp == []:
                continue
            temp.sort(key=lambda x: x[1])
            while temp != [] :
                stack.append(temp.pop()[0])
        print("Depth First Traversal Orders :", dft)

    def breathFirstTraversal(self,start):
        notvisited = set([i for i in range(self.size)])
        bft = []
        queue = [start]
        while queue != [] :
            current = queue.pop(0)
            if not (current in notvisited) :
                continue
            notvisited.remove(current)
            bft.append(current)
            temp = []
            for i in notvisited :
                if self.adjancecyMatrix[current][i] > 0 :
                    temp.append([i,self.adjancecyMatrix[current][i]])
            if temp == []:
                continue
            temp.sort(key=lambda x : x[1])
            queue.extend(map(lambda x : x[0],temp))
        print("Breath First Traversal Orders :", bft)
    
    def dijkstra(self,start):
        def reheap(arr,comp,start):
            while start >= 0 :
                heapify(arr, comp,start)
                start = (start - 1) // 2

        def heapify(arr,comp,ind):
            tem = arr[ind]
            temp = comp[tem]
            size =len(arr)
            while ind < size:
                minChild = temp
                minIndex = tem
                if 2*ind + 1 < size and comp[arr[2*ind + 1]] < minChild:
                    minChild = comp[arr[2*ind + 1]]
                    minIndex = arr[2*ind + 1]
                if 2*ind + 2 < size and comp[arr[2*ind + 2]] < minChild:
                    minChild = comp[arr[2*ind + 2]]
                    minIndex = arr[2*ind + 2]
                arr[ind] = minIndex
                if minChild == temp:
                    break
                else:
                    if minChild == comp[arr[2 * ind + 1]]:
                        ind = 2 * ind + 1
                    else:
                        ind = 2 * ind + 2
            
        parent = [-1 for _ in range(self.size)]
        shortpath = [float('inf') for _ in range(self.size)]
        heap = [i for i in range(self.size)]
        heap[start] , heap[0] = heap[0] , heap[start]  
        shortpath[start] = 0
        while heap != [] :
            heap[0] , heap[-1] = heap[-1] , heap[0]
            current = heap.pop()
            if len(heap) > 1 :
                heapify(heap,shortpath,0)
            for i in range(self.size):
                #print(shortpath)
                if i in heap and self.adjancecyMatrix[current][i] > 0 and shortpath[current] + self.adjancecyMatrix[current][i] < shortpath[i]:
                    shortpath[i] = shortpath[current] + self.adjancecyMatrix[current][i]
                    reheap(heap,shortpath,heap.index(i))
                    parent[i] = current 
        for i in range(self.size) :
            print (chr(start+ord('A')),"to",chr(i+ord('A')) , " shortest path = " , shortpath[i])

g = Graph(7)
g.add(0,1,1)
g.add(0,2,2)
g.add(1,3,12)
g.add(2,3,11)
g.add(2,5,3)
g.add(3,4,7)
g.add(5,6,4)
g.add(6,4,5)
g.add(6,3,1)
g.depthFirstTraversal(0)
g.breathFirstTraversal(0)
g.dijkstra(0)
