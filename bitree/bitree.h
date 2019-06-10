#ifndef _BITREE_H_
#define _BITREE_H_

struct bitree_node{
    int val;
    struct bitree_node *left;
    struct bitree_node *right;

};

struct bitree_node* create_bitree(int n);
void delete_bitree(struct bitree_node *root);
void print_DLR(struct bitree_node *root);
void print_LDR(struct bitree_node *root);
void print_LRD(struct bitree_node *root);


#endif
