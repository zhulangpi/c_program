#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

//Q:一条单向链表，反转从m到n的所有节点, 0<m<n<链表长度-1
//输入{0,1,2,3,4,5,6}, m=3, n=5, 
//输出{0,1,2,5,4,3,6}
//
//p1    p3  p4   ...    p2
//m-1   m   m+1  ...    n+1
//
//p1    p3  p4   ...    p2
//m-1   m+1 m+2  ...    m   n+1
int list_reverse(struct list_node *phead, int m, int n)
{
    int size = n-m+1, i=0;
    struct list_node *p1 = phead, *p2 = NULL, *p3 = NULL, *p4 = NULL;

    if(!phead)
        return -1;

    for( i=0; i<m-1; i++ ){
        p1 = p1->next;
    }
    //now, p1 @ m-1

    p3 = p1->next;
    //now, p3 @ m

    p4 = p3->next;
    p2 = p3;
    //now, p4 @ m+1, p2 @ m

    //一共循环n+1-m次，第1次p2 @ m+1，第n-m+1次 p2 = n + 1
    for( i=m; i<n+1; i++){
        p2 = p2->next;
    }
    //now, p2 @ n+1

    for(i=0; i<size; i++ ){
        p4 = p3->next;
        p3->next = p2;
        p2 = p3;
        p3 = p4;
    }

    p1->next = p2;

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

    print_list(phead);

    list_reverse(phead, 1,9);

    print_list(phead);

    printf("delete %d nodes\n",delete_list(phead));
    return 0;
}

