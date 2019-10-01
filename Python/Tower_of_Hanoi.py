from functools import reduce
from sys import stderr
A,B,C =[],[],[]
def show_current():
    print(reduce(lambda s,t: s+t,A,"Tower A : "))
    print(reduce(lambda s,t: s+t,B,"Tower B : "))
    print(reduce(lambda s,t: s+t,C,"Tower C : "))    
    print("==========================")
def tower_move(source : list,buffer : list,destination: list,layer : int):
    def move_obj(source : list,destination : list):
        destination.append(source.pop())
        show_current()
    if layer < 1 :
        if layer < 0 :
            class Minus_exception(Exception):
                pass
            raise Minus_exception("Minus Move Exception")
        return
    if layer == 1 : 
        move_obj(source,destination)
        return
    tower_move(source,destination,buffer,(layer-1))
    move_obj(source,destination)
    tower_move(buffer,source,destination,(layer-1))
if __name__ == "__main__":
    level = int(input("Tower Of Hanoi Enter Level : "))
    A = [chr(ord('A')+i) for i in range(level)][::-1]
    print("==========================")
    show_current()
    try:
        tower_move(A,B,C,len(A))
    except Exception as e:
        print(e,file=stderr)