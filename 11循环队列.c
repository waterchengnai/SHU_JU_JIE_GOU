//循环队列解决的是一般队列的一些问题
//比如前面空余太多,此时用一般挪格子效率太慢

#include<stdio.h>

#define MAXLEN 100

typedef struct {
	int front;
	int rear;
	int queue[MAXLEN];
}queue;

////初始化
//queue* initqueue(queue* Q)
//{
//	Q->front = 0;
//	Q->rear = 0;
//	return Q;
//}

//循环链表代码的实现其实是进队和出队中rear,front的自增方式改变实现的,使其的值一直再0~MAXLEN-1

//进栈
//这里有两个版本,分别是rear指向尾节点还是尾节点下一个节点

//这一版是rear指向尾节点下一个节点

//int equeue(queue *Q,int push)
//{
//	//首先判断队列满了没,但是循环队列判断满没满方式不同
//	if ((Q->rear + 1) % MAXLEN == Q->front)
//	{
//		//这里这样写是因为循环链表的特性
//		//但这里有bug,会使最后"填满"时有一个空的格子杯rear占着,但不做考虑
//		printf("真的满了");
//		return 0;
//	}
//	Q->queue[Q->rear] = push;
//	Q->rear= (Q->rear + 1) % MAXLEN;
//	return 1;
//}

//在这一版中,rear指向尾节点,每次往下一个节点插值
//而且初始化要改变

//初始化
queue* initqueue(queue* Q)
{
	Q->front = 0;
	Q->rear = MAXLEN-1;
	return Q;
}
int flag = 0;
int equeue(queue* Q, int push)
{
	
	//首先判断队列满了没,但是循环队列判断满没满方式不同
	if ((Q->rear + 1) % MAXLEN == Q->front&&flag)
	{
		printf("真的满了");
		return 0;
	}
	if (!flag )
	{
		flag++;
	}
	Q->rear = (Q->rear + 1) % MAXLEN;
	Q->queue[Q->rear] = push;
	return 1;
}

//出队列

int oqueue(queue* Q)
{
	//首先判断是否队列是否是空的
	if (Q->front == Q->rear)
	{
		printf("队列是空的\n");
		return -1;
	}
	int e = Q->queue[Q->front];
	Q->front++;
	return e;
}

//获取队头数据

int getQtop(queue* Q)
{
	//首先判断是否队列是否是空的
	if (Q->front == Q->rear)
	{
		printf("队列是空的,无法获取\n");
	}
	else
	{
		int top;
		top = Q->queue[Q->front];
		return top;
	}
}
int main()
{
	queue Q;
	initqueue(&Q);
	equeue(&Q, 1);
	equeue(&Q, 2);
	equeue(&Q, 3);
	equeue(&Q, 5);
	equeue(&Q, 4);
	int e = oqueue(&Q);
	printf("%d\n", e);
	e = oqueue(&Q);
	printf("%d\n", e);
	e = getQtop(&Q);
	printf("%d\n", e);
}