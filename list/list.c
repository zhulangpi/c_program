#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//长度为len，每个节点val为随机的双向循环链表
//返回链表头
struct list_node* create_list( int len)
{
    int i=0,val=0,l=0;
    struct list_node *phead=NULL, *pprev=NULL,*ptmp=NULL;

    if(!len)
        return NULL;

    srand( (unsigned int)time(NULL) );
    
    phead = (struct list_node*)malloc(sizeof(struct list_node));

    if(NULL==phead)
        return 0;

    phead->val = rand()%1000;

    ptmp = phead;

    for(i=1;i<len;i++){
        pprev = ptmp;
        ptmp = (struct list_node*)malloc(sizeof(struct list_node));

        pprev->next = ptmp;

        if( NULL==ptmp ){
            ptmp = pprev;
            break;
        }

        ptmp->prev = pprev;
        ptmp->val = rand()%1000;
        l++;
    
    }

    phead->prev = ptmp;
    ptmp->next = phead;

    return phead;
}

//断开循环链表的头尾
int break_list(struct list_node *phead)
{
    struct list_node *ptmp=NULL;
    if(!phead)
        return -1;

    if(phead->prev)
        phead->prev->next = NULL;
    else{
        ptmp = phead;
        while(ptmp->next){
            ptmp=ptmp->next;
        }
        ptmp->next=NULL;
    }

    phead->prev = NULL;

    return 0;
}


//打印链表，返回节点数
int print_list(struct list_node *phead)
{
    struct list_node *ptmp = phead;
    int i=0;
    
    while(ptmp){
        printf("%3d", ptmp->val);
        if(ptmp->next)
            if(ptmp->next->prev==ptmp)
                printf("<->");
            else
                printf(" ->");

        if( 0==(++i%10) )
            printf("\n");

        ptmp = ptmp->next;

        if(ptmp==phead)
            break;
    }

    if( 0!=( i%10) )
        printf("\n");
    printf("list length is %d\n", i);

    return i;
}

//free整个链表
int delete_list(struct list_node* phead)
{
    int i=0;
    struct list_node *ptmp = phead, *pprev = NULL;

    while(ptmp){

        pprev = ptmp;
        ptmp = pprev->next;

        free(pprev);

        i++;

        if(ptmp==phead)
            break;
    }

    return i;
}

