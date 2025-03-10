//��ĿҪ��
//����ʽ�ṹ����һ�ö���������������WPL(��Ȩ·������)

//˼·
//��Ȼ��ʹ�ò�������ķ���
//��ͬ����
//1.��������ʱ����ṹ��Ҫ����Ȩ��(weight)
//2.Ҫ�жϽ���ǲ���Ҷ�ӽ��

#include<stdio.h>
#include<stdlib.h>
typedef struct TREE {
	char data;
	struct TREE* left;
	struct TREE* right;
	int weight;
}treenode;
char tree[] = "ABDH##I##EJ###CF##G##";
int idx = -1;
int weight[] = { 150,60,30,10,-1,-1,20,-1,-1,30,30,-1,-1,-1,90,40,-1,-1,50,-1,-1 };

//������
treenode* createTree()
{
	//Ҫ���������Ƿ�Խ����
	if (idx >= (int)(sizeof(tree) - 1))//��������Ϊ�ַ�����β��\0
		//����Ϊɶǿת��,��Ϊsizeof���ص����޷���int,��idxһ��ʼ��-1,�ᱻǿ��ת����һ���ܴ����
	{
		return NULL;
	}
	idx++;
	if (tree[idx] == '#')
	{
		return NULL;
	}
	treenode* t=(treenode*)malloc(sizeof(treenode));
	t->data = tree[idx];
	t->weight = weight[idx];
	t->left=createTree();
	t->right=createTree();
	return t;
}

//2025.3.10��,�㴴�������ĺ���д��ϡ��

#define MAX 100
void WPL(treenode* t)
{
	if (t == NULL) {
		return;
	}
	treenode* queue[MAX];
	int front=0;
	int rear=0;
	queue[0] = t;//���ڵ��Ƚ�ջ
	rear++;
	int depth = 0;
	int WPL = 0;
	while (front < rear)
	{
		depth++;
		int count = rear-front;//��¼�ò��ж��ٸ����
		for (int i = 0; i < count; i++)
		{
			treenode* curr = queue[front];//��¼��ǰ�ڵ�
			if (curr->left != NULL)
			{
				queue[rear] = curr->left;
				rear++;
			}
			if (curr->right != NULL)
			{
				queue[rear] = curr->right;
				rear++;
			}
			if (curr->left == NULL && curr->right == NULL)
			{
				WPL += (depth - 1)* (curr->weight);//�ۼ���Ҷ�ӽڵ�Ĵ�Ȩ·��
			}			
			front++;//��ʾ�ò�����ջ
		}
	}
	printf("%d", WPL);
}

//�ͷ��ڴ�
void freeTree(treenode* t)
{
	if (t == NULL)return;
	freeTree(t->left);
	freeTree(t->right);
	free(t);
}


int main()
{
	treenode* t=createTree();
	WPL(t);
	freeTree(t);
}