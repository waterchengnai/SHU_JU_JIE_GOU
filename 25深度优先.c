//#include <stdio.h>
////图的现实结构我们可以看作一种抽象的树
////代码结构我们可以看作上面学过的邻接矩阵
//
////深度优先类似与树的前根遍历,所以最终也是有递归实现的
//
////总领一下思路:
////1.创建一个结构体,包含成员顶点数量,边数量,顶点数组,二维数组
////其中顶点数量与二维矩阵的长宽对应
////2.定义一个visited数组记录被访问过的顶点
////3.初始化邻接矩阵,包括用顶点数组下表给对应顶点对应,给二维数组赋值0或1
////4.进行深度遍历,找与访问顶点的相邻且未被访问过的结点,然后向下递进
//
//typedef char VertexType;//顶点
//typedef int EdgeType;//边
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
////mat是矩阵英文简称
////Grph是图的英文简称
//
//int visited[MAXSIZE];
////这个数组是用来记录被访问过的顶点的
//
//void create_graph(Mat_Grph* G)
//{
//	G->vertex_num = 9;
//	G->edge_num = 15;
//
//	//在遍历中,我们用数组下表表示顶点
//	//这样会有很多优势,便于写代码
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
//	//初始化邻接矩阵,全部归零
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
//	//这一步是将矩阵对称化
//	//因为我们知道,无图像的邻接矩阵是对称的
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = 0; j < G->vertex_num; j++)
//		{
//			G->arc[j][i] = G->arc[i][j];
//		}
//	}
//}
//
////这里就是真的的深度遍历函数了
////深度遍历简称dfs
//void dfs(Mat_Grph G, int i)
//{
//	//对下标为i的顶点记录,并打印出来
//	visited[i] = 1;
//	printf("%c\n", G.vertex[i]);
//
//	//遍历每一行,直到第i行的第j个满足if判断,然后转到j行再次递归操作
//	for (int j = 0; j < G.vertex_num; j++)
//	{
//		if (G.arc[i][j] == 1 && visited[j] == 0)
//		//遇到之前没被访问过的相邻顶点
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
//	//初始化visited数组
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		visited[i] = 0;
//	}
//	dfs(G, 0);
//	return 0;
//}
//
