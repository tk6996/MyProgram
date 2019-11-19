import random


def quickSort(lists,pivot_type):
    count = 0

    def partition(begin, end, pivot_type):
        nonlocal count
        nonlocal lists
        if end - begin < 1:
            return None
        prev_begin = begin
        prev_end = end
        if pivot_type == 2:
            lists[begin], lists[end] = lists[end], lists[begin]
        elif pivot_type == 3:
            mid = (begin+end)//2
            if lists[end] > lists[begin]:
                (lists[end], lists[begin]) = (lists[begin], lists[end])
            if lists[begin] > lists[mid]:
                (lists[begin], lists[mid]) = (lists[mid], lists[begin])
            if lists[end] > lists[begin]:
                (lists[end], lists[begin]) = (lists[begin], lists[end])
        pivot_value = lists[begin]
        begin += 1
        while begin <= end:
            while begin <= end and lists[begin] < pivot_value:
                count += 1
                begin += 1
            count += 1
            while begin <= end and lists[end] >= pivot_value:
                count += 1
                end -= 1
            count += 1
            if begin < end:
                lists[begin], lists[end] = lists[end], lists[begin]
        lists[prev_begin], lists[end] = lists[end], lists[prev_begin]
        partition(prev_begin, end - 1, pivot_type)
        partition(end + 1, prev_end, pivot_type)
    partition(0, len(lists) - 1, pivot_type)
    print(count,"==>",end=' ')
    print(lists)


#lists = [10, 99, 85, 12, 36, 47, 97, 35, 62, 44, 33, 11, 63, 13, 18, 29]
#lists = [ i for i in range(21)]
print("*** Quicksort with different pivot ***" "\r\n"\
      "*** Count the number of comparison ***" "\r\n"\
      "   1. pivot at first position" "\r\n"\
      "   2. pivot at end position" "\r\n"\
      "   3. pivot is mid value of first middle and end""\r\n"\
      "       excluding comparison of pivot finding"         )
lists = list(map(int,filter(lambda x : x,input("Enter some numbers : ").split(' '))))
print("#1 - ",end='')
quickSort(lists[:],1)
print("#2 - ",end='')
quickSort(lists[:],2)
print("#3 - ",end='')
quickSort(lists[:],3)
