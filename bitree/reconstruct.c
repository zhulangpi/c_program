#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitree.h"


//Q:输入一棵二叉树的前序，中序遍历，重建二叉树
//A:
struct bitree_node* reconstruct( int *DLR, int *LDR, int size )
{
    struct bitree_node *root=NULL;
    int *left_DLR=NULL, *left_LDR=NULL, *right_DLR=NULL, *right_LDR=NULL;
    int i = 0, left_size=0, right_size=0;

    if(size<1)
        return NULL;
    //先创建该子树的根节点
    root = (struct bitree_node*)calloc(1, sizeof(struct bitree_node));
    root->val = DLR[0];

    //找到根节点在子树LDR中的位置
    for(i=0; i<size; i++){
        if(LDR[i]==DLR[0])
            break;
    }

    left_size = i;
    right_size = size - i - 1;

    left_DLR = DLR+1;
    left_LDR = LDR, left_size;
    right_DLR = DLR+left_size+1;
    right_LDR = LDR+left_size+1;

    root->left = reconstruct( left_DLR, left_LDR, left_size );
    root->right = reconstruct( right_DLR, right_DLR, right_size );

    return root;
}

int main(int argc, char* argv[])
{
    struct bitree_node * root  =NULL;
    int total=0;
    int DLR[] = {1,2,4,7,3,5,6,8};
    int LDR[] = {4,7,2,1,5,3,8,6};

//    if(argc>=2)
//        total = atoi(argv[1]);
    root = reconstruct( DLR, LDR, sizeof(DLR)/sizeof(DLR[0]) );

    print_DLR(root);
    print_LDR(root);
    print_LRD(root);

    delete_bitree(root);
    return 0;
}


