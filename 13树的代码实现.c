//#include<stdio.h>
////��Ҳ�Ǽȿ�����˳��ṹ,Ҳ��������ʽ�ṹ
////���Ƕ����������֪��,������ʽ��
//
//typedef struct TREE{
//	int data;
//	struct TREE* left;
//	struct TREE* right;
//}treenode;
//
//typedef treenode* Bitree;//��ָ�������,Bi�Ƕ����Ƶ���˼
//
////ǰ�����
////�����õ��˵ݹ�˼��
//void preorder(Bitree T)
//{
//	if (T == NULL)
//	{
//		return ;
//	}
//	printf("%d ", T->data);
//	preorder(T->left);
//	preorder(T->right);
//}
//
////�������
//void inorder(Bitree T)
//{
//	if (T == NULL)
//	{
//		return ;
//	}
//	inorder(T->left);
//	printf("%d ", T->data);
//	inorder(T->right);
//}
//
////�������
//void endorder(Bitree T)
//{
//	if (T == NULL)
//	{
//		return ;
//	}
//	endorder(T->left);	
//	endorder(T->right);
//	printf("%d ", T->data);
//}
//
////���ѿ��������б����У��ڵ������˳�򲻱䣬ֻ�Ǵ�ӡ˳���߼���ͬ
////ǰ�����:�κνڵ�,�����Լ����ӽڵ��ȴ�ӡ
////�������:�κνڵ�,���ȴ�ӡ���ӽڵ�,�����Լ�,������ҽڵ�
////��������:�κνڵ�,�ȴ�ӡ�ӽڵ�,������Լ