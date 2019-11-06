import random


def bubbleSort(arr):
    for i in range(len(arr) - 1, 0, -1):
        swaped = False
        for j in range(0, i):
            if arr[j] > arr[j+1]:
                (arr[j], arr[j+1]) = (arr[j+1], arr[j])
                swaped = True
        if swaped is False:
            break
    return arr


def selectionSort(arr):
    for i in range(len(arr) - 1):
        minIndex = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[minIndex]:
                minIndex = j
        (arr[i], arr[minIndex]) = (arr[minIndex], arr[i])
    return arr


def insertionSort(arr):
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i
        while j >= 1:
            if arr[j-1] > temp:
                arr[j] = arr[j-1]
            else:
                break
            j -= 1
        arr[j] = temp
    return arr


def shellSort(arr):
    gap = len(arr)//2
    while gap > 0:
        for k in range(0, gap):
            for i in range(k + gap, len(arr), gap):
                temp = arr[i]
                j = i
                while j >= k + gap :
                    if arr[j-gap] > temp:
                        arr[j] = arr[j-gap]
                    else:
                        break
                    j -= gap
                arr[j] = temp
        gap //= 2
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
    def partition(low, high):
        nonlocal arr
        if low >= high:
            return
        mid = (low + high)//2
        if arr[mid] <= arr[low] <= arr[high] or arr[mid] >= arr[low] >= arr[high]:
            (arr[low], arr[high]) = (arr[high], arr[low])
        elif arr[low] <= arr[mid] <= arr[high] or arr[low] >= arr[mid] >= arr[high]:
            (arr[mid], arr[high]) = (arr[high], arr[mid])
        i = low
        j = high - 1
        while not (i > j):
            if arr[i] > arr[high]:
                (arr[i], arr[j]) = (arr[j], arr[i])
                j -= 1
            else:
                i += 1
        (arr[i], arr[high]) = (arr[high], arr[i])
        partition(low, i-1)
        partition(i+1, high)
    partition(0, len(arr)-1)
    return arr


arr = [random.randint(0, 100) for _ in range(100)]
# print(bubbleSort(arr[:]))
# print(selectionSort(arr[:]))
# print(insertionSort(arr[:]))
# print(mergeSort(arr[:]))
# print(quickSort(arr[:]))
print(shellSort(arr[:]))
