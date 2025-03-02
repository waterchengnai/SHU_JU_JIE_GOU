#include<stdio.h>
#include<stdlib.h>

typedef struct suibianba {
	int data;
	struct suibianba* prev;
	struct suibianba* next;
}DL;

//初始化
DL* intit_Dlist()
{
	DL* head = (DL*)malloc(sizeof(DL));
	head->data = 0;
	head->next = NULL;
	head->prev = NULL;
	return head;
}

//头插法

void Dheadinsert(DL* L, int inputdata)
{
	//L是初始化函数接收的首链表
	DL* p = (DL*)malloc(sizeof(DL));
	p->data = inputdata;
	p->next = L->next;
	p->prev = L;
	//先把p搞定
	//再把俩箭头搞定
	if (L->next != NULL)
	{
		L->next->prev = p;
	}
	L->next = p;
	return 1;
}

//遍历

void Dergolist(DL* L)
{
	DL* temp = L->next;
	//跳过头节点的0
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


//尾插法
DL* Dget_tail(DL* L) {
	DL* tail = L;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;
}
DL* Dendinsert(DL* tail, int inputdata) {
	DL* new_tail = (DL*)malloc(sizeof(DL));
	new_tail->data = inputdata;
	new_tail->next = NULL;
	tail->next = new_tail;
	new_tail->prev = tail;
	return new_tail;
}

//指定位置插入

DL* Dinsert(DL* L, int inputdata, int place)
{

	//插入是插入前驱得后面
	//但是，现在是双向链表，所以找后驱也行了
	DL* p = L;

	//我们不知道place对应的节点是谁,所以想办法用变量解决
	int i = 0;
	while (i < place - 1)
		//插入是插入在链表的前驱,所以并不是真的找第place个,而是place-1
	{
		p = p->next;
		i++;
		if (p == NULL)
			//防止place超出长度
		{
			return 0;
		}
	}
	//循环只是找位置,现在才是开始进行插入
	DL* temp = (DL*)malloc(sizeof(DL));
	temp->data = inputdata;
	temp->next = p->next;
	temp->prev = p;
	p->next->prev = temp;
	p->next = temp;
	return L;
}

// 在指定位置删除
DL* DDelete(DL* L, int place)
{
	DL* p = L;
	int i = 0;
	//跟上面一样,先找前驱
	while (i < place - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}

	}
	if (p->next == NULL)
	{
		printf("删除的位置没有数据");
		return 0;
	}
	DL* q = (DL*)malloc(sizeof(DL));
	q = p->next;
	p->next = q->next;
	p->next->prev = p;
	free(q);
}