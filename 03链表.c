//#include<stdio.h>
//#include<stdlib.h>
//
////�����������Ϊ������������,����������Ϊ�˷�ֹʲô,��ʲô,����ɶ��
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
////��ʼ��
////��ʼ�����Ǵ��������������һ��,��������ͷ�ڵ�,��ʹ����治���ӡ��,��������������
//
//lklist* intit_list()
//{
//	lklist* head=(lklist*)malloc(sizeof(lklist));
//	head->data = 0;
//	head->next = NULL;
//	return head;
//}
//
////ͷ�巨
//
//void headinsert(lklist* L,Int inputdata)
//{
//	//L�ǳ�ʼ���������յ�������
//	lklist* p=(lklist*)malloc(sizeof(lklist));
//	p->data = inputdata;
//	p->next = L->next;
//	L->next = p;
//}
//
//// 1. ���β�ڵ�ĺ���
//lklist* get_tail(lklist* L) {
//	lklist* tail = L;
//	// �������Ϊ�գ�����NULL��������������Ϊ����ͷ�ڵ㣨����ͷ�ڵ��ʼʱdata��Ч��nextΪNULL��
//	if (L == NULL) {
//		return NULL; // ���߿���ѡ�񷵻�ͷ�ڵ��һ������״̬���������Ǽ���NULL��ʾ������
//	}
//	while (tail->next != NULL) {
//		tail = tail->next;
//	}
//	return tail;
//}
//
//// 2. ���������ݣ��������β�ڵ�ĺ���
//lklist* endinsert(lklist* L, int inputdata) {
//	lklist* new_tail = (lklist*)malloc(sizeof(lklist));
//	new_tail->data = inputdata;
//	new_tail->next = NULL;
//	tail->next = new_tail;
//	return new_tail;
//}


////ָ��λ�ò���
//
//lklist* insert(lklist* L, Int inputdata,int place)
//{
//
//	//�����ǲ����������ǰ��
//	lklist* p = L;
//
//	//���ǲ�֪��place��Ӧ�Ľڵ���˭,������취�ñ������
//	int i = 0;
//	while (i < place-1)
//	//�����ǲ����������ǰ��,���Բ���������ҵ�place��,����place-1
//	{
//		p = p->next;
//		i++;
//		if (p == NULL)
//		//��ֹplace��������
//		{
//			return 0;
//		}
//	}
//	//ѭ��ֻ����λ��,���ڲ��ǿ�ʼ���в���
//	lklist* temp = (lklist*)malloc(sizeof(lklist));
//	temp->data = inputdata;
//	temp->next = p->next;
//	p->next = temp;
//	return L;
//}
//
////��ָ��λ��ɾ��
//lklist* delete(lklist* L, int place)
//{
//	lklist* p = L;
//	int i = 0;
//	//������һ��,����ǰ��
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
//		printf("ɾ����λ��û������");
//		return 0;
//	}
//
//	//��¼Ҫɾ���Ķ�Ӧ�ڵ�,��������
//	lklist* temp = p->next;
//	//�滻��p��ָ��ڵ�
//	p->next = temp->next;
//
//	//�ͷŵ�ɾ���ڵ�Ŀռ�
//	free(temp);
//}
//
////����
//
//void ergolist(lklist* L)
//{
//	lklist* temp = L->next;
//	//����ͷ�ڵ��0
//	while (temp != NULL)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//	printf("\n");
//}
//
////����������,ע��,һ�㲻�����׽ڵ�
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
////�ͷ�����ռ�
////������ͷ��ǽ������ʼ��,�׽ڵ㻹��Ҫ�����,�׽��ָ�򻹵���NULL;
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
//		//��һ���ͷ��˵ڶ����ڵ�,ֱ���������ж����ͷ�
//	}
//	L->next = NULL;
//	//���ڳ��׽ڵ�����ȫ���������,�������˽��׽ڵ�ָ���ʼ��
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