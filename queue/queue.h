#ifndef _QUEUE_H_
#define _QUEUE_H_


struct queue{
	int *data;
	int front;
	int rear;
	int capacity;//最大容量
};


//初始化一个有size个空位的循环队列，基于数组实现
struct queue *create_queue(int size);
int clear_queue(struct queue *q);
void delete_queue(struct queue *q);
int queue_is_empty(struct queue *q);
int queue_is_full(struct queue *q);
//队列未满 队尾插入操作 插入一个元素 队尾指针+1
int put_queue(struct queue *q, int new_element);
//队列非空 队首弹出元素
int get_queue(struct queue *q);
int queue_front(struct queue *q);
int queue_rear(struct queue *q);
int print_queue(struct queue *q);
#endif

