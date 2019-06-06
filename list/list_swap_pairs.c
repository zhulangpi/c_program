#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//Q:一条双向链表，每2个节点做一次反转
//输入{0,1,2,3,4,5,6} 
//输出{1,0,3,2,5,4,6}
//
int list_swap_pairs(struct list_node **phead)
{
    int size = n-m+1, i=0;
    struct list_node *p1 = *phead;

    return 0;
}


int main()
{
    struct list_node *phead=NULL;

    create_list(&phead, 11);

    print_list(phead);


    print_list(phead);

    printf("delete %d nodes\n",delete_list(phead));
    return 0;
}

