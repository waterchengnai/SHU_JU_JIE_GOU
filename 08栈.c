#include<stdio.h>
//栈是受限的顺序表,所以也分为顺序结构和链表结构
//这里先进行顺序结构的实现，链式在125行

/*#define MAXLEN 100

//顺序结构首先是要创建一个结构体
//结构体包含一个数组和记录长度的len
//但是栈中用top,即表示栈顶的变量代替了len
//
//typedef struct {
//	int arr[MAXLEN];
//	int top;
//}Stack;
////这里是直接用数组而并非动态内存分配的方式
////所以下面定义时回避了指针的定义方法
////因为那样做还要再动态内存分配,否则指针没有分配地址
//
////初始化
//
//void initStack(Stack *p)
//{
//	p->top = -1;
//}
//-1表示top,也就是数组下表为-1

//下面展示动态内存分配的定义方法
//这只会有结构体定义和初始化时的不同


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



//判断栈是否为空栈

void isEmpty(Stack* p)
{
	if (p->top == -1)
	{
		printf("栈为空栈");
	}
}

//判断栈是否栈满

void isfull(Stack* p)
{
	if (p->top == MAXLEN)
	{
		printf("栈满");
	}
}

//进栈

void push(Stack* p,int data)
{

	if (p->top == MAXLEN)
	{
		printf("栈已满");
		return 0;
	}
	p->top++;
	p->arr[p->top] = data;
}

//出栈

void pop(Stack* p,int* e)
{
	if (p->top == -1)
	{
		printf("栈为空栈");
		return 0;
	}
	*e = p->arr[p->top];
	p->top--;
}

//获得栈顶元素

void gettop(Stack* p, int* e)
{
	if (p->top == -1)
	{
		printf("栈为空栈");
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

//链式结构
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack* next;
}Stack;

//既然是栈，那么就要考虑栈顶和栈底，这对链表来说首节点和尾节点都可以
//但为了简单化，一般将首节点当栈顶，这样好操作

//初始化，和链表代码完全一致

Stack* initStack()
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = 0;
	p->next = NULL;
	return p;
}

//判断链表是否为空

void isempty(Stack* s)
{
	if (s->next == NULL)
	{
		printf("栈是空的");
	}
}

//进栈,跟头插法一模一样
void push(Stack* s, int inputdata)
{
	//L是初始化函数接收的首链表
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = inputdata;
	p->next = s->next;
	s->next = p;
}

//出栈,直接删除首节点后面的节点并记录值
int pop(Stack* s,int *e)
{
	if (s->next == NULL)
	{
		printf("栈是空的");
		return 0;
	}
	Stack* temp = s->next;
	*e = temp->data;
	s->next = temp->next;
	free(temp);
}

//获得栈顶元素
int gettop(Stack* s, int* e)
{
	if (s->next == NULL)
	{
		printf("栈是空的");
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
