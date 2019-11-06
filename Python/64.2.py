import random
def minAndmax(arr,index):
    if index < 0 :
        return [None,None]
    if index < 1 :
        return [arr[0],arr[0]]
    (minV,maxV) = minAndmax(arr,index - 2)
    if arr[index -1] < arr[index]:
        minC = arr[index -1]
        maxC = arr[index]
    else :
        minC = arr[index]
        maxC = arr[index - 1]
    return [min(minV,minC),max(maxV,maxC)] if minV != None else [minC,maxC]
print(minAndmax([random.randint(-1000,1000) for i in range(100)],99))