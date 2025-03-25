#include <stdio.h>
#include <stdlib.h>

//pirm是解决图中的最小生成树的问题,
//最小生成树（Minimum Spanning Tree, MST）是图论中的一个重要概念，用于在加权连通图中找到一棵包含所有顶点的树，且边的总权重最小。
//关键点是:连通图,总权重最小
typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff

typedef struct
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;


void create_graph(Mat_Grph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;

	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = MAX;
			}

		}
	}

	//A-B A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;

	//B-C B-G B-I
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;

	//C-D C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;

	//D-E D-G D-H D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;

	//E-F E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;

	//F-G
	G->arc[5][6] = 17;

	//G-H
	G->arc[6][7] = 19;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

//这种算法的逻辑是在原有的邻接矩阵的基础上,再写一个weight数组和vex_index数组
//可以想象这两个数组是对齐放在这邻接矩阵下面
//其中weight是用来记录哪条路径权值最小,vex_index用来记录该下表对应顶点是跟谁连接在一起
//这种算法实际上只进行了三个操作
//1.初始化,确定图从哪里开始,以及起点的侯选边,并连接所有侯选边(即在vex_index[j]赋值k)
//2.找到最小边,用k记录,接下来找侯选边就是从k这个对应的顶点开始的
//3.更新侯选边,连接所有侯选边给k这个顶点

void prim(Mat_Grph* G)
{
	int i, j, k;
	int min;
	int weight[MAXSIZE];//候选边
	int vex_index[MAXSIZE];//值表示出发点，下标表示到达点

	//先从顶点A开始
	weight[0] = 0; //vex_index某点与下标对应点的权重
	vex_index[0] = 0;

	//初始化,找到了A的所有侯选边,即全部非A结点
	for (i = 1; i < G->vertex_num; i++)
	{
		weight[i] = G->arc[0][i];
		vex_index[i] = 0;
	}

	//开始大循环,从第二行直到最后一行
	for (int i = 1; i < G->vertex_num; i++)
	{
		min = MAX;
		j = 0;
		k = 0;
		//找到最小边，与之连接
		while (j < G->vertex_num)
		{
			if (weight[j] != 0 && weight[j] < min)
			{
				min = weight[j];
				k = j;
			}
			j++;
		}

		//printf("(%d, %d)\n", vex_index[k], k);
		printf("(%c, %c)\n", G->vertex[vex_index[k]], G->vertex[k]);
		weight[k] = 0;

		//找新连接结点的侯选边,与它们全部连接
		for (j = 0; j < G->vertex_num; j++)
		{
			//weight的残党与新结点可连接的边进行比较，有比weight小的就替换,然后连接
			if (weight[j] != 0 && G->arc[k][j] < weight[j])
			{
				weight[j] = G->arc[k][j];
				vex_index[j] = k;
			}
		}

	}
}
//​变量 i 的作用
//​初始化阶段：
//
//在第一个循环中，i 从 1 遍历到顶点总数 G->vertex_num，用于初始化所有顶点（除了起点）的候选边权重（weight[]）和对应边的起点（vex_index[]）。
//例如：weight[i] = G->arc[0][i] 表示顶点 0 到顶点 i 的初始权重。
//​主循环阶段：
//
//在第二个循环中，i 从 1 遍历到 G->vertex_num - 1，用于控制生成树的扩展次数（每次加入一个顶点，共需要加入 n - 1 个顶点）。
//​变量 j 的作用
//​寻找最小边：
//
//在 while (j < G->vertex_num) 循环中，j 遍历所有顶点，寻找当前候选边中的最小权重边。
//例如：通过比较 weight[j] 和 min，找到未加入生成树的最小权重边。
//更新候选边：
//
//在 for (j = 0; j < G->vertex_num; j++) 循环中，j 遍历所有顶点，检查是否需要更新候选边权重（weight[j]）和对应起点（vex_index[j]）。
//例如：如果新加入的顶点 k 到顶点 j 的边权重更小，则更新 weight[j] = G->arc[k][j]。
//变量 k 的作用
//记录最小边的目标顶点：
//
//在寻找最小权重边的过程中，k 记录当前找到的最小权重边的目标顶点索引。
//例如：当 weight[j] < min 时，更新 k = j，表示顶点 j 是当前最小边的终点。
//标记顶点加入生成树：
//
//通过 weight[k] = 0（或修正后的 inMST[k] = true）标记顶点 k 已加入生成树。
//
//总结:
// * *i * *：控制主循环次数，表示已加入生成树的顶点数量。
// * *j * *：遍历所有顶点，用于寻找最小边或更新候选边。
// * *k * *：记录关键顶点的索引（如最小边的终点），用于后续操作。
int main()
{
	//Mat_Grph* G = (Mat_Grph*)malloc(sizeof(Mat_Grph));
	Mat_Grph G;
	create_graph(&G);
	prim(&G);
	return 0;
}