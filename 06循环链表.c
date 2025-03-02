#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

int judgeloops(lklist* L);

/*int main()
{
	lklist* L;
	L = intit_list();
	lklist* tail = get_tail(L);
	tail = endinsert(tail, 1);
	tail = endinsert(tail, 2);
	tail = endinsert(tail, 3);
	lklist* tie = tail;
	tail = endinsert(tail, 4);
	tail = endinsert(tail, 5);
	tail = endinsert(tail, 6);
	tail = endinsert(tail, 7);
	tail = endinsert(tail, 8);
	tail->next = tie;
	//现在，我们就写好了一个以3为节点的循环链表

	//问题一
	//假如你不知道链表内容时，你该如何判断链表是否循环

	//方法：快慢指针
	if (judgeloops(L))
	{
		printf("链表是循环链表\n");
	}
	else
	{
		printf("链表不是循环链表\n");
	}

	//问题二
	//怎么判断循环开始的节点是谁,是第几个节点
	//思路:快慢指针
	lklist* fast = L->next;
	lklist* slow = L->next;
	int count = 0;
	while(fast != slow)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	do
	{
		fast = fast->next->next;
		slow = slow->next;
		count++;
	} while (fast != slow);//算出环多长

	
	//这里也可以只让其中之一移动，一次走一步，上面实际上搞麻烦了
	

	//将指针重置,让快指针先走环的长度,再让慢指针出发,再次相遇用的步数就是结果
	fast = L->next;
	slow = L->next;
	for (int i = 0; i < count; i++)
	{
		fast = fast->next;
	}
	count = 1;
	//这里count设置为1,因为是从第一格开始走的最小是1
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
		count++;
	}
	printf("第%d个节点是环开始的节点", count);
}*/
int judgeloops(lklist* L)
{
	lklist* fast = L->next;
	lklist* slow = L->next;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return 1;
		}
	}
	return 0;
}