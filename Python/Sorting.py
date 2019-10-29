import random


def bubbleSort(arr):
    for i in range(len(arr) - 1, 0, -1):
        for j in range(0, i):
            if arr[j] > arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    return arr


def selectionSort(arr):
    for i in range(len(arr) - 1):
        minIndex = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[minIndex]:
                minIndex = j
        temp = arr[i]
        arr[i] = arr[minIndex]
        arr[minIndex] = temp
    return arr


def insertionSort(arr):
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i
        while j > 0:
            if arr[j-1] > temp:
                arr[j] = arr[j-1]
            else:
                break
            j -= 1
        arr[j] = temp
    return arr


def mergeSort(arr):
    if len(arr) < 2:
        return arr
    lmerge = mergeSort(arr[:len(arr)//2])
    rmerge = mergeSort(arr[len(arr)//2:])
    index = len(arr) - 1
    while index >= 0:
        if lmerge != [] and rmerge != []:
            arr[index] = lmerge.pop() if lmerge[-1] > rmerge[-1] else rmerge.pop()
        elif lmerge != []:
            arr[index] = lmerge.pop()
        else:
            arr[index] = rmerge.pop()
        index -= 1
    return arr


def quickSort(arr):
    def __qsort(low, high):
        nonlocal arr
        if low >= high:
            return
        pivot = random.randint(low, high)
        temp = arr[high]
        arr[high] = arr[pivot]
        arr[pivot] = temp
        i = low
        j = high - 1
        while not (i > j):
            if arr[i] > arr[high]:
                temp = arr[j]
                arr[j] = arr[i]
                arr[i] = temp
                j -= 1
            else:
                i += 1
        temp = arr[high]
        arr[high] = arr[i]
        arr[i] = temp
        __qsort(low, i-1)
        __qsort(i+1, high)
    __qsort(0, len(arr)-1)
    return arr


arr = [random.randint(0, 100) for _ in range(100)]
print(bubbleSort(arr[:]))
print(selectionSort(arr[:]))
print(insertionSort(arr[:]))
print(mergeSort(arr[:]))
print(quickSort(arr[:]))
