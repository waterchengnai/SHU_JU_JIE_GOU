//#include <stdio.h>
////ͼ����ʵ�ṹ���ǿ��Կ���һ�ֳ������
////����ṹ���ǿ��Կ�������ѧ�����ڽӾ���
//
////�����������������ǰ������,��������Ҳ���еݹ�ʵ�ֵ�
//
////����һ��˼·:
////1.����һ���ṹ��,������Ա��������,������,��������,��ά����
////���ж����������ά����ĳ����Ӧ
////2.����һ��visited�����¼�����ʹ��Ķ���
////3.��ʼ���ڽӾ���,�����ö��������±����Ӧ�����Ӧ,����ά���鸳ֵ0��1
////4.������ȱ���,������ʶ����������δ�����ʹ��Ľ��,Ȼ�����µݽ�
//
//typedef char VertexType;//����
//typedef int EdgeType;//��
//
//#define MAXSIZE 100
//
//typedef struct
//{
//	VertexType vertex[MAXSIZE];
//	EdgeType arc[MAXSIZE][MAXSIZE];
//	int vertex_num;
//	int edge_num;
//}Mat_Grph;
////mat�Ǿ���Ӣ�ļ��
////Grph��ͼ��Ӣ�ļ��
//
//int visited[MAXSIZE];
////���������������¼�����ʹ��Ķ����
//
//void create_graph(Mat_Grph* G)
//{
//	G->vertex_num = 9;
//	G->edge_num = 15;
//
//	//�ڱ�����,�����������±��ʾ����
//	//�������кܶ�����,����д����
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
//	//��ʼ���ڽӾ���,ȫ������
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = 0; j < G->vertex_num; j++)
//		{
//			G->arc[i][j] = 0;
//		}
//	}
//
//	//A-B A-F
//	G->arc[0][1] = 1;
//	G->arc[0][5] = 1;
//
//	//B-C B-G B-I
//	G->arc[1][2] = 1;
//	G->arc[1][6] = 1;
//	G->arc[1][8] = 1;
//
//	//C-D C-I
//	G->arc[2][3] = 1;
//	G->arc[2][8] = 1;
//
//	//D-E D-G D-H D-I
//	G->arc[3][4] = 1;
//	G->arc[3][6] = 1;
//	G->arc[3][7] = 1;
//	G->arc[3][8] = 1;
//
//	//E-F E-H
//	G->arc[4][5] = 1;
//	G->arc[4][7] = 1;
//
//	//F-G
//	G->arc[5][6] = 1;
//
//	//G-H
//	G->arc[6][7] = 1;
//
//	//��һ���ǽ�����Գƻ�
//	//��Ϊ����֪��,��ͼ����ڽӾ����ǶԳƵ�
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = 0; j < G->vertex_num; j++)
//		{
//			G->arc[j][i] = G->arc[i][j];
//		}
//	}
//}
//
////���������ĵ���ȱ���������
////��ȱ������dfs
//void dfs(Mat_Grph G, int i)
//{
//	//���±�Ϊi�Ķ����¼,����ӡ����
//	visited[i] = 1;
//	printf("%c\n", G.vertex[i]);
//
//	//����ÿһ��,ֱ����i�еĵ�j������if�ж�,Ȼ��ת��j���ٴεݹ����
//	for (int j = 0; j < G.vertex_num; j++)
//	{
//		if (G.arc[i][j] == 1 && visited[j] == 0)
//		//����֮ǰû�����ʹ������ڶ���
//		{
//			dfs(G, j);
//		}
//	}
//}
//
//
//int main(int argc, char const* argv[])
//{
//	Mat_Grph G;
//	create_graph(&G);
//
//	//��ʼ��visited����
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		visited[i] = 0;
//	}
//	dfs(G, 0);
//	return 0;
//}
//
