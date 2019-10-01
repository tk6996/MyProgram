#include <stdio.h>
#include <stdlib.h>
typedef struct __attribute__((__packed__))
{
    int quantity;
    double pricePerkilo;
}* Rice;
Rice __Rice__(int price,int quantity)
{
    Rice this = malloc(sizeof(*this));
    if(!this)
    {
        perror("Out Of Memmories");
        exit(1);
    }
    this->quantity = quantity;
    this->pricePerkilo = (double)price/quantity;
    return this;
}
struct ListNode
{
    Rice data;
    struct ListNode *next
};
typedef struct ListNode* ListNode;
ListNode __ListNode__(Rice data)
{
    ListNode this = calloc(1,sizeof(*this));
    if(!this)
    {
        perror("Out Of Memmories");
        exit(1);
    }
    this->data = data;
    return this;
}
void newList(ListNode *this,Rice data)
{
    if(this == NULL)
    {
        abort();
        exit(1);
    }
    ListNode head = *this;
    ListNode ptr = head;
    ListNode prev = NULL;
    while (ptr)
    {
        if(data->pricePerkilo < ptr->data->pricePerkilo)
            break;
        prev = ptr;
        ptr = ptr->next;
    }
    if(ptr == head)
    {
        *this = __ListNode__(data);
        (*this)->next = ptr;
    }
    else
    {
        prev->next = __ListNode__(data);
        prev->next->next = ptr;
    }
}
double pricePopList(ListNode *this,int quantity)
{
    if(*this == NULL)
    {
        abort();
        exit(1);
    }
    double price = 0.0;
    ListNode head = *this;
    while (head && quantity)
    {
        if(quantity < head->data->quantity)
        {
            price += head->data->pricePerkilo * quantity;
            head->data->quantity -= quantity;
            break;
        }
        else
        {
            price += head->data->pricePerkilo * head->data->quantity;
            quantity-= head->data->quantity;
            *this = head->next;
            free(head->data);
            free(head);
            head = *this;
        }
    }
    return price;
}
int main(void)
{
    ListNode *linkedlist = calloc(sizeof(*linkedlist),1);
    int amountRice,amountMerchant;
    scanf("%d",&amountRice);
    for (int i = 0; i < amountRice; i++)
    {
        int P,Q;
        scanf("%d %d",&P,&Q);
        newList(linkedlist,__Rice__(P,Q));
    }
    scanf("%d",&amountMerchant);
    for (int i = 0; i < amountMerchant; i++)
    {
        int q;
        scanf("%d",&q);
        printf("%.3lf\n",pricePopList(linkedlist,q));
    }
    return 0;
}