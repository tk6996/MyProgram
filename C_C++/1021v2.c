#include <stdio.h>
#include <stdlib.h>
#define Type int
struct ListNode
{
    Type data;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
ListNode *constructorList(Type val)
{
    ListNode *this = calloc(1, sizeof(*this));
    this->data = val;
    return this;
}
ListNode *addNode(ListNode *head, ListNode *node)
{
    if (!head)
        return node;
    ListNode *prev = NULL;
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        if (node->data >= ptr->data)
            break;
        prev = ptr;
        ptr = ptr->next;
    }
    if(ptr==head)
    {
        node->next = ptr;
        return node;
    }
    else
    {
        prev->next = node;
        node->next = ptr;
        return head;
    }
}
int maxValueList(ListNode **list)
{
    if(*list == NULL) return -1; 
    int val = (*list)->data;
    ListNode *temp = *list;
    *list = temp->next;
    free(temp);
    return val;
}
void freeList(ListNode *list)
{
    while (list)
    {
        ListNode *temp = list;
        list = list->next;
        free(temp);
    }
}
int main()
{
    ListNode *list = NULL;;
    int line;
    scanf("%d", &line);
    for (int i = 0; i < line; i++)
    {
        char c[2];
        scanf("%1s", c);
        if (*c == 'P')
        {
            int val;
            scanf("%d", &val);
            list = addNode(list,constructorList(val));
        }
        else
        {
            printf("%d\n", maxValueList(&list));
        }
    }
    //freeList(list);
    return 0;
}