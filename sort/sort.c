#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *generate_sequence(int length)
{

    int *phead = NULL;
    int i =0;

    phead = (int*)calloc( length, sizeof(int) );
    srand( (unsigned int)time(NULL) );
    for(i=0; i<length; i++){
        phead[i] = rand()%1000;
    }

    return phead;
}

void print_sequence(int *phead, int length)
{
    int i=0;
    for( i=0; i<length;i++){
        printf("%3d ", phead[i]);
        if( (i+1)%10==0 )
            printf("\n");
    }
    if(i%10!=0)
        printf("\n");
}

void delete_sequence(int *phead)
{
    free(phead);
}


void bubble_sort(int *phead, int length)
{
    int tmp=0;
    int i=0,j=0;

    //重复length次
    for(i=0;i<length;i++){
        //每次相邻两个数，大的放后面，小的放前面，
        //第一次最大的数跑到最后，第二次第二大的数跑到倒数第二的位置
        //大数冒到了后面
        for(j=0;j<length-1-i;j++){
            if( phead[j]>phead[j+1] ){
                tmp = phead[j];
                phead[j] = phead[j+1];
                phead[j+1] = tmp;
            }
        }
    }
}

void select_sort(int *phead, int length)
{
    int i=0,j=0;
    int max=0,max_idx=0;
    int tmp = 0;

    //重复length次
    for(i=0;i<length;i++){
        max = phead[0];
        max_idx = 0;
        //比较前length-i个数，找到最大的放末尾
        for(j=0;j<length-i;j++){
            if( phead[j]>=max){
                max_idx = j;
                max = phead[j];
            }
        }
        //交换最大数与末尾
        tmp = phead[max_idx];
        phead[max_idx] = phead[length-i-1];
        phead[length-i-1] = tmp;
    }
}

void insert_sort(int *phead, int length)
{
    int i=0,j=0;
    int tmp=0;

    //默认第0个数是个有序序列，从第1个数开始插入
    for( i=1; i<length; i++){
        tmp = phead[i];
        //如果待插入数已经比前面有序序列最后一个数大，直接跳过此次循环
        if( tmp >= phead[i-1])
            continue;
        //从序列末尾开始往后挪
        for( j=i; j>0;j--){
            //每次移一个
            phead[j] = phead[j-1];
            //找到合适位置插入
            if( tmp >= phead[j-2]){
                phead[j-1] = tmp;
                break;
            //如果到头了，直接插入
            }else if(j==1){
                phead[0] = tmp;
                break;
            }
        }
    }
}

#define swap(m, n)  ({\
    m += n;\
    n = m-n;\
    m = m-n;\
})

void quick_sort(int *phead, int length)
{
    int i=0,j=length-1;
    int tmp = 0;

    if(!phead||length<1)
        return;
    //头尾相等时结束
    while(1){
        while( i<j &&  phead[i]<phead[j] ){
            j--;
        }
        if(i==j)
            break;
        else{
            swap(phead[i],phead[j]);
        }
        while( i<j &&  phead[i]<phead[j] ){
            i++;
        }
        if(i==j)
            break;
        else{
            swap(phead[i],phead[j]);
        }
    }

    quick_sort(phead,i);
    quick_sort(phead+i+1,length-i-1);

}


int main(int argc, char* argv[])
{
    int *phead=NULL;
    int len=10;

    if(argc>1)
        len = atoi(  argv[1] );

    phead = generate_sequence(len);
    print_sequence(phead,len);
    quick_sort(phead,len);
    print_sequence(phead,len);

    delete_sequence(phead);

    return 0;
}

