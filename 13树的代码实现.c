//#include<stdio.h>
////树也是既可以用顺序结构,也可以用链式结构
////但是动脑子想想就知道,还是链式简单
//
//typedef struct TREE{
//	cgar data;
//	struct TREE* left;
//	struct TREE* right;
//}treenode;
//
//typedef treenode* Bitree;//给指针起别名,Bi是二进制的意思
//

//char tree[] = "ABDH##I##EJ###CF##G##";
//int idx = 0;

////创建树
//treenode* createtree()
//{
//	if (idx >= sizeof(tree) - 1) return NULL;
//	char ch = tree[idx++];
//	if (ch == '#')
//	{
//		return NULL;
//	}
//	treenode* T = (treenode*)malloc(sizeof(treenode));
//	T->data = ch;
//	T->left = createtree();
//	T->right = createtree();
//	return T;
//}
////前序遍历
////这里用到了递归思想
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
////中序遍历
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
////后序遍历
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
// void freeTree(treenode* root) {
//if (root == NULL) return;
//freeTree(root->left);  // 先递归释放左子树
//freeTree(root->right); // 再递归释放右子树
//free(root);            // 最后释放当前节点
//}
////不难看出，三中遍历中，节点遍历的顺序不变，只是打印顺序逻辑不同
////前序遍历:任何节点,都比自己的子节点先打印
////中序遍历:任何节点,都先打印左子节点,后是自己,最后是右节点
////后续遍历:任何节点,先打印子节点,最后是自己
