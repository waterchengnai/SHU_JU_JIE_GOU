#include<stdio.h>
//ջ�����޵�˳���,����Ҳ��Ϊ˳��ṹ������ṹ
//�����Ƚ���˳��ṹ��ʵ�֣���ʽ��125��

/*#define MAXLEN 100

//˳��ṹ������Ҫ����һ���ṹ��
//�ṹ�����һ������ͼ�¼���ȵ�len
//����ջ����top,����ʾջ���ı���������len
//
//typedef struct {
//	int arr[MAXLEN];
//	int top;
//}Stack;
////������ֱ������������Ƕ�̬�ڴ����ķ�ʽ
////�������涨��ʱ�ر���ָ��Ķ��巽��
////��Ϊ��������Ҫ�ٶ�̬�ڴ����,����ָ��û�з����ַ
//
////��ʼ��
//
//void initStack(Stack *p)
//{
//	p->top = -1;
//}
//-1��ʾtop,Ҳ���������±�Ϊ-1

//����չʾ��̬�ڴ����Ķ��巽��
//��ֻ���нṹ�嶨��ͳ�ʼ��ʱ�Ĳ�ͬ


#include<stdlib.h>
typedef struct {
	int* arr;
	int top;
}Stack;

Stack* initStack()
{
	Stack* p=(Stack*)malloc(sizeof(Stack));
	p->arr = (int*)malloc(sizeof(int*) * MAXLEN);
	p->top = -1;
	return p;
}



//�ж�ջ�Ƿ�Ϊ��ջ

void isEmpty(Stack* p)
{
	if (p->top == -1)
	{
		printf("ջΪ��ջ");
	}
}

//�ж�ջ�Ƿ�ջ��

void isfull(Stack* p)
{
	if (p->top == MAXLEN)
	{
		printf("ջ��");
	}
}

//��ջ

void push(Stack* p,int data)
{

	if (p->top == MAXLEN)
	{
		printf("ջ����");
		return 0;
	}
	p->top++;
	p->arr[p->top] = data;
}

//��ջ

void pop(Stack* p,int* e)
{
	if (p->top == -1)
	{
		printf("ջΪ��ջ");
		return 0;
	}
	*e = p->arr[p->top];
	p->top--;
}

//���ջ��Ԫ��

void gettop(Stack* p, int* e)
{
	if (p->top == -1)
	{
		printf("ջΪ��ջ");
		return 0;
	}
	*e = p->arr[p->top];

}


int main()
{
	Stack* st=initStack();
	int* e=st->arr;
	push(st, 4);
	push(st, 3);
	push(st, 2);
	pop(st, e);
	printf("%d\n", *e);
	gettop(st, e);
	printf("%d\n", *e);
}*/

//��ʽ�ṹ
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack* next;
}Stack;

//��Ȼ��ջ����ô��Ҫ����ջ����ջ�ף����������˵�׽ڵ��β�ڵ㶼����
//��Ϊ�˼򵥻���һ�㽫�׽ڵ㵱ջ���������ò���

//��ʼ���������������ȫһ��

Stack* initStack()
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = 0;
	p->next = NULL;
	return p;
}

//�ж������Ƿ�Ϊ��

void isempty(Stack* s)
{
	if (s->next == NULL)
	{
		printf("ջ�ǿյ�");
	}
}

//��ջ,��ͷ�巨һģһ��
void push(Stack* s, int inputdata)
{
	//L�ǳ�ʼ���������յ�������
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = inputdata;
	p->next = s->next;
	s->next = p;
}

//��ջ,ֱ��ɾ���׽ڵ����Ľڵ㲢��¼ֵ
int pop(Stack* s,int *e)
{
	if (s->next == NULL)
	{
		printf("ջ�ǿյ�");
		return 0;
	}
	Stack* temp = s->next;
	*e = temp->data;
	s->next = temp->next;
	free(temp);
}

//���ջ��Ԫ��
int gettop(Stack* s, int* e)
{
	if (s->next == NULL)
	{
		printf("ջ�ǿյ�");
		return 0;
	}
	*e = s->next->data;
	return 1;
}

//int main()
//{
//	Stack* s = initStack();
//	push(s, 5);
//	push(s, 3);
//	push(s, 2);
//	push(s, 1);
//	int e;
//	pop(s, &e);
//	printf("%d\n", e);
//	gettop(s, &e);
//	printf("%d\n", e);
//}
