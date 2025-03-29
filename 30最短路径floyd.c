#include <stdio.h>

typedef int VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000

//floyd�㷨��һ������ѭ�����ܹ��������ж��������·���Լ�Ȩֵ
//����Ӧ�ģ�����ʱ�临�Ӷ�ΪV(O^3)

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

	//���㷨���߼��Ƚϼ�,���ҵ���j��k�����,�Ƿ���һ���м���i,�Ƕ��ߵ�·������
	//������������ά����path,distance
	//distanceһ��ʼ��¼G.arc������ֵ
	//path��¼���Ƕ���,�ҷ��������
	//1.���j��k��ֱ�ӵ���,��ôpath[j][k]=k,ֱ�Ӽ�¼�յ�
	//2.����������м��,��ôpath[j][k]=i,��¼�м䶥��
	//Ȼ������ѭ��,��������ijk���������,�����Ƿ���distance[j][k] > distance[j][i] + distance[i][k]
	//�еĻ��͸���distance�����ά������distance[j][k] Ϊ distance[j][i] + distance[i][k];
	
	//����,����j��k�����������м��m,nզ��?
	//��������,j��n�ǲ��ǿ϶�Ҫ��¼�м��m,��ôdistance[j][n] = distance[j][m] + distance[m][n]
	//��ôj��k�ǲ��ǻ�������м���n���������,����ʱdistance[j][n]�Ѿ����¹���,���Ծ�ʵ����
	//distance[j][k] > distance[j][n] + distance[n][k](����distance[j][n] = distance[j][m] + distance[m][n])
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			distance[i][j] = G.arc[i][j];
			path[i][j] = j;
		}
	}
	// j:��ʼ���㡡i:��ת���㡡k:��ֹ����
	//������Ҫע�⣬����ѭ�����⵽��ʱi��j��k��˳��
	//������㷨�����
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
	//������������ά�����������,���ܵ�֪���ж����·����Ȩֵ
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