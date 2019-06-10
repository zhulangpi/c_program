#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bitree.h"

static void create_node(struct bitree_node* root, int index, int total)
{
    int i = 0, left_idx = 2*index+1, right_idx = 2*index+2;

    if(!root)
        return;
    
    root->left = NULL;
    root->right = NULL;
    if(index>total){
        return;
    }

    if( left_idx <= total){
        root->left = (struct bitree_node*)calloc(1,sizeof(struct bitree_node));
        root->left->val = rand()%1000;
        create_node(root->left, left_idx, total);
    }

    if( right_idx <= total){
        root->right = (struct bitree_node*)calloc(1,sizeof(struct bitree_node));
        root->right->val = rand()%1000;
        create_node(root->right, right_idx, total);
    }
}

//创建一个节点值随机，n个节点的完全二叉树
//    0              i
//    /\           /  \
//   1  2       2*i+1 2*i+2
//  /\  /\
// 3 4 5  6
struct bitree_node* create_bitree(int n)
{
    struct bitree_node * root =NULL;

    if(n<1)
        return NULL;

    srand((unsigned int)time(NULL));

    root = (struct bitree_node*)calloc(1, sizeof(struct bitree_node));
    root->val = rand()%1000;

    create_node(root, 0, n-1);

    return root;
}

void delete_bitree(struct bitree_node *root)
{
    if(!root)
        return;

    delete_bitree(root->left);
    delete_bitree(root->right);
    free(root);
}

//DLR 先序遍历
 static void DLR_bitree(struct bitree_node* root)
{
    if(!root)
        return;
    printf("%d ",root->val);
    DLR_bitree(root->left);
    DLR_bitree(root->right);
}

void print_DLR(struct bitree_node *root)
{
    printf("DLR:\n");
    DLR_bitree(root);
    printf("\n");
}

//LDR 中序遍历
static void LDR_bitree(struct bitree_node* root)
{
    if(!root)
        return;
    LDR_bitree(root->left);
    printf("%d ",root->val);
    LDR_bitree(root->right);
}

void print_LDR(struct bitree_node *root)
{
    printf("LDR:\n");
    LDR_bitree(root);
    printf("\n");
}

//LRD 后序遍历
static void LRD_bitree(struct bitree_node* root)
{
    if(!root)
        return;
    LRD_bitree(root->left);
    LRD_bitree(root->right);
    printf("%d ",root->val);
}

void print_LRD(struct bitree_node *root)
{
    printf("LRD:\n");
    LRD_bitree(root);
    printf("\n");
}

