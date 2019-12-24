from random import randint


def bubbleSort(arr: list):
    for t in range(len(arr)):
        swap = False
        for ind in range(len(arr)-1, t, -1):
            if arr[ind] < arr[ind - 1]:
                swap = True
                arr[ind], arr[ind - 1] = arr[ind - 1], arr[ind]
        if not swap:
            break
        # print(arr)


def selectionSort(arr: list):
    for t in range(len(arr)):
        minIndex = t
        for ind in range(t+1, len(arr)):
            if arr[ind] < arr[minIndex]:
                minIndex = ind
        arr[t], arr[minIndex] = arr[minIndex], arr[t]
        print(arr)


def insertionSort(arr: list):
    for t in range(1, len(arr)):
        temp = arr[t]
        for ind in range(t, 0, -1):
            if temp < arr[ind - 1]:
                arr[ind] = arr[ind - 1]
            else:
                arr[ind] = temp
                break
        else:
            arr[0] = temp
        print(arr)


def shellSort(arr: list, inc=None):
    if inc is None:
        n = len(arr)
        inc = []
        while n > 1:
            n //= 2
            inc.append(n)

    for i in inc:
        for start in range(i):
            for t in range(start+i, len(arr), i):
                temp = arr[t]
                for ind in range(t, start, -i):
                    if temp < arr[ind - i]:
                        arr[ind] = arr[ind - i]
                    else:
                        arr[ind] = temp
                        break
                else:
                    arr[start] = temp
                print(arr)


def heapSort(arr: list):
    def heapify(arr, ind, size):
        temp = arr[ind]
        while ind < size:
            maxChild = temp
            if 2*ind + 1 < size and arr[2*ind + 1] > maxChild:
                maxChild = arr[2*ind + 1]
            if 2*ind + 2 < size and arr[2*ind + 2] > maxChild:
                maxChild = arr[2*ind + 2]
            arr[ind] = maxChild
            if maxChild == temp:
                break
            else:
                if maxChild == arr[2 * ind + 1]:
                    ind = 2 * ind + 1
                else:
                    ind = 2 * ind + 2

    for ind in range(((len(arr)-1)-1)//2, -1, -1):
        heapify(arr, ind, len(arr))
    # print(arr)
    for size in range(len(arr) - 1, 0, -1):
        arr[size], arr[0] = arr[0], arr[size]
        heapify(arr, 0, size)
        # print(arr)


def print90(heap: list):
    def binaryprint(index, level=0):
        nonlocal heap
        if index < 0 or index >= len(heap):
            return
        binaryprint(2*index+2, level+1)
        print('  '*level, heap[index], sep='')
        binaryprint(2*index+1, level+1)
    binaryprint(0)


def mergeSort(arr: list):
    size = []
    n = 1
    while n < len(arr):
        size.append(n)
        n *= 2
    for s in size:
        for ind in range(0, len(arr), 2*s):
            a = arr[ind:ind+s]
            b = arr[ind+s:ind+2*s]
            while a != [] and b != []:
                if a[0] < b[0]:
                    arr[ind] = a.pop(0)
                else:
                    arr[ind] = b.pop(0)
                ind += 1
            while a != []:
                arr[ind] = a.pop(0)
                ind += 1
            while b != []:
                arr[ind] = b.pop(0)
                ind += 1
            print(arr)


def quickSort(arr):
    size = [[0, len(arr) - 1]]
    while size != []:
        low, high = size.pop()
        if low > high:
            continue
        mid = (low + high) // 2
        if arr[high] > arr[low]:
            arr[high], arr[low] = arr[low], arr[high]
        if arr[low] > arr[mid]:
            arr[low], arr[mid] = arr[mid], arr[low]
        if arr[high] > arr[low]:
            arr[high], arr[low] = arr[low], arr[high]
        pviot = arr[low]
        i = low + 1
        j = high
        while not (i > j):
            if arr[i] <= pviot:
                i += 1
            else:
                arr[i], arr[j] = arr[j], arr[i]
                j -= 1
        arr[low], arr[j] = arr[j], arr[low]
        size.append([j+1, high])
        size.append([low, j-1])


arr = [randint(-100, 100) for i in range(10)]
print(arr)
quickSort(arr)
print(arr)
