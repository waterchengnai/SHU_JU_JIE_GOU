//#include <stdio.h>
//#include <stdlib.h>
//
//typedef char VertexType;
//typedef int EdgeType;
//
////kruskal算法完成的是找到所有边，然后将他们从小到大排序，一下找到所有连接的且权值最小的边
////1.遍历邻接矩阵的上三角(不包括对角线),找到所有边,用一个结构体数组(edges[MAX])记录连接的顶点和权值
////2.然后写一个函数sortedges将顶点按权值进行从小到大排序(这里的排序方法是任意的,不过我现在只会冒泡)
////3.接着创建一个parent数组,像之前的weight一样记录结点的连接情况,但是又有不同,这是因为进行这部操作是由find函数进行的,后面会提到
////4.最后遍历打印即可
//#define MAXSIZE 100
//#define MAXEDGE 200
//#define MAX 0x7fffffff
//
//typedef struct
//{
//	VertexType vertex[MAXSIZE];
//	EdgeType arc[MAXSIZE][MAXSIZE];
//	int vertex_num;
//	int edge_num;
//}Mat_Grph;
//
//typedef struct
//{
//	int begin;
//	int end;
//	int weight;
//}Edge;
//
//
//void create_graph(Mat_Grph* G)
//{
//	G->vertex_num = 9;
//	G->edge_num = 15;
//
//	G->vertex[0] = 'A';
//	G->vertex[1] = 'B';
//	G->vertex[2] = 'C';
//	G->vertex[3] = 'D';
//	G->vertex[4] = 'E';
//	G->vertex[5] = 'F';
//	G->vertex[6] = 'G';
//	G->vertex[7] = 'H';
//	G->vertex[8] = 'I';
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = 0; j < G->vertex_num; j++)
//		{
//			if (i == j)
//			{
//				G->arc[i][j] = 0;
//			}
//			else
//			{
//				G->arc[i][j] = MAX;
//			}
//
//		}
//	}
//
//	//A-B A-F
//	G->arc[0][1] = 10;
//	G->arc[0][5] = 11;
//
//	//B-C B-G B-I
//	G->arc[1][2] = 18;
//	G->arc[1][6] = 16;
//	G->arc[1][8] = 12;
//
//	//C-D C-I
//	G->arc[2][3] = 22;
//	G->arc[2][8] = 8;
//
//	//D-E D-G D-H D-I
//	G->arc[3][4] = 20;
//	G->arc[3][6] = 24;
//	G->arc[3][7] = 16;
//	G->arc[3][8] = 21;
//
//	//E-F E-H
//	G->arc[4][5] = 26;
//	G->arc[4][7] = 7;
//
//	//F-G
//	G->arc[5][6] = 17;
//
//	//G-H
//	G->arc[6][7] = 19;
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = 0; j < G->vertex_num; j++)
//		{
//			G->arc[j][i] = G->arc[i][j];
//		}
//	}
//}
//
//void swap(Edge* edges, int i, int j)
//{
//	Edge temp = edges[i];
//	edges[i] = edges[j];
//	edges[j] = temp;
//}
//
//void sortEdges(Edge edges[], int edge_num)
//{
//	for (int i = 0; i < edge_num; i++)
//	{
//		for (int j = i + 1; j < edge_num; j++)
//		{
//			if (edges[i].weight > edges[j].weight)
//			{
//				swap(edges, i, j);
//			}
//		}
//	}
//}
//
////**********************************************//
////第一个关键点
//int find(int* parent, int index)
//{
//	//parent一开始初始化是0,所以进入whlie循环的条件就是parent赋过值了
//	//赋过值了就证明人家已经找到自己的另一半了,这怎么能再插一腿呢?
//	//这里我我们将这个传进来且已经有另一半的下表在parent里面找到他的另一半
//	//把他的另一半赋值给index再传出
//	//这样本来人家是找你的,这下变成了通过找你的另一半,间接证明你是跟他连接的
//	//如果对象的另一半还有另一半,那你就再往下找另一半,直到找到没有另一半的
//	//顺藤摸瓜
//	while (parent[index] > 0)
//	{
//		index = parent[index];
//	}
//	return index;
//}
//
//void Kruskal(Mat_Grph G)
//{
//	Edge edges[MAXEDGE];
//	int k = 0;
//
//	//1.
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		for (int j = i + 1; j < G.vertex_num; j++)
//		{
//			if (G.arc[i][j] < MAX)
//			{
//				edges[k].begin = i;
//				edges[k].end = j;
//				edges[k].weight = G.arc[i][j];
//				k++;
//			}
//		}
//	}
//
//	//2.
//	sortEdges(edges, G.edge_num);
//
//	//3.这里先进行了初始化
//	int parent[MAXSIZE];
//
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		parent[i] = 0;
//	}
//
//	int n, m;
//	//n是记录parent数组中连接前结点的下标,m是连接后结点的下标
//	//这里i=0的初始化是针对edges这个数组的第一个元素开始的
//	for (int i = 0; i < G.edge_num; i++)
//	{
//		//这里就是要对parent赋值了,我们要注意这个find函数的逻辑
//		n = find(parent, edges[i].begin);
//		m = find(parent, edges[i].end);
//		
//		//*********************************************//
//		//第二个关键点,如何规避形成环,我们每次都是再找权值最短的路径,那我们怎么规避形成环回路呢?
//		//答案就在第一个关键点加上这里
//		//我们上面说过,如果我们连接的时候发现这个点已经被占领了,我们要找他的另一半,或者他另一半的另一半,以此类推
//		//那么在一条绳上的蚂蚱就把自己串起来了,真找你的时候就变成了找到藤上的这个瓜了,且我们能保证藤上所有结点的对象都是不重复的
//		//因为假设parent的begin和end和藤上任意结点有关,最后都会找到瓜,那么就坐实他俩都在藤上,再连接就会成环,就被if挡住了
//		//如果begin和end只有一个或没有一个在藤上,那么肯定连接后不会成环,且begin和end肯定不相同,所以更不会重复
//		//所以藤上结点都不重复
//		if (n != m)
//		{
//			parent[n] = m;
//			//printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
//			printf("(%c, %c) %d\n", G.vertex[edges[i].begin], G.vertex[edges[i].end], edges[i].weight);
//		}
//	}
//}
//
//int main(int argc, char const* argv[])
//{
//	Mat_Grph G;
//	create_graph(&G);
//	Kruskal(G);
//	return 0;
//}