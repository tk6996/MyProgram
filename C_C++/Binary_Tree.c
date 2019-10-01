#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
typedef struct Queue
{
    TreeNode **data;
    int size;
} Queue;
Queue constructQueue(int capacity)
{
    Queue self;
    self.data = (TreeNode**)calloc(capacity,sizeof(*(self.data)));
    self.size = 0;
    return self;
}
typedef struct
{
    TreeNode *root;
    int size;
} Binary_Tree;
TreeNode *newLeaf(int n)
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    t->data = n;
    t->left = NULL;
    t->right = NULL;
    return t;
}
TreeNode *addLeaf(TreeNode *t, int n)
{
    if (t == NULL)
    {
        return newLeaf(n);
    }
    else
    {
        if (n < t->data)
        {
            t->left = addLeaf(t->left, n);
            return t;
        }
        else
        {
            t->right = addLeaf(t->right, n);
            return t;
        }
    }
}
void startbinarytree(Binary_Tree *t)
{
    t->root = NULL;
    t->size = 0;
}
void addTree(Binary_Tree *t, int n)
{
    t->root == NULL ? t->root = newLeaf(n) : addLeaf(t->root, n);
    t->size++;
}
TreeNode* removeLeaf(TreeNode *t,int n)
{
    if(t == NULL) return NULL;
    if(n == t->data)
    {
        if(t->left == NULL && t->right == NULL)
        {
            free(t);
            return NULL;
        }
        else if(t->left == NULL || t->right == NULL)
        {
            TreeNode *temp = (t->left != NULL) ? t->left : t->right;
            free(t);
            return temp;
        }
        else
        {
            TreeNode *temp = t->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            t->data = temp->data;
            t->right = removeLeaf(t->right,temp->data);
            return t;
        }
    }
    else
    {
        if(n < t->data)
        {
            t->left = removeLeaf(t->left,n);
            return t;
        }
        else
        {
            t->right = removeLeaf(t->right,n);
            return t;
        }
    }
}
void run_tree(int arr[], TreeNode *t, int *index, int Mode)
{
    if (t == NULL)
        return;
    if (Mode == 0)
    {
        *(arr + *index) = t->data;
        *index = *index + 1;
    }
    run_tree(arr, t->left, index, Mode);
    if (Mode == 1)
    {
        *(arr + *index) = t->data;
        *index = *index + 1;
    }
    run_tree(arr, t->right, index, Mode);
    if (Mode == 2)
    {
        *(arr + *index) = t->data;
        *index = *index + 1;
    }
}
void bfsLeaf(int arr[],Queue current,int index)
{
    if(current.size == 0) return;
    Queue next = constructQueue(current.size * 2);
    for(int i = 0;i < current.size ; i++)
    {
        arr[index++] = current.data[i]->data;
        next.data[current.data[i]->left ? next.size++ : next.size] = current.data[i]->left;
        next.data[current.data[i]->right ? next.size++ : next.size] = current.data[i]->right;
    }
    bfsLeaf(arr,next,index);
    free(next.data);
}
int* run_bfstree(int arr[], TreeNode *t)
{
    if(t == NULL)
    {
        free(arr);
        return NULL;
    }
    *(arr) = t->data;
    Queue next = constructQueue(2);
    next.data[t->left ? next.size++ : next.size] = t->left;
    next.data[t->right ? next.size++ : next.size] = t->right;
    bfsLeaf(arr,next,1);
    free(next.data);
    return arr;
}
int *tree_to_array(Binary_Tree *t, int Mode)
{
    int *Array = (int *)malloc(sizeof(int) * t->size);
    if(Mode < 3)
    {
        int index = 0;
        run_tree(Array, t->root, &index, Mode);
    }
    else
    {
        run_bfstree(Array,t->root);   
    }
    return Array;
}
int search_Tree(Binary_Tree *t, int key)
{
    if (t != NULL)
    {
        TreeNode *p = t->root;
        while (p != NULL)
        {
            if (key < p->data)
                p = p->left;
            else if (key > p->data)
                p = p->right;
            else
                return 1;
        }
    }
    return 0;
}
void removeTree(Binary_Tree *t, int n)
{
    if(search_Tree(t,n))
    {
        t->root = removeLeaf(t->root,n);
        t->size--;
    }
}
int main(int argc, char const *argv[])
{
    Binary_Tree *t = (Binary_Tree *)malloc(sizeof(Binary_Tree));
    startbinarytree(t);
    addTree(t, 34);
    addTree(t, 20);
    removeTree(t,20);
    addTree(t, 59);
    addTree(t, 12);
    addTree(t, 23);
    addTree(t, 42);
    addTree(t, 66);
    addTree(t, 9);
    removeTree(t,-59);
    addTree(t, 45);
    removeTree(t , 34);
    int *arr = tree_to_array(t, 3);
    for (int a = 0,b = 0; a < t->size; a++)
    {
        if (arr[a] != 0)
            printf("%d ", arr[a]);
    }
    free(arr);
    printf("\n%d\n",t->size);
    //printf("\n%d", search_Tree(t, 5));
    return 0;
}
