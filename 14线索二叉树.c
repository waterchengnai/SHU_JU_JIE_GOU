//#include<stdio.h>
//#include<stdlib.h>
//
////�����������ǻ�������ķ�������������ʵ�ֵ��ֶ�
//
////��������n���ڵ㣬��ô�ӽڵ����2n��,������n-1���Ƿǿյ�(��Ϊ��n���ڵ�,��һ���Ǹ�)
////������n+1���սڵ�,���Ƕ���Ҷ���ӽڵ�
////�������������˳��,���ǿ��԰���Щ�յĽڵ���������
////����ڵ���ǰ��ָ��,�ҽڵ�������ָ��,�ٽ�ϱ������еĺ���ָ�밴������,������������нڵ㴩����,�γ�һ������
//
////����������������,
////1.�����ͷ�ڵ���˭
////2.��ô�ж��Ǻ���ָ�뻹��ǰ�����
//
////��˵�ڶ���:
////���ǿ��Զ�ԭ�ȵĽṹ������µĳ�Ա����Ϊ�ж�
//typedef struct TREE {
//	char data;
//	struct TREE* left;
//	struct TREE* right;
//	int ltag;
//	int rtag;
//}threadtree;
//
////��ʼ��ʱ��ltag��rlag�ֱ�ֵ0;��֮���ǰ���ͺ��,��ֵΪ1
//
////��һ������
////�����ǵ���������һ���½ڵ���Ϊͷ�ڵ�,�Ƕ�������������
////Ȼ����������ָ���,���ָ����������һ���ڵ�
////Ȼ�󽫱����ĵ�һ���ڵ��ǰ��ָ��ͷ�ڵ�
////���������һ���ڵ�ĺ��ָ��ָ��ͷ�ڵ�
////����Ľڵ㣬������Һ����ǿսڵ�,�򰴱���˳��ָ��ǰ������
//
////�ڶ�������
////��ltag,rtag��ֵ���ж�
////0��ʾ���ӽ��,1��ʾ�������
//
//char tree[] = "ABDH##I##EJ###CF##G##";
//int idx = 0;
//threadtree* prev = NULL;//ר�ż�¼�����ڵ��ǰ���ڵ��õ�
//
////����һ����,��ʵҲ�ǳ�ʼ��
//threadtree* createtree()
//{
//	if (idx >= sizeof(tree) - 1) return NULL;
//	char ch = tree[idx++];
//	if (ch == '#')
//	{
//		return NULL;
//	}
//	threadtree* T = (threadtree*)malloc(sizeof(threadtree));
//	T->data = ch;
//	T->ltag = 0;
//	T->rtag = 0;
//	T->left = createtree();
//	T->right = createtree();
//	return T;
//}
//
////������ǰ�ú��������ڵݹ���������м�ڵ�������
////�뿴������Ĵ��벻Ҫ��������,Ҫ���Է���
//void thread(threadtree* T)
//{
//	if (T != NULL)
//	{
//		//�����˼���֮ǰ����������߼�һ��
//		//���������Ĵ�ӡ���������������
//		thread(T->left);
//		//�������Ĺ���������
//		//1.��ǰ��,˭����û�оͲ�˭��ǰ��
//		//2.�����,˭�Һ���û�оͲ�˭�ĺ��
//
//
//		//1.��ǰ��
//		if (T->left == NULL)
//		{
//			//prev�Ƿ��ʵ�ǰ�ڵ�,���Բ�ǰ����������ָ��prev
//			T->ltag = 1;
//			T->left = prev;
//		}
//		//2.�����
//		if (prev != NULL && prev->right == NULL)
//		{
//			//T��prev�Ľڵ�,����prev���ҽڵ��ָ��T
//			//��Ϊʲô���ǲ����Ŷ�T��������?
//			//��ΪT����һ���ڵ���˭�Ҳ�֪��
//			//����prev����һ���ڵ���֪��
//			prev->rtag = 1;
//			prev->right = T;
//		}
//
//		prev = T;//������ʵ��prev�ǵ�ǰ���ʽڵ��ǰ�ڵ�Ĵ���
//
//		thread(T->right);
//	}
//	else return;
//};
//
//
////������
////����������߼�������headΪͷ�ڵ������չ����
//void inorderthread(threadtree* head, threadtree* T)
//{
//	head->ltag = 0;
//	head->rtag = 1;
//	//��Ϊhead��ͷ�ڵ㣬����ltag=0
//	head->right = head;
//	//������head����ָ��ָ���Լ���Ϊ�˱�֤������Ϊ�յ��������Ȼ����ѭ������
//	if (T == NULL)
//	{
//		head->left = head;
//	}
//	else
//	{
//		head->left = T;
//		prev = head;
//		//prev�����þ��Ǽ�¼��ǰ�ڵ��ǰ��
//		//���ڵ�ǰ�ڵ���T����������ָ��head
//
//		//���ﺯ��������м�ڵ�������
//		thread(T);
//
//		//Ȼ���β�ڵ����������
//		if (prev != NULL) {
//			prev->rtag = 1;
//			prev->right = head;
//		}
//		head->right = prev;
//		//���ѱ����ĵ�һ�����������
//		prev = head;
//		while (prev->ltag == 0)
//		{
//			prev = prev->left;
//		}
//		prev->left = head;
//		prev->ltag = 1;
//	}
//}
//
////��������������
//void inorder(threadtree* head)
//{
//	if (head == NULL) return;
//
//	threadtree* curr = head->left;
//	//���Ƕ���һ�·�������������һ�����
//	//1.�����������ӣ���ô����Ӧ��������,Ȼ���ߵ���ߵľ�ͷ
//	//2.������û�����ӣ���������������ô��Ӧ�ô�ӡ������������
//	//3.������û����������ֻ���Һ��ӣ�����Ӧ�ô�ӡ�Լ��������Һ�����
//	//4.������Ҫ�߻�head�ˣ��Ǿ͸ý���������
//
//	//4.
//	while (curr != head)
//	{
//		//1.
//		while (curr->ltag == 0)
//		{
//			curr = curr->left;
//		}
//		//2.
//		while (curr->rtag == 1 && curr->right != head)//����̫���ߵ�ͷ�����
//		{
//			printf("%c ", curr->data);
//			curr = curr->right;
//		}
//		//3.
//		printf("%c ", curr->data);
//		curr = curr->right;
//	}
//	printf("\n");  // ��ӻ��з�
//}
//
//int main()
//{
//	threadtree* head = (threadtree*)malloc(sizeof(threadtree));
//	//������
//	threadtree* T = createtree();
//	//������
//	inorderthread(head, T);
//	//������������
//	inorder(head);
//	free(head);
//}
