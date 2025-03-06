//#include<stdio.h>
//#include<stdlib.h>
//
////线索二叉树是基于链表的方法来对树遍历实现的手段
//
////假设树有n个节点，那么子节点就有2n个,其中有n-1个是非空的(因为有n个节点,有一个是根)
////所以有n+1个空节点,它们都是叶的子节点
////根据中序遍历的顺序,我们可以把这些空的节点利用起来
////将左节点做前驱指针,右节点做后驱指针,再结合本来就有的孩子指针按照中序,遍历结果将所有节点穿起来,形成一个链表
//
////接下来有两个问题,
////1.链表的头节点是谁
////2.怎么判断是孩子指针还是前驱后继
//
////先说第二个:
////我们可以对原先的结构体插入新的成员来作为判断
//typedef struct TREE {
//	char data;
//	struct TREE* left;
//	struct TREE* right;
//	int ltag;
//	int rtag;
//}threadtree;
//
////初始化时对ltag和rlag分别赋值0;若之后搞前驱和后继,则赋值为1
//
////第一个问题
////我们是单独创建了一个新节点作为头节点,是独立于树创建的
////然后将它的左孩子指向根,后继指向遍历的最后一个节点
////然后将遍历的第一个节点的前驱指向头节点
////遍历的最后一个节点的后继指向指向头节点
////其余的节点，若左或右孩子是空节点,则按遍历顺序指向前驱或后继
//
////第二个问题
////用ltag,rtag的值来判断
////0表示孩子结点,1表示线索结点
//
//char tree[] = "ABDH##I##EJ###CF##G##";
//int idx = 0;
//threadtree* prev = NULL;//专门记录遍历节点的前驱节点用的
//
////创建一个树,其实也是初始化
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
////线索化前置函数，用于递归遍历并将中间节点线索化
////想看懂下面的代码不要定量分析,要定性分析
//void thread(threadtree* T)
//{
//	if (T != NULL)
//	{
//		//这里的思想跟之前中序遍历的逻辑一致
//		//不过遍历的打印操作变成了线索化
//		thread(T->left);
//		//线索化的过程是两种
//		//1.补前驱,谁左孩子没有就补谁的前驱
//		//2.补后继,谁右孩子没有就补谁的后继
//
//
//		//1.补前驱
//		if (T->left == NULL)
//		{
//			//prev是访问的前节点,所以补前驱就是左孩子指向prev
//			T->ltag = 1;
//			T->left = prev;
//		}
//		//2.补后继
//		if (prev != NULL && prev->right == NULL)
//		{
//			//T是prev的节点,所以prev的右节点就指向T
//			//那为什么我们不接着对T线索化呢?
//			//因为T的下一个节点是谁我不知道
//			//但是prev的下一个节点我知道
//			prev->rtag = 1;
//			prev->right = T;
//		}
//
//		prev = T;//这里是实现prev是当前访问节点的前节点的代码
//
//		thread(T->right);
//	}
//	else return;
//};
//
//
////线索化
////这里的所有逻辑都是以head为头节点的链表展开的
//void inorderthread(threadtree* head, threadtree* T)
//{
//	head->ltag = 0;
//	head->rtag = 1;
//	//因为head是头节点，所以ltag=0
//	head->right = head;
//	//这里让head的右指针指向自己是为了保证出现树为空的情况下依然构成循环链表
//	if (T == NULL)
//	{
//		head->left = head;
//	}
//	else
//	{
//		head->left = T;
//		prev = head;
//		//prev的作用就是记录当前节点的前驱
//		//现在当前节点是T，所以现在指向head
//
//		//这里函数来解决中间节点线索化
//		thread(T);
//
//		//然后把尾节点线索化解决
//		if (prev != NULL) {
//			prev->rtag = 1;
//			prev->right = head;
//		}
//		head->right = prev;
//		//最后把遍历的第一个结点线索化
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
////基于线索化遍历
//void inorder(threadtree* head)
//{
//	if (head == NULL) return;
//
//	threadtree* curr = head->left;
//	//我们定性一下分析，对于任意一个结点
//	//1.假如它有左孩子，那么它就应该往左走,然后走到左边的尽头
//	//2.假如它没有左孩子，它有右线索，那么它应该打印，并往线索走
//	//3.假如它没有右线索，只有右孩子，那它应该打印自己，并往右孩子走
//	//4.假如它要走回head了，那就该结束遍历了
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
//		while (curr->rtag == 1 && curr->right != head)//别走太过走到头结点了
//		{
//			printf("%c ", curr->data);
//			curr = curr->right;
//		}
//		//3.
//		printf("%c ", curr->data);
//		curr = curr->right;
//	}
//	printf("\n");  // 添加换行符
//}
//
//int main()
//{
//	threadtree* head = (threadtree*)malloc(sizeof(threadtree));
//	//创建树
//	threadtree* T = createtree();
//	//线索化
//	inorderthread(head, T);
//	//基于线索遍历
//	inorder(head);
//	free(head);
//}
