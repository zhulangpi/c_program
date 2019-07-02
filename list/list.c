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

//判断链表是否有环，如果有返回入口节点，否则返回NULL
struct list_node* list_have_hoop(struct list_node *phead, int *length)
{
    struct list_node *p1=phead, *p2=phead, *p3=NULL;
    int i=0, hoop_length=0;

    if(!phead)
        return NULL;

    while(p1->next && p2->next){
        p1 = p1->next;
        p2 = p2->next;
        if(p2->next)
            p2 = p2->next;

        //有环，计算环的长度
        if(p1==p2){
            do{
                hoop_length++;
                p2 = p2->next;
            }while(p2!=p1);
            break;
        }
    }

    if(!hoop_length)
        return NULL;

    if(length)
        *length = hoop_length;

    p1 = p2 = phead;
    for(i=0; i<hoop_length; i++){
        p2 = p2->next;
    }

    while(p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int list_break_hoop(struct list_node *phead)
{
    struct list_node *p1=NULL, *p2=NULL;
    if(!phead)
        return 0;

    p1 = list_have_hoop(phead, NULL);
    if(!p1)
        return 0;
    p2 = p1;
    while(p2->next!=p1){
        p2 = p2->next;
    };
    p2->next = NULL;

    return 1;
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


