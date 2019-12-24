def nextPrime(num: int):
    def binarySearch(prime, num):
        low = 0
        high = len(prime)
        while low < high:
            mid = (low + high) // 2
            if prime[mid] == num:
                return num
            elif num < prime[mid]:
                high = mid 
            else:
                low = mid + 1
        return prime[low]

    def findPrime(num, prime=[2,3]):
        j = 1
        while prime[-1] < num:
            for p in prime:
                if (prime[-1] + 2*j) % p == 0:
                    j += 1
                    break
            else:
                prime.append(prime[-1]+2*j)
                j = 1
        return binarySearch(prime, num)

    return findPrime(num)


class record:
    def __init__(self, key, data):
        self.key = key
        self.data = data

    def __str__(self):
        return ("('", self.key, "\',", self.data, ")")


class HashTable:
    def __init__(self, size=1):
        self.table = [None for _ in range(size)]
        self.size = size
        self.total = 0
        self.timesResize = 0
        self.timesCollision = 0
        self.maxCollisionChain = 0

    def hash(self, string, tablesize):
        sum = 0
        for char in string:
            sum += ord(char)
        return sum % self.size

    def hashHorner(self, string):
        sum = 0
        for char in string:
            sum = (sum << 5) + ord(char)
        return sum % self.size

    def rehash(self, j, firstHV):
        return (j + firstHV) % self.size

    def put(self, key, data):
        if self.total / self.size > 0.5 :
            self.resize()
        print("*** puting %s %d ***" % (key, data))
        firstHashValue = self.hashHorner(key)
        j = 0
        while j < self.size:
            hashValue = self.rehash(j, firstHashValue)
            if self.table[hashValue] == None:
                self.table[hashValue] = record(key, data)
                self.total += 1
                break
            elif self.table[hashValue].key == key:
                print("+++ already have this key, changing data +++")
                self.table[hashValue].data = data
                break
            else:
                j += 1
                self.timesCollision += 1
                print("colission %d at %d" % (j, hashValue))
        if j > self.maxCollisionChain :
            self.maxCollisionChain = j 
        self.printTable()

    def printTable(self):
        print("----- table size =", self.size, ",total =", self.total, "-----")
        for i in range(self.size):
            if self.table[i] != None:
                print("%d : (%s,%d)" %
                      (i, self.table[i].key, self.table[i].data))

    def __setitem__(self, key, data):
        self.put(key, data)

    def get(self, key):
        firstHashValue = self.hashHorner(key)
        j = 0
        while j < self.size:
            hashValue = self.rehash(j, firstHashValue)
            if self.table[hashValue] != None and self.table[hashValue].key == key:
                return self.table[hashValue].data
            else:
                j += 1

    def __getitem__(self, key):
        return self.get(key)
    
    def resize(self):
        self.timesResize += 1
        oldsize = self.size
        self.size = nextPrime(2 * self.size)
        oldtable = self.table
        self.total = 0
        self.table = [None for _ in range(self.size)]
        print('===*** resize from', oldsize , 'to', self.size, '***===')
        for rec in oldtable :
            if rec is not None :
                self.put(rec.key,rec.data)
    @property
    def loadfactor(self):
        return self.total / self.size
    


h = HashTable()
h.put('Ann', 2431)
print()
h.put('Tony', 7222)
print()
h.put('Tony', 7221)
print()
h.put('Jim', 1026)
print()
h.put("Mij", 8127)
print()
h.put("Nan", 5555)
print()
h.put("Nyto", 2222)
print()
h.put("Ramk", 4567)
print()
h.put("Jim", 8127)
print()
h.put("Karm", 5235)
print()
h.put("Tim", 2244)
print()
h.put("Mit", 4554)
print()
print("Times Resizes :",h.timesResize)
print("Load Factor :",h.loadfactor)
print("Times Collision :",h.timesCollision)
print("Max Collision Chain :",h.maxCollisionChain)