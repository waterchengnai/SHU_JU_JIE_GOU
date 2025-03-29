//#include <stdio.h>
//
//typedef int VertexType;
//typedef int EdgeType;
//
//#define MAXSIZE 100
//#define MAXEDGE 200
//#define MAX 0x10000
////该实现完整对应经典Dijkstra四步骤：
//
////初始化距离和前驱数组
////选择未处理顶点中的最小距离顶点
////更新该顶点邻居的最短距离
////标记顶点为已处理，循环直至所有顶点处理完毕
//
//
////该算法在非负权图中完全正确
////当图中所有边权值非负时，Dijkstra算法的贪心策略能严格保证：
////
////1.局部最优即全局最优
////算法每次从“未处理集合”中选择当前距离起点最近的节点（记为u），一旦将其加入“已处理集合”（S），则u的最短路径长度即被永久确定。
////这是因为后续任何路径必须经过其他未处理节点，而所有边权非负，导致绕行其他节点的路径只会更长。
////​2.动态更新的正确性
////通过松弛操作（distance[next] + G.arc[next][j] < distance[j]）算法不断优化未处理节点的距离值。
////由于已处理节点的最短路径不再被修改，最终所有节点的最短路径都会被正确计算。
//typedef struct
//{
//	VertexType vertex[MAXSIZE];
//	EdgeType arc[MAXSIZE][MAXSIZE];
//	int vertex_num;
//	int edge_num;
//}Mat_Graph;
//
//void createGraph(Mat_Graph* G)
//{
//	G->vertex_num = 9;
//	G->edge_num = 16;
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
//			if (i == j)
//			{
//				G->arc[i][j] = 0;
//			}
//			else
//			{
//				G->arc[i][j] = MAX;
//			}
//		}
//	}
//
//
//	G->arc[0][1] = 1;
//	G->arc[0][2] = 5;
//
//	G->arc[1][2] = 3;
//	G->arc[1][3] = 7;
//	G->arc[1][4] = 5;
//
//	G->arc[2][4] = 1;
//	G->arc[2][5] = 7;
//
//	G->arc[3][4] = 2;
//	G->arc[3][6] = 3;
//
//	G->arc[4][5] = 3;
//	G->arc[4][6] = 6;
//	G->arc[4][7] = 9;
//
//	G->arc[5][7] = 5;
//
//	G->arc[6][7] = 2;
//	G->arc[6][8] = 7;
//
//	G->arc[7][8] = 4;
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = i; j < G->vertex_num; j++)
//		{
//			G->arc[j][i] = G->arc[i][j];
//		}
//	}
//}
//
////返回下一次要观察哪一个顶点
////2.实际上就是在找未处理顶点中的最小距离顶点
//int choose(int distance[], int visited[], int vertex_num)
//{
//	int min = MAX;
//	int minPos = -1;//minposition的意思,记录最小值的位置
//	for (int i = 0; i < vertex_num; i++)
//	{
//		if (distance[i] < min && visited[i] == 0)
//		{
//			min = distance[i];
//			minPos = i;
//		}
//	}
//	return minPos;
//}
//
//void dijkstra(Mat_Graph G, int begin)
//{
//	int visited[MAXSIZE];//顶点是否已走过
//	//******************//
//	int path[MAXSIZE];
//	//路径,这跟之前的记录顶点到下个顶点的数组一样,就是单纯记录边的两头顶点是谁，对吗？
//	//如果你这么想就错了
//	//path数组用于记录到达每个节点的前驱节点（即路径的上一步）。不是下一步
//	int distance[MAXSIZE];//begin到达每一个顶点最短距离
//
//	//1.对三个数组初始化,并先用第begin行对distance赋值
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		visited[i] = 0;
//		path[i] = -1;
//		distance[i] = G.arc[begin][i];
//	}
//	//实际上是begin对自己进行了已处理和最短距离操作
//	visited[begin] = 1;
//	distance[begin] = 0;
//
//	int next;//下一个要观察的顶点,也就是当前结点的下个权值最近顶点
//
//	for (int i = 1; i < G.vertex_num; i++)
//	{	
//		//2.
//		next = choose(distance, visited, G.vertex_num);
//		//这个choose就是在找谁是下个权值最近顶点
//
//		for (int j = 0; j < G.vertex_num; j++)
//		{
//			if (visited[j] == 0)
//			{
//				//3.更新该顶点到所有邻居的最短路径
//				//(distance[next]是begin到next这个顶点的最短距离
//				//这个distance[j]是谁呢?
//				//一开始是begin到其他各顶点的距离
//				//然后随着当前访问顶点i的最近顶点(next)到其他顶点的距离相加(distance[next] + G.arc[next][j])
//				//若发现比原来知道的begin到j顶点的走法短,那么就更新distance[j]
//				//并且记录走到j的上一步为next,因为next到j比之前认为的最短连接方式还短
//
//				//这个算法保证了到第j结点是最短路径,一直到最后的结点也一直是最短路径
//				//因为我们一直在更新到j结点的上一步应该是谁
//				if (distance[next] + G.arc[next][j] < distance[j])
//				{
//					distance[j] = distance[next] + G.arc[next][j];
//					path[j] = next;
//				}
//			}
//		}
//		//4.标记结点已访问过
//		visited[next] = 1;
//	}
//
//
//
//	for (int i = 1; i < G.vertex_num; i++)
//	{
//		printf("V0 -> V%d : %d\n", i, distance[i]);
//
//		int j = i;
//		printf("V%d <- ", i);
//		while (path[j] != -1)
//		{
//			printf("V%d <- ", path[j]);
//			j = path[j];
//		}
//		printf("V0\n");
//
//	}
//
//}
//
//int main(int argc, char const* argv[])
//{
//	Mat_Graph G;
//	createGraph(&G);
//	int begin = 0;
//	dijkstra(G, begin);
//	return 0;
//}