def print90(heap: list):
    def binaryprint(index, level=0):
        nonlocal heap
        if index < 0 or index >= len(heap):
            return
        binaryprint(2*index+2, level+1)
        print('  '*level, heap[index], sep='')
        binaryprint(2*index+1, level+1)
    binaryprint(0)

def minHeapify(index,heap,length):
    minIndex = index
    leftIndex = 2*index + 1
    rightIndex = 2*index + 2
    if  leftIndex < length and heap[leftIndex] < heap[minIndex]:
        minIndex = leftIndex
    if rightIndex < length and heap[rightIndex] < heap[minIndex] :
        minIndex = rightIndex
    if minIndex != index :
        temp = heap[index]
        heap[index] = heap[minIndex]
        heap[minIndex] = temp
        minHeapify(minIndex,heap,length)

def insertMinHeap(heap, data):
    print("insert", data)
    heap.append(data)
    index = len(heap) - 1
    parentIndex = (index - 1) // 2
    while parentIndex >= 0:
            if heap[parentIndex] < heap[index]:
                break
            else:
                temp = heap[index]
                heap[index] = heap[parentIndex]
                heap[parentIndex] = temp
                index = parentIndex
                parentIndex = (index - 1) // 2

def deleteMinHeap(heap,length):
    if length <= 0 :
        return
    temp = heap[0]
    heap[0] = heap[length - 1]
    heap[length - 1] = temp
    minHeapify(0,heap,length - 1)
    return temp

def heapSort(heap):
    print('***deleteMin***')
    print('input heap')
    print(heap.__str__().strip('[]').replace(',', ''))
    print90(heap)
    for l in range(len(heap) - 1,0,-1):
        oldlast = heap[l] 
        heap[l] = deleteMinHeap(heap,l + 1)
        newlast = heap[l]
        print('====heap sort====')
        print("deleteMin",newlast,'FindPlaceFor',oldlast)
        print(heap.__str__().strip('[]').replace(',', ''))
        print90(heap)
    return list(reversed(heap))

def createMinHeap(arr: list):
    heap = []
    for data in arr:
        insertMinHeap(heap,data)
        print(heap.__str__().strip('[]').replace(',', ''))
        print90(heap)
        print('-'*9)
    return heap


arr = [68, 65, 32, 24, 26, 21, 19, 13, 16, 14]
harr = createMinHeap(arr)
print(heapSort(harr))
