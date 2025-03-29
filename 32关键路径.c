#include <stdio.h>
#include <stdlib.h>

typedef int VertextType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff

//关键路径是基于拓扑排序基础上的
//他还要考虑有向图带权重的问题
//其中又一些概念要知道
//etv:事件最早发生的时间(earliest time ofvertex)
//ltv:事件最晚发生的时间(lastest time of vertex
//我举例子来方便理解一下:假如V0是起点,要执行V1,V2,对应时间是3,4,且V1,V2执行完后执行V3,对应时间是5,8
//那么问完成V3的etv是多少
//答案是4+8=12,而不是3+5=8,因为只有完成了V1和V2才能完成V3,这是拓扑逻辑的基础
//而且我们认为这两件事是同时执行的,所以应该取完成时间的最大值,即max{V0->V1->V3,V0->V2->V3}

//ltv刚好相反,我们是倒过来推算一个事最晚能啥时候发生
//还拿上面的例子,我们知道了V3最早12完成,那么12-5=7就是V1的最晚完成时间,也就是能拖则拖的逻辑
//但是V0啥时候开始干呢
//从V1,V2倒退,V0的ltv分别是4,0,此时应该取0,即min{0,4}
//因为V0从4开始干的话,V2开始时间就是8了,这超出了V2的ltv=4

//那么关键路径是啥呢，在一个图中，我们把所有etv和ltv相等的节点连接起来，这个路径就是关键路径
//关键路径的顶点早完成,晚完成都会影响最终完成时间

//由于关键路径是基于拓扑排序逻辑上的,下面的代码也大部分相同,只标出不同处


typedef struct
{
	VertextType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;


//1.这里多加了权重这个成员
typedef struct EdgeNode
{
	int edge_vex;
	int weight;
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertextNode
{
	int in;
	VertextType data;
	EdgeNode* headnext;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];

typedef struct
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;


void create_graph(Mat_Graph* G)
{
	G->vertex_num = 10;
	G->edge_num = 13;

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			//这里有权重,不相邻应标为MAX
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

	G->arc[0][1] = 3;
	G->arc[0][2] = 4;
	G->arc[1][3] = 5;
	G->arc[1][4] = 6;
	G->arc[2][3] = 8;
	G->arc[2][5] = 7;
	G->arc[3][4] = 3;
	G->arc[4][6] = 9;
	G->arc[4][7] = 4;
	G->arc[5][7] = 6;
	G->arc[6][9] = 2;
	G->arc[7][8] = 5;
	G->arc[8][9] = 3;

}

void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG)
{
	EdgeNode* e;

	*ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));
	(*ALG)->vertex_num = G.vertex_num;
	(*ALG)->edge_num = G.edge_num;

	for (int i = 0; i < G.vertex_num; i++)
	{
		(*ALG)->adj_list[i].in = 0;
		(*ALG)->adj_list[i].data = G.vertex[i];
		(*ALG)->adj_list[i].headnext = NULL;
	}

	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			if (G.arc[i][j] != 0 && G.arc[i][j] < MAX)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->edge_vex = j;
				//2.这里多了给权重赋值的操作
				e->weight = G.arc[i][j];

				//还是头插法
				e->next = (*ALG)->adj_list[i].headnext;
				(*ALG)->adj_list[i].headnext = e;
				(*ALG)->adj_list[j].in++;
			}
		}
	}
}

//这里开始有很多不同了,但是还是比较好理解
void critical_path(Adj_List_Graph ALG)
{
	EdgeNode* e;

	//3.这里创建两个栈,第一个进行拓扑排序,不过出栈元素进入第二个栈中,第二个进行对出栈的元素再出栈
	int top = -1;
	int top2 = -1;
	int stack[MAXSIZE];
	int stack2[MAXSIZE];

	//4.创建ltv,etv两个数组
	int etv[MAXSIZE];
	int ltv[MAXSIZE];
	int curr;
	int k;

	//这里还是相同的
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			top++;
			stack[top] = i;
		}
	}

	//5.这里初始化etv全为0
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		etv[i] = 0;
	}

	while (top != -1)
	{

		curr = stack[top];
		top--;
		printf("V%d -> ", ALG->adj_list[curr].data);

		//6.上边出栈,下边入栈
		top2++;
		stack2[top2] = curr;

		e = ALG->adj_list[curr].headnext;

		while (e != NULL)
		{
			k = e->edge_vex;
			ALG->adj_list[k].in--;
			if (ALG->adj_list[k].in == 0)
			{
				top++;
				stack[top] = k;
			}


			//7.如果当前顶点(首节点)的etv加上它的子节点e(非首节点)>e的etv,那么我就要更新e的etv,就上上面说的,etv取最大值
			//是从前往后推的逻辑,跟下面ltv的逻辑是相反的
			if (etv[curr] + e->weight > etv[k])
			{
				etv[k] = etv[curr] + e->weight;
			}
			e = e->next;
		}
	}
	printf("End\n");

	printf("etv: ");
	//8.这里是打印etv数组
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", etv[i]);
	}
	printf("End\n");

	//9.这里是初始化ltv,不是真的操作
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		ltv[i] = etv[ALG->vertex_num - 1];
	}

	while (top2 != -1)
	{
		curr = stack2[top2];
		top2--;

		e = ALG->adj_list[curr].headnext;
		//这里的代码更上面的逻辑是非常相似的,只是干的事情不同
		while (e != NULL)
		{
			k = e->edge_vex;

			//如果e的ltv-e的权重小于curr的ltv值,那么就该更新curr的ltv,ltv取更小的那个
			if (ltv[k] - e->weight < ltv[curr])
			{
				ltv[curr] = ltv[k] - e->weight;
			}
			e = e->next;
		}
	}

	printf("ltv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", ltv[i]);
	}
	printf("End\n");

	//这里再比较etv,ltv中相同的顶点,就完事了
	for (int i = 0; i < ALG->vertex_num; ++i)
	{
		if (etv[i] == ltv[i])
		{
			printf("V%d -> ", i);
		}
	}


}

int main(int argc, char const* argv[])
{
	Mat_Graph G;
	Adj_List_Graph ALG;
	create_graph(&G);
	create_adj_graph(G, &ALG);
	critical_path(ALG);
	return 0;
}