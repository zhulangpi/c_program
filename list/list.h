#ifndef _LIST_H_
#define _LIST_H_


struct list_node{
        int val;
        struct list_node *prev;
        struct list_node *next;
};


extern struct list_node* create_list(int len);
extern int break_list(struct list_node *phead);
extern int print_list(struct list_node *phead);
extern int delete_list(struct list_node* phead);
extern struct list_node* list_have_hoop(struct list_node *phead, int *length);
extern int list_break_hoop(struct list_node *phead);

#endif
