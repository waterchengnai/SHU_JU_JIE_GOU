#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
//题目一

//找到链表中倒数第k个节点,并打印其中的数据

//技巧:快慢指针 

//int main()
//{
//	lklist* L=intit_list();
//	headinsert(L,48);
//	headinsert(L, 17);
//	headinsert(L, 72);
//	headinsert(L, 73);
//	headinsert(L, 67);
//	headinsert(L, 41);
//	headinsert(L, 35);
//	ergolist(L);
//	int len=length(L);
//	int k;
//	scanf_s("%d",&k);
//	if (k > len || k < 0)
//	{
//		printf("error!");
//		return 0;
//	}
//	lklist* fast = L->next;
//	lklist* slow = L->next;
//	fast=L->next;
//	slow = L->next;
//	for(int i=0;i<k-1;i++)
//	{
//		fast = fast->next;
//	}
//	while (fast->next != NULL)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	printf("倒数第%d个节点的数据是: %d\n", k, slow->data);
//	freelist(L);
//}


//题目二：
//有一个链表,要求删除绝对值相同的节点(除了第一个出现该值的)

//方法:以空间换时间

//#include<math.h>
//int main()
//{
//	lklist* L = intit_list();
//	headinsert(L,45);
//	headinsert(L,15);
//	headinsert(L, 48);
//	headinsert(L, 48);
//	headinsert(L, 18);
//	headinsert(L, 14);
//	headinsert(L, -48);
//	ergolist(L);
//	int len = length(L);
//	//创建数组
//
//	int max_abs_value = 0;
//	lklist* temp = L->next;
//	while (temp != NULL) {
//		int abs_value = abs(temp->data);
//		if (abs_value > max_abs_value) 
//		{
//			max_abs_value = abs_value;
//		}
//		temp = temp->next;
//	}
//	//遍历数组,初始化
//	int* p = (int*)malloc(sizeof(int) * (max_abs_value + 1));
//	for (int i = 0; i < max_abs_value + 1; i++)
//	{
//		*(p + i) = 0;
//	}
//
//	lklist* prev = L;
//	temp = L->next;
//	//搞个快慢指针,记录前节点
//	while (temp != NULL) 
//	{
//		int abs_value = abs(temp->data);
//		if (p[abs_value])
//		{
//			lklist* to_delete = temp;
//			prev->next = temp->next;
//			free(to_delete);
//			temp = prev->next;
//		}
//		else {
//			p[abs_value] = 1;
//			prev = temp;
//			temp = prev->next;
//		}
//		
//	}
//	ergolist(L);
//	freelist(L);
//	free(p);
//}


//题目三

//创建一个链表,要求输入一些数字,当出现绝对值相同的数时,利用函数将除第一个出现的数字删除
//PS:数据绝对值最大不能超过数组长度

//思想:用空间来换时间

//#include<math.h>
//void removesame(lklist*L,int len_of_list)
//{
//	//创建一个数组,要求长度为链表中绝对值最大数+1
//	//这样数组的每个索引都在链表中有对应
//	//当链表中出现一个数时,数组索引对应元素就+1,以此判断是否出现过
//	int* arr = (int*)malloc((len_of_list+1) * sizeof(int));
//	lklist* p = L;
//	//给数组初始化,c语言不初始化数组,数据会是随机的
//	for (int i = 0; i < len_of_list + 1; i++)
//	{
//		arr[i] = 0;
//	}
//	//删除的逻辑还是要知道前驱,所以最后一个节点不需要循环
//	while (p->next != NULL)
//	{	
//		int index = abs(p->next->data);
//		//index当数组索引
//		if (*(arr + index)==0)
//		{
//			arr[index]++;
//			p = p->next;
//		}
//		else
//		{
//			lklist* temp = p->next;
//			p->next = temp->next;
//			free(temp);
//		}
//	}
//	free(arr);//数组记得释放,p别释放了,现在人家是尾节点
//}
//
//
//int main()
//{
//	lklist* L = intit_list();
//	headinsert(L,8);
//	headinsert(L, 2);
//	headinsert(L, 2);
//	headinsert(L, -7);
//	headinsert(L, 5);
//	headinsert(L, -2);
//	headinsert(L, 1);
//	headinsert(L, 6);
//	ergolist(L);
//	int len=length(L);
//	removesame(L, len);
//	ergolist(L);
//	freelist(L);
//}


//题目四

//创建一个链表，输入数据，要求将链表反过来

