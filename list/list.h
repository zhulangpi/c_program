#ifndef _LIST_H_
#define _LIST_H_


struct list_node{
        int val;
        struct list_node *prev;
        struct list_node *next;
};


extern int create_list( struct list_node **phead , int len);
extern int print_list(struct list_node *phead);
extern int delete_list(struct list_node* phead);


#endif
