//ѭ�����н������һ����е�һЩ����
//����ǰ�����̫��,��ʱ��һ��Ų����Ч��̫��

#include<stdio.h>

#define MAXLEN 100

typedef struct {
	int front;
	int rear;
	int queue[MAXLEN];
}queue;

////��ʼ��
//queue* initqueue(queue* Q)
//{
//	Q->front = 0;
//	Q->rear = 0;
//	return Q;
//}

//ѭ����������ʵ����ʵ�ǽ��Ӻͳ�����rear,front��������ʽ�ı�ʵ�ֵ�,ʹ���ֵһֱ��0~MAXLEN-1

//��ջ
//�����������汾,�ֱ���rearָ��β�ڵ㻹��β�ڵ���һ���ڵ�

//��һ����rearָ��β�ڵ���һ���ڵ�

//int equeue(queue *Q,int push)
//{
//	//�����ж϶�������û,����ѭ�������ж���û����ʽ��ͬ
//	if ((Q->rear + 1) % MAXLEN == Q->front)
//	{
//		//��������д����Ϊѭ�����������
//		//��������bug,��ʹ���"����"ʱ��һ���յĸ��ӱ�rearռ��,����������
//		printf("�������");
//		return 0;
//	}
//	Q->queue[Q->rear] = push;
//	Q->rear= (Q->rear + 1) % MAXLEN;
//	return 1;
//}

//����һ����,rearָ��β�ڵ�,ÿ������һ���ڵ��ֵ
//���ҳ�ʼ��Ҫ�ı�

//��ʼ��
queue* initqueue(queue* Q)
{
	Q->front = 0;
	Q->rear = MAXLEN-1;
	return Q;
}
int flag = 0;
int equeue(queue* Q, int push)
{
	
	//�����ж϶�������û,����ѭ�������ж���û����ʽ��ͬ
	if ((Q->rear + 1) % MAXLEN == Q->front&&flag)
	{
		printf("�������");
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

//������

int oqueue(queue* Q)
{
	//�����ж��Ƿ�����Ƿ��ǿյ�
	if (Q->front == Q->rear)
	{
		printf("�����ǿյ�\n");
		return -1;
	}
	int e = Q->queue[Q->front];
	Q->front++;
	return e;
}

//��ȡ��ͷ����

int getQtop(queue* Q)
{
	//�����ж��Ƿ�����Ƿ��ǿյ�
	if (Q->front == Q->rear)
	{
		printf("�����ǿյ�,�޷���ȡ\n");
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