#include <stdio.h>
#include <stdlib.h>

typedef int VertextType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff

//�ؼ�·���ǻ���������������ϵ�
//����Ҫ��������ͼ��Ȩ�ص�����
//������һЩ����Ҫ֪��
//etv:�¼����緢����ʱ��(earliest time ofvertex)
//ltv:�¼���������ʱ��(lastest time of vertex
//�Ҿ��������������һ��:����V0�����,Ҫִ��V1,V2,��Ӧʱ����3,4,��V1,V2ִ�����ִ��V3,��Ӧʱ����5,8
//��ô�����V3��etv�Ƕ���
//����4+8=12,������3+5=8,��Ϊֻ�������V1��V2�������V3,���������߼��Ļ���
//����������Ϊ����������ͬʱִ�е�,����Ӧ��ȡ���ʱ������ֵ,��max{V0->V1->V3,V0->V2->V3}

//ltv�պ��෴,�����ǵ���������һ����������ɶʱ����
//�������������,����֪����V3����12���,��ô12-5=7����V1���������ʱ��,Ҳ�����������ϵ��߼�
//����V0ɶʱ��ʼ����
//��V1,V2����,V0��ltv�ֱ���4,0,��ʱӦ��ȡ0,��min{0,4}
//��ΪV0��4��ʼ�ɵĻ�,V2��ʼʱ�����8��,�ⳬ����V2��ltv=4

//��ô�ؼ�·����ɶ�أ���һ��ͼ�У����ǰ�����etv��ltv��ȵĽڵ��������������·�����ǹؼ�·��
//�ؼ�·���Ķ��������,����ɶ���Ӱ���������ʱ��

//���ڹؼ�·���ǻ������������߼��ϵ�,����Ĵ���Ҳ�󲿷���ͬ,ֻ�����ͬ��


typedef struct
{
	VertextType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;


//1.��������Ȩ�������Ա
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
			//������Ȩ��,������Ӧ��ΪMAX
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
				//2.������˸�Ȩ�ظ�ֵ�Ĳ���
				e->weight = G.arc[i][j];

				//����ͷ�巨
				e->next = (*ALG)->adj_list[i].headnext;
				(*ALG)->adj_list[i].headnext = e;
				(*ALG)->adj_list[j].in++;
			}
		}
	}
}

//���￪ʼ�кܶ಻ͬ��,���ǻ��ǱȽϺ����
void critical_path(Adj_List_Graph ALG)
{
	EdgeNode* e;

	//3.���ﴴ������ջ,��һ��������������,������ջԪ�ؽ���ڶ���ջ��,�ڶ������жԳ�ջ��Ԫ���ٳ�ջ
	int top = -1;
	int top2 = -1;
	int stack[MAXSIZE];
	int stack2[MAXSIZE];

	//4.����ltv,etv��������
	int etv[MAXSIZE];
	int ltv[MAXSIZE];
	int curr;
	int k;

	//���ﻹ����ͬ��
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			top++;
			stack[top] = i;
		}
	}

	//5.�����ʼ��etvȫΪ0
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		etv[i] = 0;
	}

	while (top != -1)
	{

		curr = stack[top];
		top--;
		printf("V%d -> ", ALG->adj_list[curr].data);

		//6.�ϱ߳�ջ,�±���ջ
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


			//7.�����ǰ����(�׽ڵ�)��etv���������ӽڵ�e(���׽ڵ�)>e��etv,��ô�Ҿ�Ҫ����e��etv,��������˵��,etvȡ���ֵ
			//�Ǵ�ǰ�����Ƶ��߼�,������ltv���߼����෴��
			if (etv[curr] + e->weight > etv[k])
			{
				etv[k] = etv[curr] + e->weight;
			}
			e = e->next;
		}
	}
	printf("End\n");

	printf("etv: ");
	//8.�����Ǵ�ӡetv����
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", etv[i]);
	}
	printf("End\n");

	//9.�����ǳ�ʼ��ltv,������Ĳ���
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		ltv[i] = etv[ALG->vertex_num - 1];
	}

	while (top2 != -1)
	{
		curr = stack2[top2];
		top2--;

		e = ALG->adj_list[curr].headnext;
		//����Ĵ����������߼��Ƿǳ����Ƶ�,ֻ�Ǹɵ����鲻ͬ
		while (e != NULL)
		{
			k = e->edge_vex;

			//���e��ltv-e��Ȩ��С��curr��ltvֵ,��ô�͸ø���curr��ltv,ltvȡ��С���Ǹ�
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

	//�����ٱȽ�etv,ltv����ͬ�Ķ���,��������
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