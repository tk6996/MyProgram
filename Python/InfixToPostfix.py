def infixTopostfixCalculation(infix : str) :
    outStackOperator = { '+' : 3, '-' : 3, '*' : 5, '/' : 5, '^' : 8, '(' : 9 , ')' : 1}
    inStackOperator = {'+' : 3, '-' : 3, '*' : 5, '/' : 5, '^' : 7, '(' : 0 }
    postfix = ''
    stackOfOperator = []
    variable = set()
    varvalue = {}
    for op in infix :
        if  'a' <= op <= 'z' or 'A' <= op <= 'Z' :
            postfix += op
            variable.add(op)
        elif op in outStackOperator.keys() :
            while( len(stackOfOperator) and inStackOperator[stackOfOperator[len(stackOfOperator) - 1]] >= outStackOperator[op]) :
                postfix += stackOfOperator.pop()
            if op == ')' :
                stackOfOperator.pop()
            else :
                stackOfOperator.append(op)
    postfix += ''.join(stackOfOperator[::-1])
    
    for v in sorted(variable):
        varvalue.update({v : int(input('[ %s ] = ' %(v)))})
    return postfixCalculation(postfix,varvalue)
def postfixCalculation(postfix : str, memory_var : dict) :
    stackVar = []
    for op in postfix :
        if  'a' <= op <= 'z' or 'A' <= op <= 'Z' :
            stackVar.append(memory_var[op])
        elif op in '+-*/^' :
            second = stackVar.pop()
            frist = stackVar.pop()
            if op == '+' : stackVar.append(frist + second)
            elif op == '-' : stackVar.append(frist - second)
            elif op == '*' : stackVar.append(frist * second)
            elif op == '/' : stackVar.append(frist / second)
            elif op == '^' : stackVar.append(frist ** second)
    return stackVar.pop()
print(infixTopostfixCalculation(input()))