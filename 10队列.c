//队列是先进先出的模式
//那么就有队头front和队尾rear,队头是出口,队尾是入口

//还是先用顺序结构实现

#include<stdio.h>

//#define MAXLEN 100
//
//typedef struct {
//	int front;
//	int rear;
//	int queue[MAXLEN];
//}queue;
//
////初始化
//queue* initqueue(queue* Q)
//{
//	Q->front = 0;
//	Q->rear = 0;
//	return Q;
//}
//
////进队列和出队列的逻辑
////一开始front和rear都是0；
////一进队列那么rear就++，使对应的元素后移
////一出队列front就++，使首元素后移
////当然有些情况还有其他要考虑的，下面再说
//
//int equeue(queue *Q,int push)
//{
//	//首先判断队列满了没 
//	int isreallyfull(queue * Q);
//	if (Q->rear==MAXLEN)//这里我觉得入队是一个一个进的，所以判断条件写的==,下面的函数也是沿着这个逻辑写的
//	{
//		//如果上面条件成立了，就要考虑队列前面还有没有"空弦"
//		if (isreallyfull(Q))
//		{
//			printf("真的满了\n");
//			return 0;
//		}
//
//	}
//	Q->queue[Q->rear] = push;
//	Q->rear++;
//	return 1;
//}
//
// //我们可以发现,rear总指向队尾元素的下一个元素
// 
//int isreallyfull(queue* Q)
//{
//	if (Q->front == 0)
//	{
//		return 1;//表示yes
//	}
//	int temp = Q->front;
//	for (int i = Q->front; i < Q->rear; i++)//这里是<=会越界
//	{
//		Q->queue[i - temp] = Q->queue[i];
//	}
//	Q->front = 0;
//	Q->rear = Q->rear - temp;
//	return 0;
//}
//
////出队列
//
//int oqueue(queue* Q)
//{
//	//首先判断是否队列是否是空的
//	if (Q->front == Q->rear)
//	{
//		printf("队列是空的\n");
//		return -1;
//	}
//	int e = Q->queue[Q->front];
//	Q->front++;
//	return e;//当然这里也可以用指针改变e的值
//}
//
////获取队头数据
//
//int getQtop(queue* Q)
//{
//	//首先判断是否队列是否是空的
//	if (Q->front == Q->rear)
//	{
//		printf("队列是空的,无法获取\n");
//	}
//	else
//	{
//		int top;
//		top = Q->queue[Q->front];
//		return top;
//	}
//}
//int main()
//{
//	queue Q;
//	initqueue(&Q);
//	oqueue(&Q);
//	equeue(&Q, 1);
//	equeue(&Q, 2);
//	oqueue(&Q);
//	equeue(&Q, 3);
//	equeue(&Q, 5);
//	equeue(&Q, 4);
//	int e = oqueue(&Q);
//	printf("%d\n", e);
//	e = getQtop(&Q);
//	printf("%d\n", e);
//}

////队列的链式结构
//#include<stdlib.h>
////链式结构front和rear的确定一般是让首节点做front,尾节点当rear
////当然反过来也行
//typedef struct LQueue{
//	int data;
//	struct LQueue* next;
//}lqueue;
//
//typedef struct {
//	lqueue* front;
//	lqueue* rear;
//}lqueuepointer;
//
////初始化
//lqueuepointer* initlqueue()
//{
//	lqueue* Q = (lqueue*)malloc(sizeof(lqueue));
//	Q->data = 0;
//	Q->next = NULL;
//	lqueuepointer* qp = (lqueuepointer*)malloc(sizeof(lqueuepointer));
//	qp->front = Q;
//	qp->rear = Q;
//	//这里qp已经把Q的活干完了，所以后面对qp操作就行了
//	//根据这里rear的初始化可知,队列空不空可以根据rear是不是等于Q判断
//	//当然还是可以用原来的front是否等于rear
//	//PS:在后面我知道了，front没动过，一直是Q，哈哈😄
//	return qp;
//}
//
////判断是否为空
//int islqempty(lqueuepointer* qp)
//{
//	if (qp->front == qp->rear)
//	{
//		printf("队列是空的\n");
//		return 1;
//	}
//	return 0;
//}
//
////入队
//
////入对的代码是根据哪边认为是队尾决定的，认为队尾是尾节点，那就用尾插法逻辑
////但是很舒服的一点是，我们只对qp操作，而rear可以通过代码一直指向尾节点
////所以比原来要获得尾节点舒服得多
//
//void elqueue(lqueuepointer* qp, int push)
//{
//	lqueue* temp = (lqueue*)malloc(sizeof(lqueue));
//	temp->data = push;
//	qp->rear->next = temp;
//	temp->next = NULL;
//	qp->rear = temp;
//}
//
////出队,跟删首节点思路一样
////下面可以看出，其实front一直没动
//void olqueue(lqueuepointer* qp, int* e)
//{
//	lqueue* temp = qp->front->next;
//	*e = temp->data;
//	qp->front->next = temp->next;
//	//这里要注意一下，别把rear删了
//	if (temp == qp->rear)
//	{
//		qp->rear = qp->front;
//	}
//	free(temp);
//}
//
////获取队头元素
//
//int toplqueue(lqueuepointer* qp, int* e)
//{
//	//首先判断是否为空
//	if (qp->rear == qp->front)
//	{
//		printf("空的\n");
//		return 0;
//	}
//	*e = qp->front->next->data;
//	return 1;
//}
//
//int main()
//{
//	lqueuepointer* qp = initlqueue();
//	elqueue(qp, 10);
//	elqueue(qp, 20);
//	elqueue(qp, 30);
//	int e;
//	olqueue(qp, &e);
//	printf("%d\n", e);
//	toplqueue(qp, &e);
//	printf("%d\n", e);
//}