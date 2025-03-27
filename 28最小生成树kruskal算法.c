//#include <stdio.h>
//#include <stdlib.h>
//
//typedef char VertexType;
//typedef int EdgeType;
//
////kruskal�㷨��ɵ����ҵ����бߣ�Ȼ�����Ǵ�С��������һ���ҵ��������ӵ���Ȩֵ��С�ı�
////1.�����ڽӾ����������(�������Խ���),�ҵ����б�,��һ���ṹ������(edges[MAX])��¼���ӵĶ����Ȩֵ
////2.Ȼ��дһ������sortedges�����㰴Ȩֵ���д�С��������(��������򷽷��������,����������ֻ��ð��)
////3.���Ŵ���һ��parent����,��֮ǰ��weightһ����¼�����������,�������в�ͬ,������Ϊ�����ⲿ��������find�������е�,������ᵽ
////4.��������ӡ����
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
////��һ���ؼ���
//int find(int* parent, int index)
//{
//	//parentһ��ʼ��ʼ����0,���Խ���whlieѭ������������parent����ֵ��
//	//����ֵ�˾�֤���˼��Ѿ��ҵ��Լ�����һ����,����ô���ٲ�һ����?
//	//���������ǽ�������������Ѿ�����һ����±���parent�����ҵ�������һ��
//	//��������һ�븳ֵ��index�ٴ���
//	//���������˼��������,���±����ͨ���������һ��,���֤�����Ǹ������ӵ�
//	//����������һ�뻹����һ��,���������������һ��,ֱ���ҵ�û����һ���
//	//˳������
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
//	//3.�����Ƚ����˳�ʼ��
//	int parent[MAXSIZE];
//
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		parent[i] = 0;
//	}
//
//	int n, m;
//	//n�Ǽ�¼parent����������ǰ�����±�,m�����Ӻ�����±�
//	//����i=0�ĳ�ʼ�������edges�������ĵ�һ��Ԫ�ؿ�ʼ��
//	for (int i = 0; i < G.edge_num; i++)
//	{
//		//�������Ҫ��parent��ֵ��,����Ҫע�����find�������߼�
//		n = find(parent, edges[i].begin);
//		m = find(parent, edges[i].end);
//		
//		//*********************************************//
//		//�ڶ����ؼ���,��ι���γɻ�,����ÿ�ζ�������Ȩֵ��̵�·��,��������ô����γɻ���·��?
//		//�𰸾��ڵ�һ���ؼ����������
//		//��������˵��,����������ӵ�ʱ����������Ѿ���ռ����,����Ҫ��������һ��,��������һ�����һ��,�Դ�����
//		//��ô��һ�����ϵ����ƾͰ��Լ���������,�������ʱ��ͱ�����ҵ����ϵ��������,�������ܱ�֤�������н��Ķ����ǲ��ظ���
//		//��Ϊ����parent��begin��end�������������й�,��󶼻��ҵ���,��ô����ʵ������������,�����Ӿͻ�ɻ�,�ͱ�if��ס��
//		//���begin��endֻ��һ����û��һ��������,��ô�϶����Ӻ󲻻�ɻ�,��begin��end�϶�����ͬ,���Ը������ظ�
//		//�������Ͻ�㶼���ظ�
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