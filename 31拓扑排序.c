//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int VertextType;
//typedef int EdgeType;
//
//#define MAXSIZE 100
////拓扑排序是解决事件完成先后顺序的算法,简称AOV
////在一个有向图中,我们认为,入度为0的结点可以直接执行
////入度大于0的不能直接执行
////那么我们按哪种顺序才能让所有顶点执行呢
//
////这就用到了拓朴排序
////他的实现离不开邻接表,栈和链表
////我们先创建一个邻接矩阵
////然后按行顺序创建邻接表
////邻接表的每个元素存放在结构体数组中,结构体包含in,data,headnext
////其中in记录该顶点的入度,data表示该顶点叫什么,headnext是指针类型,指向另一个结构体指针形成链表,存放顶点的出度指向谁
////这样准备工作就完成了
////1.然后我们遍历数组,如果顶点入度为0(即in=0),那么就入栈
////2.所有入度为零的顶点都入栈后,就出栈,并将以他们为首的链表包含的结点的in-1(既然是in-1,那肯定是对对应下表的数组元素in操作)
////3.如果它们中有人in-1后in=0了,那他们就要进栈,进行1.2.操作,直到栈中再没有元素
////所以我们能看出来,这是一个循环操作
//
//typedef struct
//{
//	VertextType vertex[MAXSIZE];
//	EdgeType arc[MAXSIZE][MAXSIZE];
//	int vertex_num;
//	int edge_num;
//}Mat_Graph;
//
////非首节点的节点的结构体
//typedef struct EdgeNode
//{
//	//记录下标
//	int edge_vex;
//	struct EdgeNode* next;
//}EdgeNode;
//
////首节点的结构体
//typedef struct VertextNode
//{
//	int in;
//	VertextType data;
//	EdgeNode* headnext;
//}VertextNode;
//
////这里是给VertextNode起了一个Adj_List[MAXSIZE]的别名,所以VertextNode代表的就是Adj_List类型的数组
////这里的操作很少见(应该),人家一个结构体类型突然就代表结构体数组类型了
//typedef VertextNode Adj_List[MAXSIZE];//adjacency邻接
//
//
////这个结构体更有意思,他把邻接表又包起来了,还多加了两个玩意
//typedef struct
//{
//	Adj_List adj_list;
//	int vertex_num;
//	int edge_num;
//}Adj_Graph;
//
////这里又给这个结构体指针起了别名,后面跟会用到指针的指针
//typedef Adj_Graph* Adj_List_Graph;
//
////下面是栈的相关函数,之前已经学过
//int top = -1;
//int stack[MAXSIZE];
//
//void push(int e)
//{
//	if (top > MAXSIZE)
//	{
//		printf("满了\n");
//		return;
//	}
//
//	top++;
//	stack[top] = e;
//}
//
//int pop()
//{
//	if (top == -1)
//	{
//		printf("空的\n");
//		return 0;
//	}
//
//	int elem = stack[top];
//	top--;
//	return elem;
//}
//
//int is_empty()
//{
//	if (top == -1)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//void create_graph(Mat_Graph* G)
//{
//	G->vertex_num = 14;
//	G->edge_num = 20;
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		G->vertex[i] = i;
//	}
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = 0; j < G->vertex_num; j++)
//		{
//			G->arc[i][j] = 0;
//		}
//	}
//
//	G->arc[0][4] = 1;
//	G->arc[0][5] = 1;
//	G->arc[0][11] = 1;
//	G->arc[1][2] = 1;
//	G->arc[1][4] = 1;
//	G->arc[1][8] = 1;
//	G->arc[2][5] = 1;
//	G->arc[2][6] = 1;
//	G->arc[2][9] = 1;
//	G->arc[3][2] = 1;
//	G->arc[3][13] = 1;
//	G->arc[4][7] = 1;
//	G->arc[5][8] = 1;
//	G->arc[5][12] = 1;
//	G->arc[6][5] = 1;
//	G->arc[8][7] = 1;
//	G->arc[9][10] = 1;
//	G->arc[9][11] = 1;
//	G->arc[10][13] = 1;
//	G->arc[12][9] = 1;
//}
//
////这里是初始化邻接表了
//void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG)
//{
//	EdgeNode* e;
//
//	//动态内存分配一个Adj_Graph的内存空间,也就是我们最终最大的哪个结构体,并对其按邻接矩阵赋值顶点数和边数
//	*ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));
//	(*ALG)->vertex_num = G.vertex_num;
//	(*ALG)->edge_num = G.edge_num;
//
//	//接下来对每个邻接表数组的首节点初始化
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		(*ALG)->adj_list[i].in = 0;
//		(*ALG)->adj_list[i].data = G.vertex[i];
//		(*ALG)->adj_list[i].headnext = NULL;
//	}
//
//	//接着是根据邻接矩阵对邻接表的非首节点初始化
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		for (int j = 0; j < G.vertex_num; j++)
//		{
//			if (G.arc[i][j] == 1)
//			{
//				//动态内存分配非首节点的大小
//				e = (EdgeNode*)malloc(sizeof(EdgeNode));
//				//这里的j是代表的顶点的下标,不是他的名字
//				e->edge_vex = j;
//
//				//首插法
//				e->next = (*ALG)->adj_list[i].headnext;
//				(*ALG)->adj_list[i].headnext = e;
//				(*ALG)->adj_list[j].in++;
//			}
//		}
//	}
//}
//
//void topological_sort(Adj_List_Graph ALG)
//{
//	EdgeNode* e;
//	int curr;
//	int k;
//
//	//对明确入度为0的顶点入栈
//	for (int i = 0; i < ALG->vertex_num; i++)
//	{
//		if (ALG->adj_list[i].in == 0)
//		{
//			push(i);
//		}
//	}
//
//	while (is_empty() != 0)
//	{
//		//出栈
//		curr = pop();
//		printf("V%d -> ", ALG->adj_list[curr].data);
//		//e记录当前出栈的节点对应的首节点的下个节点
//		e = ALG->adj_list[curr].headnext;
//
//		while (e != NULL)
//		{
//			k = e->edge_vex;
//			ALG->adj_list[k].in--;
//			if (ALG->adj_list[k].in == 0)
//			{
//				push(k);
//			}
//			e = e->next;
//		}
//	}
//}
//
//int main(int argc, char const* argv[])
//{
//	Mat_Graph G;
//	Adj_List_Graph ALG;
//	create_graph(&G);
//	create_adj_graph(G, &ALG);
//	topological_sort(ALG);
//	return 0;
//}