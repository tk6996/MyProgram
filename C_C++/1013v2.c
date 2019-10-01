#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int begin;
    int end;
} Subrange;
struct Stack
{
    int data[10];
    int size;
};
typedef struct Stack Stack;
void push_stack(Stack *this, int val)
{
    this->data[(this->size)++] = val;
}
int pop_stack(Stack *this)
{
    return this->data[--(this->size)];
}
int top_stack(Stack *this)
{
    return this->data[(this->size) - 1];
}
Stack *constructStack()
{
    Stack *this = calloc(1, sizeof(Stack));
    return this;
}
void readOperation(Stack **operation, int line)
{
    for (int i = 0; i < line; i++)
    {
        operation[i] = constructStack();
        do
        {
            int val;
            scanf("%d", &val);
            push_stack(operation[i], val);
        } while (top_stack(operation[i]));
        pop_stack(operation[i]);
    }
}
int checkPriority(const char *ex, Subrange r)
{
    unsigned char met = 0;
    int inner = 0;
    for (int i = r.begin; i != r.end; ++i)
    {
        if (ex[i] == '(')
        {
            inner++;
            met |= 0b1000;
        }
        else if (ex[i] == ')')
            inner--;
        else if (inner == 0)
        {
            switch (ex[i])
            {
            case '+':
                met |= 0b0001;
                break;
            case '*':
                met |= 0b0010;
                break;
            case '^':
                met |= 0b0100;
                break;
            default:
                break;
            }
        }
    }
    return met & 0b0001 ? 0 : met & 0b0010 ? 1 : met & 0b0100 ? 2 : met & 0b1000 ? 3 : -1;
}
Subrange splitExpreesion(const char *ex, Stack *op, Subrange r)
{
    const char *sign = "+*^";
    int op_order = 0;
    Subrange new_r = r;
    while (op_order < op->size)
    {
        int order = op->data[op_order++];
        int priority = checkPriority(ex, r);
        int inner = 0;
        int met = 0;
        int i;
        for (i = r.begin; i != r.end; ++i)
        {
            if (ex[i] == '(')
            {
                if (inner == 0 && priority == 3)
                {
                    if(--order == 0) new_r.begin = i + 1;
                }
                inner++;
            }
            else if (ex[i] == ')')
            {
                if (--inner == 0 && priority == 3 && order == 0)
                {
                    new_r.end = i;
                    break;
                }
            }
            else if (inner == 0 && ex[i] == sign[priority])
            {
                new_r.end = i;
                if(--order == 0)
                    break;
                new_r.begin = i + 1;
            }
        }
        if(i == r.end && priority != 3){
            new_r.end = i ;
            order--;
        }
        r = new_r;
        if(order != 0) 
            {
                Subrange temp = {-1,-1};
                return temp;
            }
    }
    return r ;
}
void printOperation(Stack *op)
{
    if (op->size)
    {
        printf("op(%d,", pop_stack(op));
        printOperation(op);
        printf(")");
    }
    else
    {
        printf("p");
    }
}
void printExpreesion(const char *ex,Subrange r){
    putchar('=');
    if(r.begin == -1) puts("null");
    else
    {
        for(int i = r.begin ; i != r.end ; ++i){
            putchar(ex[i]);
        }
        putchar('\n');
    }
}
int main(void)
{
    char *expression = gets(malloc(65));
    int line;
    scanf("%d", &line);
    Stack **operation = malloc(sizeof(*operation) * line);
    readOperation(operation, line);
    for (int i = 0; i < line; i++)
    {
        Subrange temp = {0,strlen(expression)};
        temp = splitExpreesion(expression,operation[i],temp);
        //printf("%d,%d\n",temp.begin,temp.end);
        printOperation(operation[i]);
        printExpreesion(expression,temp);
        free(operation[i]);
    }
    free(operation);
    free(expression);
}