//层序遍历应用了队列来遍历树，并记录深度
//特点是一层一层的遍历

//逻辑：
//从根结点开始,根节点进入队列,然后把他的左右孩子拉进队列
//然后根节点出队列
//接着由于左孩子先进队列,所以他先把他的左右孩子拉近队列,然后根节点的右孩子把他的左右孩子拉近队列
//最后直到树遍历完全

//这过程中我们需要解决两个问题
//1.怎么判断这一层空了
//2.怎么记录有多少层

//答案是都用变量记录计科


#include<stdio.h>
#include<stdlib.h>
typedef struct TREE {
	char data;
	struct TREE* left;
	struct TREE* right;
}treenode;

char tree[] = "ABDH##I##EJ###CF##G##";
int idx = 0;

typedef struct LQueue {
	treenode* data;
	struct LQueue* next;
}lqueue;

typedef struct {
	lqueue* front;
	lqueue* rear;
}lqueuepointer;


//需要用到的函数
lqueuepointer* initlqueue();	//初始化
int islqempty(lqueuepointer* qp);	//是否为空
void elqueue(lqueuepointer* qp, treenode* push);	//入队
void olqueue(lqueuepointer* qp, treenode* e);	//出队
treenode* createtree();	//创建树
void freeTree(treenode* root);//释放树
void freelQueue(lqueuepointer* Q);

//还有一个是新的函数,测算队列的长度
int LenQ(lqueuepointer* Q) {
	int count = 0;
	lqueue* p = Q->front->next; // 跳过头结点
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

int depthTree(lqueuepointer* Q, treenode* T)
{
	if (T == NULL)
		return 0;
	int depth = 0;//记录深度
	elqueue(Q, T);
	while (!islqempty(Q)) {
		int levelSize = LenQ(Q);//记录这一层有多少个结点
		depth++;
		for (int i = 0; i < levelSize; i++) {
			treenode* curr;
			olqueue(Q, &curr);
			if (curr->left) elqueue(Q, curr->left);
			if (curr->right) elqueue(Q, curr->right);
		}
	}
	printf("%d", depth);
	return depth;
}

int main()
{
	lqueuepointer* Q = initlqueue();
	treenode* T = createtree();
	depthTree(Q,T);
	freeTree(T);
	freelQueue(Q);
}
//创建树
treenode* createtree()
{
	if (idx >= sizeof(tree) - 1) return NULL;
	char ch = tree[idx++];
	if (ch == '#')
	{
		return NULL;
	}
	treenode* T = (treenode*)malloc(sizeof(treenode));
	T->data = ch;
	T->left = createtree();
	T->right = createtree();
	return T;
}

//初始化
lqueuepointer* initlqueue()
{
	lqueue* Q = (lqueue*)malloc(sizeof(lqueue));
	Q->next = NULL;
	lqueuepointer* qp = (lqueuepointer*)malloc(sizeof(lqueuepointer));
	qp->front = Q;
	qp->rear = Q;
	//这里qp已经把Q的活干完了，所以后面对qp操作就行了
	//根据这里rear的初始化可知,队列空不空可以根据rear是不是等于Q判断
	//当然还是可以用原来的front是否等于rear
	//PS:在后面我知道了，front没动过，一直是Q，哈哈😄
	return qp;
}

//判断是否为空
int islqempty(lqueuepointer* qp)
{
	if (qp->front == qp->rear)
	{
		return 1;
	}
	return 0;
}

//入队

//入对的代码是根据哪边认为是队尾决定的，认为队尾是尾节点，那就用尾插法逻辑
//但是很舒服的一点是，我们只对qp操作，而rear可以通过代码一直指向尾节点
//所以比原来要获得尾节点舒服得多

void elqueue(lqueuepointer* qp, treenode* push)
{
	lqueue* temp = (lqueue*)malloc(sizeof(lqueue));
	temp->data = push;
	qp->rear->next = temp;
	temp->next = NULL;
	qp->rear = temp;
}

//出队,跟删首节点思路一样
//下面可以看出，其实front一直没动
void olqueue(lqueuepointer* qp, treenode** e)
{
	lqueue* temp = qp->front->next;
	*e = temp->data;
	qp->front->next = temp->next;
	//这里要注意一下，别把rear删了
	if (temp == qp->rear) 
	{
		qp->rear = qp->front;
	}
	free(temp);
}

void freeTree(treenode* root) 
{
	if (root == NULL) return;
	freeTree(root->left);  // 先递归释放左子树
	freeTree(root->right); // 再递归释放右子树
	free(root);            // 最后释放当前节点
}

void freelQueue(lqueuepointer* Q)
{
	//出队的函数有销毁当前结点的作用
	while (!islqempty(Q)) {
		treenode* tmp;
		olqueue(Q, &tmp);
	}
	free(Q->front);
	free(Q);

}
