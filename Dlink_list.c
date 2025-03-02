#include<stdio.h>
#include<stdlib.h>

typedef struct suibianba {
	int data;
	struct suibianba* prev;
	struct suibianba* next;
}DL;

//��ʼ��
DL* intit_Dlist()
{
	DL* head = (DL*)malloc(sizeof(DL));
	head->data = 0;
	head->next = NULL;
	head->prev = NULL;
	return head;
}

//ͷ�巨

void Dheadinsert(DL* L, int inputdata)
{
	//L�ǳ�ʼ���������յ�������
	DL* p = (DL*)malloc(sizeof(DL));
	p->data = inputdata;
	p->next = L->next;
	p->prev = L;
	//�Ȱ�p�㶨
	//�ٰ�����ͷ�㶨
	if (L->next != NULL)
	{
		L->next->prev = p;
	}
	L->next = p;
	return 1;
}

//����

void Dergolist(DL* L)
{
	DL* temp = L->next;
	//����ͷ�ڵ��0
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


//β�巨
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

//ָ��λ�ò���

DL* Dinsert(DL* L, int inputdata, int place)
{

	//�����ǲ���ǰ���ú���
	//���ǣ�������˫�����������Һ���Ҳ����
	DL* p = L;

	//���ǲ�֪��place��Ӧ�Ľڵ���˭,������취�ñ������
	int i = 0;
	while (i < place - 1)
		//�����ǲ����������ǰ��,���Բ���������ҵ�place��,����place-1
	{
		p = p->next;
		i++;
		if (p == NULL)
			//��ֹplace��������
		{
			return 0;
		}
	}
	//ѭ��ֻ����λ��,���ڲ��ǿ�ʼ���в���
	DL* temp = (DL*)malloc(sizeof(DL));
	temp->data = inputdata;
	temp->next = p->next;
	temp->prev = p;
	p->next->prev = temp;
	p->next = temp;
	return L;
}

// ��ָ��λ��ɾ��
DL* DDelete(DL* L, int place)
{
	DL* p = L;
	int i = 0;
	//������һ��,����ǰ��
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
		printf("ɾ����λ��û������");
		return 0;
	}
	DL* q = (DL*)malloc(sizeof(DL));
	q = p->next;
	p->next = q->next;
	p->next->prev = p;
	free(q);
}