#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
typedef struct Linked_List
{
    node *head;
    int size;
}linkedlist;
void startlist(linkedlist* list)
{
    list->head= NULL;
    list->size=0;
}
int insert(linkedlist* list,int obj,int index) 
{
    node *n = (node*)malloc(sizeof(node));
    node *t = list->head;
    node *p = NULL;
    n->data = obj;
    n->next = NULL;
    if(index>list->size)
    {
        return -1;
    }
    else
    {
        while(index)
        {
            p = t;
            t = t->next;
            index--;
        }
        n->next = t;
        if(p!=NULL)
        p->next = n ;
        else list->head = n;
        list->size++;
        return 0;
    }
}
int earse(linkedlist *list,int index)
{
    node *t = list->head;
    node *p = NULL;
    if(index>=list->size)
    {
        return -1;
    }
    else
    {
        while(index)
        {
            p = t;
            t = t->next;
            index--;
        }
        if(p!=NULL)
        p->next = t->next;
        else
        list->head = t->next;
        free(t);
        list->size--;
        return 0;
    }
}
int getVauleAt(linkedlist *list,int index)
{
    if(index>=list->size)
    {
        return 0;
    }
    else
    {
        node *t = list->head;
        while(index)
        {
            t = t->next;
            index--;
        }
        return t->data;
    }
}
node *getNodeAt(linkedlist *list,int index)
{
    if(index>=list->size)
    {
        return NULL;
    }
    else
    {
        node *t = list->head;
        while(index)
        {
            t = t->next;
            index--;
        }
        return t;
    }
}
int getSize(linkedlist *list) {return list->size;}
int addlist(linkedlist *list,int obj){return insert(list,obj,list->size);}
int removelist(linkedlist* list){return earse(list,list->size-1);}
int main(int argc , char* argv[])
{
    linkedlist *l = (linkedlist*)malloc(sizeof(linkedlist));
    startlist(l);
    addlist(l,10);
    addlist(l,9);
    addlist(l,4);
    addlist(l,7);
    insert(l,17,4);
    earse(l,4);
    for(int i=0;i<getSize(l);i++)
    printf("%d\n",getVauleAt(l,i));
    free(l);
    return 0;
}