//思路1：
//链表指向是从前指向后，我们可以从前之后，将指向一个一个逆转方向
//建立三个快慢指针，用于实现上述操作
//利用循环，重复调头工作，直到结束

//思路2：创建一个新链表,将旧链表首插法插入新链表

/*int main()
{
	lklist* L= intit_list();
	lklist* tail=get_tail(L);
	tail = endinsert(tail, 1);
	tail = endinsert(tail, 2);
	tail = endinsert(tail, 3);
	tail = endinsert(tail, 4);
	tail = endinsert(tail, 5);
	tail = endinsert(tail, 6);
	ergolist(L);

	lklist* first=NULL;
	lklist* second = L->next;
	lklist* third = NULL;

	while (second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	//链表反过来了，所以直接用原来的链表打印不行了，现在L->nest应该是first.
	L->next = first;
	ergolist(L);

}*/

//题目五:
//找到中间节点,删除它

//思路1:快慢指针,快指针走两步,慢指针走一步

//思路2:算长度,取一半

/*int main()
{	
	lklist* L = intit_list();
	lklist* tail = get_tail(L);
	tail = endinsert(tail, 1);
	tail = endinsert(tail, 2);
	tail = endinsert(tail, 3);
	tail = endinsert(tail, 4);
	tail = endinsert(tail, 5);
	tail = endinsert(tail, 6);
	tail = endinsert(tail, 7);
	lklist* fast = L->next;
	lklist* slow = L ;
	ergolist(L);
	while (fast != NULL && fast->next != NULL)
	
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	if (slow->next != NULL) 
	{ // 检查slow->next是否存在，以避免空指针访问
		lklist* temp = slow->next;
		slow->next = temp->next;
		free(temp); // 释放被删除的节点
	}
	ergolist(L);
	freelist(L);
	return 0;
}*/

//错误记录:第二遍遍历结果不显示
//原因:while的判断条件是执行条件,而思考的时候想成了结束的条件

//题目6:有链表含a1,a2,a3,a4,a5,a6,a7...an-1,an;
//要求将链表按a1,an,a2,an-2...顺序打印

//思路:快慢指针,反转链表,找中间节点
//观察发现每次操作是将尾节点放在了首节点后,再将原来的尾节点后接上原来首节点的下一个节点
//但是由于指针不能顺着链表往前走,所以逆向将后半截逆转过来,这样中间链表节点就是尾节点
//然后间隔对应插入
//void reversal(lklist* L)
//{
//	lklist* first = NULL;
//	lklist* second = L->next;
//	lklist* third = NULL;
//
//	while (second != NULL)
//	{
//		third = second->next;
//		second->next = first;
//		first = second;
//		second = third;
//	}
//	//链表反过来了，所以直接用原来的链表打印不行了，现在L->nest应该是first.
//	L->next = first;
//}
//
//lklist* find_middle(lklist* L)
//{
//	lklist* fast = L->next;
//	lklist* slow = L;
//	while (fast != NULL && fast->next != NULL)
//
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	return slow;//slow是中间节点的前节点
//}

/*int main() {
	lklist* L;
	lklist* tail;
	L = intit_list();
	tail = endinsert(tail, 1);
	tail = endinsert(tail, 2);
	tail = endinsert(tail, 3);
	tail = endinsert(tail, 4);
	tail = endinsert(tail, 5);
	tail = endinsert(tail, 6);
	tail = endinsert(tail, 7);
	ergolist(L);

	lklist* middle = find_middle(L);//middle算是中间节点的前节点,对于要后置节点的我们,可以把他等效看作初始化节点的首节点L
	//所以上面一题的代码可以直接用;
	reversal(middle);

	ergolist(L);

	lklist* temp = middle->next;
	middle->next = NULL;

	ergolist(L);

	lklist* p1 = L->next;//1
	lklist* p2 = NULL;
	lklist* q1 = temp;//6
	lklist* q2 = NULL;

	//很神奇
	//要p2,q2一直是p1,q1的后置节点,直接在循环的最开始赋值,会省很多事,而且更准
	while (p1!=NULL&&q1!=NULL)
	{
		p2 = p1->next;//2
		q2 = q1->next;//5

		p1->next = q1;
		p1 = p2;
		if(p2!=NULL)//这里是为了防止链表是奇数个,使q2最后指向NULL,导致打印时少了个节点
		{
			q1->next = p1;
			q1 = q2;
		}
	}

	ergolist(L);

}*/
