#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

//Q:一条双向链表，每2个节点做一次反转
//输入{0,1,2,3,4,5,6} 
//输出{1,0,3,2,5,4,6}
//
//A:
//p4<->p1<->p2<->p3
//p4<->p2<->p1<->p3
int list_swap_pairs(struct list_node **phead)
{
    struct list_node *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4=NULL;
    //参数检查
    if(!phead||!*phead)
        return -1;
    //只有一个节点
    if(!(*phead)->next)
        return 0;

    p1 = p2 = p3 = p4 = *phead;

    if(p1->next){
        *phead = p1->next;
        p2 = p1->next;
        p1->prev = p2;
        p2->prev = NULL;
    }else{
        return -1;
    }
    while( p1 && p2){
        p3 = p2->next;
        p2->prev = p4;
        p2->next = p1;
        p1->prev = p2;
        if(p3&&p3->next)
            p1->next = p3->next;
        else{
            p1->next = p3;
            break;
        }
        p4 = p1;
        p1 = p3;
        if(p1)
            p2 = p1->next;
        else
            p2 = NULL;
    }

    return 0;
}


int main(int argc, char* argv[])
{
    struct list_node *phead=NULL;
    int len=0;

    if(argc>1){
        len = atoi(argv[1]);
    }

    phead = create_list(len);
    break_list(phead);

    print_list(phead);
    list_swap_pairs(&phead);
    print_list(phead);

    printf("delete %d nodes\n",delete_list(phead));
    return 0;
}

