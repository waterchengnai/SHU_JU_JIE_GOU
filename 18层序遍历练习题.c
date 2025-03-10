//题目要求
//用链式结构创建一棵二叉树，并求它的WPL(带权路径长度)

//思路
//依然是使用层序遍历的方法
//不同点是
//1.定义树的时候结点结构体要新增权重(weight)
//2.要判断结点是不是叶子结点

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

//创建树
treenode* createTree()
{
	//要考虑数组是否越界了
	if (idx >= (int)(sizeof(tree) - 1))//等于是因为字符串结尾有\0
		//这里为啥强转呢,因为sizeof返回的是无符号int,但idx一开始是-1,会被强制转换成一个很大的数
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

//2025.3.10记,你创建个树的函数写的稀碎

#define MAX 100
void WPL(treenode* t)
{
	if (t == NULL) {
		return;
	}
	treenode* queue[MAX];
	int front=0;
	int rear=0;
	queue[0] = t;//根节点先进栈
	rear++;
	int depth = 0;
	int WPL = 0;
	while (front < rear)
	{
		depth++;
		int count = rear-front;//记录该层有多少个结点
		for (int i = 0; i < count; i++)
		{
			treenode* curr = queue[front];//记录当前节点
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
				WPL += (depth - 1)* (curr->weight);//累加上叶子节点的带权路径
			}			
			front++;//表示该层结点退栈
		}
	}
	printf("%d", WPL);
}

//释放内存
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