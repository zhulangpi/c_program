#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"


//初始化一个有size个空位的循环队列，基于数组实现
struct queue *create_queue(int size)
{
	struct queue *q = (struct queue*)calloc(1, sizeof(struct queue) );
	if(!q)
		return NULL;
	q->data = (int*)calloc( sizeof(q->data[0]), size+1);
	if(!q->data){
		printf("malloc queue data failed\n");
		return NULL;
	}
	q->front = 0;
	q->rear = 0;
	q->capacity = size+1;

	return q;
}

int clear_queue(struct queue *q)
{
	if(!q){
		return -1;
	}
	memset(q->data, 0, sizeof(q->data[0])*q->capacity);
	q->front = 0;	
	q->rear = 0;
	return 0;
}

void delete_queue(struct queue *q)
{
	if(!q)
		return;
	free(q->data);
	free(q);
}

int queue_is_empty(struct queue *q)
{
	if(!q){
		return -1;
	}
	if( q->front == q->rear )
		return 1;
	else
		return 0;
}


int queue_is_full(struct queue *q)
{
	if(!q){
		return -1;
	}
	//推断队列是否为满，留一个预留空间不用
	if( (q->rear+1)%q->capacity == q->front ){
		return 1;
	}
	return 0;
}

//队列未满 队尾插入操作 插入一个元素 队尾指针+1
int put_queue(struct queue *q, int new_element)
{
	if(queue_is_full(q) ){
		return -1;
	}
	q->data[q->rear] = new_element;
	q->rear = (q->rear + 1)%q->capacity;
	return 0;
}

//队列非空 队首弹出元素
int get_queue(struct queue *q)
{
	int tmp=0;
	if(queue_is_empty(q)){
		printf("queue is empty\n");
		return -1;
	}
	tmp = q->data[q->front];
	q->front = (q->front+1)%q->capacity;
	return tmp;
}

int queue_front(struct queue *q)
{
	if(queue_is_empty(q)){
		printf("queue is empty\n");
		return -1;
	}
	return q->data[q->front];
}


int queue_rear(struct queue *q)
{
	int i=q->rear;
	if(queue_is_empty(q)){
		printf("queue is empty\n");
		return -1;
	}
	if(i==0){
		i = q->capacity-1;
	}else{
		i--;
	}
	return q->data[i];

}


int print_queue(struct queue *q)
{
	int i=0;
	if(!q){
		return -1;
	}
	i=q->front;
	while( i != q->rear){
		printf("%d\t", q->data[i]);
		i = (i+1)%q->capacity;
	}
	printf("\n");
	return 0;
}


int main( int argc, char* argv[])
{

	struct queue *q;
	int i=0;
	q = create_queue(21);
	clear_queue(q);
	for(i=0;i<q->capacity-5;i++){
		put_queue(q, i);
	}
	printf("%d %d\n",q->front, q->rear);
	print_queue(q);
	
	for(i=0;i<3;i++){
		printf( "%d\n", get_queue(q) );
	}

	printf("%d %d\n",queue_front(q),queue_rear(q));
	print_queue(q);
	delete_queue(q);
	return 0;
}


