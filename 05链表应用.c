#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
//��Ŀһ

//�ҵ������е�����k���ڵ�,����ӡ���е�����

//����:����ָ�� 

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
//	printf("������%d���ڵ��������: %d\n", k, slow->data);
//	freelist(L);
//}


//��Ŀ����
//��һ������,Ҫ��ɾ������ֵ��ͬ�Ľڵ�(���˵�һ�����ָ�ֵ��)

//����:�Կռ任ʱ��

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
//	//��������
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
//	//��������,��ʼ��
//	int* p = (int*)malloc(sizeof(int) * (max_abs_value + 1));
//	for (int i = 0; i < max_abs_value + 1; i++)
//	{
//		*(p + i) = 0;
//	}
//
//	lklist* prev = L;
//	temp = L->next;
//	//�������ָ��,��¼ǰ�ڵ�
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


//��Ŀ��

//����һ������,Ҫ������һЩ����,�����־���ֵ��ͬ����ʱ,���ú���������һ�����ֵ�����ɾ��
//PS:���ݾ���ֵ����ܳ������鳤��

//˼��:�ÿռ�����ʱ��

//#include<math.h>
//void removesame(lklist*L,int len_of_list)
//{
//	//����һ������,Ҫ�󳤶�Ϊ�����о���ֵ�����+1
//	//���������ÿ�����������������ж�Ӧ
//	//�������г���һ����ʱ,����������ӦԪ�ؾ�+1,�Դ��ж��Ƿ���ֹ�
//	int* arr = (int*)malloc((len_of_list+1) * sizeof(int));
//	lklist* p = L;
//	//�������ʼ��,c���Բ���ʼ������,���ݻ��������
//	for (int i = 0; i < len_of_list + 1; i++)
//	{
//		arr[i] = 0;
//	}
//	//ɾ�����߼�����Ҫ֪��ǰ��,�������һ���ڵ㲻��Ҫѭ��
//	while (p->next != NULL)
//	{	
//		int index = abs(p->next->data);
//		//index����������
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
//	free(arr);//����ǵ��ͷ�,p���ͷ���,�����˼���β�ڵ�
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


//��Ŀ��

//����һ�������������ݣ�Ҫ����������

//˼·1��
//����ָ���Ǵ�ǰָ������ǿ��Դ�ǰ֮�󣬽�ָ��һ��һ����ת����
//������������ָ�룬����ʵ����������
//����ѭ�����ظ���ͷ������ֱ������

//˼·2������һ��������,���������ײ巨����������

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
	//���������ˣ�����ֱ����ԭ���������ӡ�����ˣ�����L->nestӦ����first.
	L->next = first;
	ergolist(L);

}*/

//��Ŀ��:
//�ҵ��м�ڵ�,ɾ����

//˼·1:����ָ��,��ָ��������,��ָ����һ��

//˼·2:�㳤��,ȡһ��

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
	{ // ���slow->next�Ƿ���ڣ��Ա����ָ�����
		lklist* temp = slow->next;
		slow->next = temp->next;
		free(temp); // �ͷű�ɾ���Ľڵ�
	}
	ergolist(L);
	freelist(L);
	return 0;
}*/

//�����¼:�ڶ�������������ʾ
//ԭ��:while���ж�������ִ������,��˼����ʱ������˽���������

//��Ŀ6:������a1,a2,a3,a4,a5,a6,a7...an-1,an;
//Ҫ������a1,an,a2,an-2...˳���ӡ

//˼·:����ָ��,��ת����,���м�ڵ�
//�۲췢��ÿ�β����ǽ�β�ڵ�������׽ڵ��,�ٽ�ԭ����β�ڵ�����ԭ���׽ڵ����һ���ڵ�
//��������ָ�벻��˳��������ǰ��,�������򽫺�����ת����,�����м�����ڵ����β�ڵ�
//Ȼ������Ӧ����
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
//	//���������ˣ�����ֱ����ԭ���������ӡ�����ˣ�����L->nestӦ����first.
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
//	return slow;//slow���м�ڵ��ǰ�ڵ�
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

	lklist* middle = find_middle(L);//middle�����м�ڵ��ǰ�ڵ�,����Ҫ���ýڵ������,���԰�����Ч������ʼ���ڵ���׽ڵ�L
	//��������һ��Ĵ������ֱ����;
	reversal(middle);

	ergolist(L);

	lklist* temp = middle->next;
	middle->next = NULL;

	ergolist(L);

	lklist* p1 = L->next;//1
	lklist* p2 = NULL;
	lklist* q1 = temp;//6
	lklist* q2 = NULL;

	//������
	//Ҫp2,q2һֱ��p1,q1�ĺ��ýڵ�,ֱ����ѭ�����ʼ��ֵ,��ʡ�ܶ���,���Ҹ�׼
	while (p1!=NULL&&q1!=NULL)
	{
		p2 = p1->next;//2
		q2 = q1->next;//5

		p1->next = q1;
		p1 = p2;
		if(p2!=NULL)//������Ϊ�˷�ֹ������������,ʹq2���ָ��NULL,���´�ӡʱ���˸��ڵ�
		{
			q1->next = p1;
			q1 = q2;
		}
	}

	ergolist(L);

}*/
