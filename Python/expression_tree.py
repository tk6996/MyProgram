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
        return operator[node.data](ansExpression(node.left),ansExpression(node.right))

    else:
        return float(node.data)


n = postfixToExpressionTree(list(input().split(' ')))
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