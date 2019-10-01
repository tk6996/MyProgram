#include <stdio.h>
#include <stdlib.h>
#define Type int
struct TreeNode
{
    Type data;
    struct TreeNode *lnext;
    struct TreeNode *rnext;
};
typedef struct TreeNode TreeNode;
TreeNode *constructorTree(Type data)
{
    TreeNode *this = calloc(1, sizeof(*this));
    this->data = data;
    return this;
}
TreeNode *addLeaf(TreeNode *root, TreeNode *leaf)
{
    if (leaf == NULL)
        exit(1);
    if (root != NULL)
    {
        if (leaf->data < root->data)
        {
            root->lnext = addLeaf(root->lnext,leaf);
            return root;
        }
        else
        {
            root->rnext = addLeaf(root->rnext,leaf);
            return root;
        }
    }
    else
        return leaf;
}
TreeNode *maxValueTree(TreeNode *root)
{
    if(root == NULL) return NULL;
    TreeNode *prev = NULL;
    while (root->rnext)
    {
        prev = root;
        root = root->rnext;
    }
    if(prev)
    {

        if(root->lnext)
            prev->rnext = root->lnext;
        else
            prev->rnext = NULL;
    }
    return root;
}
Type popMaxValueTree(TreeNode **root)
{
    if(*root == NULL) return -1;
    TreeNode *max = maxValueTree(*root);
    int val = max->data;
    if(*root == max)
    {
        if(max->lnext)
            *root = max->lnext;
        else
            *root = NULL;
    }
    free(max);
    return val;
}
void freeTree(TreeNode* root)
{
    if (root->lnext)
        freeTree(root->lnext);
    if (root->rnext)
        freeTree(root->rnext);
    free(root);
}
int main()
{
    TreeNode *root = NULL;
    int line;
    scanf("%d", &line);
    for (int i = 0; i < line; i++)
    {
        char c[2];
        scanf("%1s", c);
        if (*c == 'P')
        {
            int val;
            scanf("%d",&val);
            root = addLeaf(root,constructorTree(val));
        }
        else
        {
            printf("%d\n",popMaxValueTree(&root));
        }
    }
    freeTree(root);
    return 0;
}