def counter(cls):
    cls.c += 1
    return cls
@counter
class Decorator(object):
    c = 0
    def __init__(self, obj):
        self.obj = obj
        print('A')
    def __call__(self):
        print('C')
    @classmethod
    def getCounter(cls):
        return cls.c
Decorator(4)
Decorator(4)
print(Decorator.getCounter())