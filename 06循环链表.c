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
	//���ڣ����Ǿ�д����һ����3Ϊ�ڵ��ѭ������

	//����һ
	//�����㲻֪����������ʱ���������ж������Ƿ�ѭ��

	//����������ָ��
	if (judgeloops(L))
	{
		printf("������ѭ������\n");
	}
	else
	{
		printf("������ѭ������\n");
	}

	//�����
	//��ô�ж�ѭ����ʼ�Ľڵ���˭,�ǵڼ����ڵ�
	//˼·:����ָ��
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
	} while (fast != slow);//������೤

	
	//����Ҳ����ֻ������֮һ�ƶ���һ����һ��������ʵ���ϸ��鷳��
	

	//��ָ������,�ÿ�ָ�����߻��ĳ���,������ָ�����,�ٴ������õĲ������ǽ��
	fast = L->next;
	slow = L->next;
	for (int i = 0; i < count; i++)
	{
		fast = fast->next;
	}
	count = 1;
	//����count����Ϊ1,��Ϊ�Ǵӵ�һ��ʼ�ߵ���С��1
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
		count++;
	}
	printf("��%d���ڵ��ǻ���ʼ�Ľڵ�", count);
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