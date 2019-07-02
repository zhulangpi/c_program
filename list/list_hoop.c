#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char* argv[])
{
    struct list_node *phead=NULL, *ptmp=NULL;
    int hoop_length;

    phead = create_list(10);
    break_list(phead);
    print_list(phead);
    ptmp = phead;
    while(ptmp->next)
        ptmp = ptmp->next;

    ptmp->next = phead->next->next->next;

    if(ptmp=list_have_hoop(phead, &hoop_length))
        printf("list has hoop with %d nodes, and the entry is %d\n", hoop_length, ptmp->val );
    list_break_hoop(phead);
    print_list(phead);
    delete_list(phead);
    return 0;
}

