#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkPriority(char *expr)
{
    char *sign = "+*^";
    int priority = -1;
    int met = 0;
    do
    {
        int inner = 0;
        char *ptr = expr;
        priority++;
        while (*ptr != '\0')
        {
            if (*ptr == '(')
                inner++;
            else if (*ptr == ')')
                inner--;
            else if (inner == 0 && sign[priority] == *ptr)
            {
                met++;
            }
            ptr++;
        }
    } while (met == 0 && priority < 3);
    if(priority < 3 || strchr(expr,'(') != NULL)
        return priority;
    else
    {
        return -1;
    }
}
char *split_exp(char *expr, int order)
{
    char *sign = "+*^";
    char *ptr = expr;
    char *word;
    int len = strlen(expr);
    int priority = checkPriority(expr);
    int st , en ;
    if(priority < 3){
        st = 0;
        en = len;
        if(priority == -1){
            if(order == 1){
                word = calloc(en - st + 1, sizeof(char));
                memcpy(word, expr + st, en - st);
                return word;
            }
            else
                return NULL;
        }
    }
    else
    {
        st = 1;
        en = len = len-1;
    }
    int inner = 0;
    int i;
    for (i = 0; i < len; i++, ptr++)
    {
        if (*ptr == '(')
            inner++;
        else if (*ptr == ')')
            inner--;
        else if (inner == 0 && sign[priority] == *ptr)
        {
            order--;
            en = i;
            if (order == 0)
            {
                break;
            }
            st = i + 1;
        }
    }
    if (i == len)
    {
        en = i;
        order--;
    }
    if (order == 0)
    {
        word = calloc(en - st + 1, sizeof(char));
        memcpy(word, expr + st, en - st);
        return word;
    }
    else
        return NULL;
}
int main(void)
{
    char *err_x = "null";
    char expression[65];
    int count;
    gets(expression);
    scanf("%d", &count);
    char **arr_str = calloc(count, sizeof(*arr_str));
    for (int i = 0; i < count; i++)
    {
        char *cur = expression;
        int n;
        scanf("%d", &n);
        while (n)
        {
            char *temp = cur;
            cur = split_exp(cur, n);
            if (temp != expression)
                free(temp);
            if (cur == NULL)
            {
                char buf[65];
                gets(buf);
                arr_str[i] = err_x;
                break;
            }
            scanf("%d", &n);
        }
        if (arr_str[i] == NULL)
            arr_str[i] = cur;
    }
    for (int i = 0; i < count; i++)
    {
        if (arr_str[i])
            puts(arr_str[i]);
    }
    return 0;
}