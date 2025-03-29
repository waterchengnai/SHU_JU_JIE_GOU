#include <stdio.h>

typedef int VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000

//floyd算法是一个三重循环，能够查找所有顶点间的最短路径以及权值
//但相应的，他的时间复杂度为V(O^3)

typedef struct
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

void createGraph(Mat_Graph* G)
{
	G->vertex_num = 9;
	G->edge_num = 16;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
	}

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


	G->arc[0][1] = 1;
	G->arc[0][2] = 5;

	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;

	G->arc[3][4] = 2;
	G->arc[3][6] = 3;

	G->arc[4][5] = 3;
	G->arc[4][6] = 6;
	G->arc[4][7] = 9;

	G->arc[5][7] = 5;

	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = i; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void floyd(Mat_Graph G)
{
	int path[MAXSIZE][MAXSIZE];
	int distance[MAXSIZE][MAXSIZE];

	//该算法的逻辑比较简单,是找到从j到k顶点间,是否有一个中间结点i,是二者的路径缩短
	//创建了两个二维数组path,distance
	//distance一开始记录G.arc的所有值
	//path记录的是顶点,且分两种情况
	//1.如果j到k是直接到的,那么path[j][k]=k,直接记录终点
	//2.如果经过了中间点,那么path[j][k]=i,记录中间顶点
	//然后三层循环,遍历所有ijk的排列组合,查找是否有distance[j][k] > distance[j][i] + distance[i][k]
	//有的话就更改distance这个二维数组中distance[j][k] 为 distance[j][i] + distance[i][k];
	
	//提问,假如j到k经过了两个中间点m,n咋办?
	//那我问你,j到n是不是肯定要记录中间点m,那么distance[j][n] = distance[j][m] + distance[m][n]
	//那么j到k是不是会遍历出中间结点n的这种情况,而此时distance[j][n]已经更新过了,所以就实现了
	//distance[j][k] > distance[j][n] + distance[n][k](其中distance[j][n] = distance[j][m] + distance[m][n])
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			distance[i][j] = G.arc[i][j];
			path[i][j] = j;
		}
	}
	// j:起始顶点　i:中转顶点　k:终止顶点
	//这里需要注意，必须循环从外到内时i，j，k的顺序
	//否则该算法会出错
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			for (int k = 0; k < G.vertex_num; k++)
			{
				if (distance[j][k] > distance[j][i] + distance[i][k])
				{
					distance[j][k] = distance[j][i] + distance[i][k];
					path[j][k] = path[j][i];
				}
			}
		}
	}

	int k;
	//最后遍历两个二维数组的上三角,就能得知所有顶点的路径和权值
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = i + 1; j < G.vertex_num; j++)
		{
			printf("V%d->V%d weight:%d ", i, j, distance[i][j]);
			k = path[i][j];
			printf("path:V%d", i);
			while (k != j)
			{
				printf("->V%d", k);
				k = path[k][j];
			}
			printf("->V%d\n", j);
		}
		printf("\n");
	}

}



int main(int argc, char const* argv[])
{
	Mat_Graph G;
	createGraph(&G);
	floyd(G);

	return 0;
}