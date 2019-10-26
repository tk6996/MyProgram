class BinaryTree:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def postfixToExpressionTree(inputs: list):
    stack = []
    for op in inputs:
        if op in '+-*/%':
            b = stack.pop()
            a = stack.pop()
            stack.append(BinaryTree(op, a, b))
        else:
            stack.append(BinaryTree(op))
    return stack.pop()


priorityoperator = {'+': 1, '-': 1, '*': 2, '/': 2, '%': 2}


def infixToExpressionTree(inputs: list):
    operand = None
    root = None
    child = None
    while inputs != []:
        op = inputs.pop(0)
        if op == ')':
            return root
        elif op in '+-*/%':
            if root is None:
                root = BinaryTree(op, operand)
                child = root
            else:
                pre = None
                cur = root
                while cur.data in '+-*/%' and priorityoperator[op] > priorityoperator[cur.data]:
                    pre = cur
                    cur = cur.right
                if pre is None:
                    root = BinaryTree(op, root)
                    child = root
                else:
                    pre.right = BinaryTree(op, cur)
                    child = pre.right
        else:
            operand =  infixToExpressionTree(inputs) if op == '(' else BinaryTree(op)
            if child is not None:
                child.right = operand
                child = None
    return root


def postOrderExpression(node):
    if node.data in '+-*/%':
        postOrderExpression(node.left)
        postOrderExpression(node.right)
        print(node.data, end=' ')
    else:
        print(node.data, end=' ')


def preOrderExpression(node):
    if node.data in '+-*/%':
        print(node.data, end=' ')
        preOrderExpression(node.left)
        preOrderExpression(node.right)
    else:
        print(node.data, end=' ')


def inOrderExpression(node):
    if node.data in '+-*/%':
        print('(', end=' ')
        inOrderExpression(node.left)
        print(node.data, end=' ')
        inOrderExpression(node.right)
        print(')', end=' ')
    else:
        print(node.data, end=' ')


def ansExpression(node):
    if node.data in '+-*/%':
        operator = {'+': lambda a, b: a+b, '-': lambda a, b: a-b,
                    '*': lambda a, b: a*b, '/': lambda a, b: a/b, '%': lambda a, b: a % b}
        return operator[node.data](ansExpression(node.left), ansExpression(node.right))

    else:
        return float(node.data)


n = infixToExpressionTree(list(input().split(' ')))
print("preorder : ")
preOrderExpression(n)
print()
print("inorder : ")
inOrderExpression(n)
print()
print("postorder : ")
postOrderExpression(n)
print()
print(ansExpression(n))
