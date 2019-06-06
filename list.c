#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//创建一个头为*phead，长度为len，每个节点val为随机的双向循环链表
//返回创建的链表长度
int create_list( struct list_node **phead , int len)
{
    int i=0,val=0,l=0;
    struct list_node *pprev=NULL,*ptmp=NULL;

    if(!len)
        return 0;

    srand( (unsigned int)time(NULL) );
    
    *phead = (struct list_node*)malloc(sizeof(struct list_node));

    if(NULL==*phead)
        return 0;

    (*phead)->val = rand()%1000;

    ptmp = *phead;

    for(i=0;i<len;i++){
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

    (*phead)->prev = ptmp;
    ptmp->next = *phead;

    return l;
}

//打印链表，返回节点数
int print_list(struct list_node *phead)
{
    struct list_node *ptmp = phead;
    int i=0;
    
    while(ptmp){

        printf("%3d-> ", ptmp->val);

        if( 0==( ++i%10) )
            printf("\n");

        ptmp = ptmp->next;

        if(ptmp==phead)
            break;
    }

    printf("\n");
    printf("list length is %d\n", i);

    return i;
}

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


int main()
{
    struct list_node *phead;

    create_list(&phead, 20);

    print_list(phead);

    printf("delete node %d\n",delete_list(phead));
    return 0;
}




