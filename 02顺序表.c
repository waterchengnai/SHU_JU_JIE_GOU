//#include<stdio.h>
//#include<stdlib.h>
//#define maxlength 100
//typedef int Int;
//
////����ṹ
//typedef struct list
//{
//	Int arr[maxlength];
//	Int len;
//}List;
////���ݱ�ʵ�������ڽṹ���ﶨ����һ������ͱ���len
////��������������,len��ʾ��Ҫ�õ��ĳ���,���������õĶ�Ĳ������鳤��maxlength,����len
//
////��ʼ��
//void intit_list(List* p)
//{
//	p->len = 0;
//	//len�����ݱ���,��ʼ�����������������������ݱ����
//	//��Ϊ����ʱû��lenֵ
//}
//
////β�����Ԫ��
//int addlist(List* p,Int add_data)
//{
//
//	if (p->len >= maxlength)
//	{
//		printf("���ݱ�����");
//		return 0;
//	}
//	p->arr[p->len] = add_data;
//	p->len++;
//	return 1;
//}
//
////����
//
//void ergolist(List* p)
//{
//	for (int i = 0; i < p->len; i++)
//	{
//		printf("%d ", p->arr[i]);
//	
//	}
//	printf("\n");
//}
//
////��������
//
//int insertlist(List* p, int place, Int data)
//{
//	if (p->len >= place)
//	//�жϲ���λ���Ƿ���˳�����
//	{
//		for (int i = p->len - 1; i >= place - 1; i--)
//			//ע������Ҫ������
//		{
//			p->arr[i + 1] = p->arr[i];
//		}
//		p->arr[place - 1] = data;
//		p->len++;
//	}
//	//len�����ݱ���,�ɿ������ݱ��õ��ĳ���;�˴���len++,�����������ٴ�ӡһλ
//	return 0;
//}
//
////ɾ������
//
//int dellist(List* p, int place)
//{
//	if(p->len>=place)
//	//�жϲ���Ԫ���Ƿ���˳�����
//	{
//		for (int i = place - 1; i <= p->len - 1; i++)
//		{
//			p->arr[i] = p->arr[i + 1];
//		}
//		p->len--;
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	//һ.����List���͵�ָ��,������������Ĳ���
//
//	//1.��̬�ڴ�ֲ����L�Ķ���
//	//List* L=(List*)malloc(sizeof(List));
//	//if (L == NULL)
//	//{
//	//	printf("�ڴ����ʧ��");
//	//	return 0;
//	//}
//
//	//2.�ȶ���һ����̬�Ľṹ�����,�ٶ���ָ��ָ�����
//	List temp;
//	List* L = &temp;
//	
//	intit_list(L);
//	addlist(L, 50);
//	addlist(L, 100);
//	addlist(L, 90);
//	ergolist(L);
//	insertlist(L, 2, 80);
//	ergolist(L);
//	dellist(L, 1);
//	ergolist(L);
//}