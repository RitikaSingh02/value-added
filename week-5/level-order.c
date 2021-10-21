/*
Use linked list concept to solve the problem, otherwise you will be disqualified from the contest.
*/

//problem link : https://www.hackerrank.com/contests/third-year-w5/challenges/level-ordering/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left,*right;
};
struct node* create(int n)
{
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->key = n;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node , int key)
{
    if(!node)
        return create(key);
    if(key%4 == 0)
    {
        node ->left = insert(node->left,key);
    }
    else
    {
        node ->right = insert(node->right,key);
    }
    return node;
}
int height(struct node* node)
{
    if(node == NULL)
    {
        return 0;
    }
    int l = height(node->left);
    int r = height(node->right);
    if(l>r)
        return l+1;
    else
        return r+1;
}
void level_order(struct node* root,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        printf("%d ",root->key);//as only root exists
    }
    else if(level>1)
    {
        level_order(root->left,level-1);
        level_order(root->right,level-1);
    }
}
void print_fun(struct node* root)
{
    int h = height(root);
    int i;
    for(i=1;i<=h;i++)
    {
        level_order(root,i);
    }
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        struct node* root = NULL;
        int n,i;
        int arr[1001];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0;i<n;i++)
        {
            root = insert(root,arr[i]);
        }
        print_fun(root);
        printf("\n");
    }
    
    return 0;
}
