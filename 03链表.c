//#include<stdio.h>
//#include<stdlib.h>
//
////如果接下来你为控制条件发愁,就想想你是为了防止什么,干什么,链表长啥样
//
//typedef int Int;
//
//typedef struct linked_list
//{
//	Int data;
//	struct linked_list* next;
//
//}lklist;
//
////初始化
////初始化才是创建链表的真正第一步,他定义了头节点,即使你后面不会打印他,但是链表长度有他
//
//lklist* intit_list()
//{
//	lklist* head=(lklist*)malloc(sizeof(lklist));
//	head->data = 0;
//	head->next = NULL;
//	return head;
//}
//
////头插法
//
//void headinsert(lklist* L,Int inputdata)
//{
//	//L是初始化函数接收的首链表
//	lklist* p=(lklist*)malloc(sizeof(lklist));
//	p->data = inputdata;
//	p->next = L->next;
//	L->next = p;
//}
//
//// 1. 获得尾节点的函数
//lklist* get_tail(lklist* L) {
//	lklist* tail = L;
//	// 如果链表为空，返回NULL或者这里可以设计为返回头节点（假设头节点初始时data无效，next为NULL）
//	if (L == NULL) {
//		return NULL; // 或者可以选择返回头节点的一个特殊状态，这里我们假设NULL表示空链表
//	}
//	while (tail->next != NULL) {
//		tail = tail->next;
//	}
//	return tail;
//}
//
//// 2. 插入新数据，并获得新尾节点的函数
//lklist* endinsert(lklist* L, int inputdata) {
//	lklist* new_tail = (lklist*)malloc(sizeof(lklist));
//	new_tail->data = inputdata;
//	new_tail->next = NULL;
//	tail->next = new_tail;
//	return new_tail;
//}


////指定位置插入
//
//lklist* insert(lklist* L, Int inputdata,int place)
//{
//
//	//插入是插入在链表的前驱
//	lklist* p = L;
//
//	//我们不知道place对应的节点是谁,所以想办法用变量解决
//	int i = 0;
//	while (i < place-1)
//	//插入是插入在链表的前驱,所以并不是真的找第place个,而是place-1
//	{
//		p = p->next;
//		i++;
//		if (p == NULL)
//		//防止place超出长度
//		{
//			return 0;
//		}
//	}
//	//循环只是找位置,现在才是开始进行插入
//	lklist* temp = (lklist*)malloc(sizeof(lklist));
//	temp->data = inputdata;
//	temp->next = p->next;
//	p->next = temp;
//	return L;
//}
//
////在指定位置删除
//lklist* delete(lklist* L, int place)
//{
//	lklist* p = L;
//	int i = 0;
//	//跟上面一样,先找前驱
//	while (i < place - 1)
//	{
//		p = p->next;
//		i++;
//		if (p == NULL)
//		{
//			return 0;
//		}
//
//	}
//	if (p->next == NULL)
//	{
//		printf("删除的位置没有数据");
//		return 0;
//	}
//
//	//记录要删除的对应节点,并利用它
//	lklist* temp = p->next;
//	//替换掉p的指向节点
//	p->next = temp->next;
//
//	//释放掉删除节点的空间
//	free(temp);
//}
//
////遍历
//
//void ergolist(lklist* L)
//{
//	lklist* temp = L->next;
//	//跳过头节点的0
//	while (temp != NULL)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//	printf("\n");
//}
//
////计算链表长度,注意,一般不计算首节点
//
//int length(lklist* L)
//{
//	int len = 0;
//	lklist* temp = L->next;
//	while (temp != NULL)
//	{
//		temp = temp->next;
//		len++;
//	}
//	return len;
//}
//
////释放链表空间
////这里的释放是将链表初始化,首节点还是要保存的,首届点指向还得是NULL;
//
//void freelist(lklist* L)
//{
//	lklist* p,* q;
//	p = L->next;
//	while (p != NULL)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//		//第一次释放了第二个节点,直到后面所有都被释放
//	}
//	L->next = NULL;
//	//现在除首节点意外全部被清除了,但别忘了将首节点指向初始化
//}
//
//int main()
//{
//	lklist* L=intit_list();
//	headinsert(L,50);
//	headinsert(L,60);
//	headinsert(L,70);
//	ergolist(L);
//	lklist* tail=get_tail(L);
//	tail = endinsert(tail, 5);
//	tail = endinsert(tail, 66);
//	tail = endinsert(tail, 25);
//	tail = endinsert(tail, 37);
//	ergolist(L);
//	insert(L, 7, 5);
//	ergolist(L);
//	delete(L, 5);
//	ergolist(L);
//	int len=length(L);
//	printf("%d\n", len);
//	freelist(L);//8
//	printf("%d\n", length(L));//1
//}