#include <stdio.h>

//广度优先就类似树中的层序遍历，因为还是那句话，图是一种特殊的树
//那么这种算法也是使用队列和循环实现的



typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100


typedef struct
{
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

int visited[MAXSIZE];
int front = 0;
int rear = 0;
int queue[MAXSIZE];

//创建邻接矩阵的过程就没必要再看一次了
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
			G->arc[i][j] = 0;
		}
	}

	//A-B A-F
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	//B-C B-G B-I
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;

	//C-D C-I
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	//D-E D-G D-H D-I
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;

	//E-F E-H
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	//F-G
	G->arc[5][6] = 1;

	//G-H
	G->arc[6][7] = 1;

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

//bfs广度优先的简称
void bfs(Mat_Grph G)
{
	//1.首顶点入队,标记为已被访问过
	int i = 0;
	visited[i] = 1;
	printf("%c\n", G.vertex[i]);
	queue[rear] = i;
	rear++;
	

	//2.接着就是找与首顶点相连的顶点然后入队,首顶点出队,重复操作,直到队列为空
	while (front != rear)
	{

		i = queue[front];
		front++;

		//j再在我们后面的一些遍历算法中,一直表示邻接矩阵的列,这跟数学中是一致的
		for (int j = 0; j < G.vertex_num; j++)
		{
			if (G.arc[i][j] == 1 && visited[j] == 0)
			{
				visited[j] = 1;
				printf("%c\n", G.vertex[j]);
				queue[rear] = j;
				rear++;
			}
		}
	}

}

int main(int argc, char const* argv[])
{
	Mat_Grph G;
	create_graph(&G);

	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}
	bfs(G);
	return 0;
}