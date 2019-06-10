#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

//基于选择排序的链表排序
int list_sort(struct list_node** pphead)
{
    struct list_node  *pold_head=NULL, *pnew_head=NULL, *ptmp=NULL, *pnew_cur=NULL, *pmin=NULL;
    
    int i=0, min=0;

    if( !pphead||!(*pphead) )
        return -1;

    pold_head = *pphead;
    pnew_head = (struct list_node*)calloc(1,sizeof(struct list_node));
    pnew_head->val = 0;
    pnew_head->next = NULL;
    pnew_cur = pnew_head;

    while( pold_head ){
        //找到最小节点
        ptmp = pold_head;
        min = pold_head->val;
        pmin = pold_head;
        while(ptmp){
            if(ptmp->val < min){
                min = ptmp->val;
                pmin = ptmp;
            }
            ptmp = ptmp->next;
        }
        //取出最小节点
        //如果头节点是最小的，取出头节点
        if(pold_head == pmin){
            pnew_cur->next = pold_head;
            pold_head = pold_head->next;
            pnew_cur = pnew_cur->next;
            //如果只剩一个头节点了，退出
            if(pold_head == NULL)
                break;
        }else{
            //找到pmin在老链表中的前一个节点
            ptmp = pold_head;
            while(ptmp){
                if(ptmp->next == pmin)
                    break;
                ptmp = ptmp->next;
            }
            ptmp->next = pmin->next;
            pnew_cur->next = pmin;
            pnew_cur = pnew_cur->next;
            pnew_cur->next = NULL;
        }
    }

    *pphead = pnew_head->next;

    free(pnew_head);

    return 0;
}

int main(int argc, char* argv[])
{
    struct list_node *phead=NULL;
    int len=10;

    if(argc>1){
        len = atoi(argv[1]);
    }

    phead = create_list(len);
    break_list(phead);

    print_list(phead);

    list_sort(&phead);
    print_list(phead);

    printf("delete %d nodes\n",delete_list(phead));
    return 0;
}

