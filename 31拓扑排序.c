//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int VertextType;
//typedef int EdgeType;
//
//#define MAXSIZE 100
////���������ǽ���¼�����Ⱥ�˳����㷨,���AOV
////��һ������ͼ��,������Ϊ,���Ϊ0�Ľ�����ֱ��ִ��
////��ȴ���0�Ĳ���ֱ��ִ��
////��ô���ǰ�����˳����������ж���ִ����
//
////����õ�����������
////����ʵ���벻���ڽӱ�,ջ������
////�����ȴ���һ���ڽӾ���
////Ȼ����˳�򴴽��ڽӱ�
////�ڽӱ��ÿ��Ԫ�ش���ڽṹ��������,�ṹ�����in,data,headnext
////����in��¼�ö�������,data��ʾ�ö����ʲô,headnext��ָ������,ָ����һ���ṹ��ָ���γ�����,��Ŷ���ĳ���ָ��˭
////����׼�������������
////1.Ȼ�����Ǳ�������,����������Ϊ0(��in=0),��ô����ջ
////2.�������Ϊ��Ķ��㶼��ջ��,�ͳ�ջ,����������Ϊ�׵���������Ľ���in-1(��Ȼ��in-1,�ǿ϶��ǶԶ�Ӧ�±������Ԫ��in����)
////3.�������������in-1��in=0��,�����Ǿ�Ҫ��ջ,����1.2.����,ֱ��ջ����û��Ԫ��
////���������ܿ�����,����һ��ѭ������
//
//typedef struct
//{
//	VertextType vertex[MAXSIZE];
//	EdgeType arc[MAXSIZE][MAXSIZE];
//	int vertex_num;
//	int edge_num;
//}Mat_Graph;
//
////���׽ڵ�Ľڵ�Ľṹ��
//typedef struct EdgeNode
//{
//	//��¼�±�
//	int edge_vex;
//	struct EdgeNode* next;
//}EdgeNode;
//
////�׽ڵ�Ľṹ��
//typedef struct VertextNode
//{
//	int in;
//	VertextType data;
//	EdgeNode* headnext;
//}VertextNode;
//
////�����Ǹ�VertextNode����һ��Adj_List[MAXSIZE]�ı���,����VertextNode����ľ���Adj_List���͵�����
////����Ĳ������ټ�(Ӧ��),�˼�һ���ṹ������ͻȻ�ʹ���ṹ������������
//typedef VertextNode Adj_List[MAXSIZE];//adjacency�ڽ�
//
//
////����ṹ�������˼,�����ڽӱ��ְ�������,���������������
//typedef struct
//{
//	Adj_List adj_list;
//	int vertex_num;
//	int edge_num;
//}Adj_Graph;
//
////�����ָ�����ṹ��ָ�����˱���,��������õ�ָ���ָ��
//typedef Adj_Graph* Adj_List_Graph;
//
////������ջ����غ���,֮ǰ�Ѿ�ѧ��
//int top = -1;
//int stack[MAXSIZE];
//
//void push(int e)
//{
//	if (top > MAXSIZE)
//	{
//		printf("����\n");
//		return;
//	}
//
//	top++;
//	stack[top] = e;
//}
//
//int pop()
//{
//	if (top == -1)
//	{
//		printf("�յ�\n");
//		return 0;
//	}
//
//	int elem = stack[top];
//	top--;
//	return elem;
//}
//
//int is_empty()
//{
//	if (top == -1)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//void create_graph(Mat_Graph* G)
//{
//	G->vertex_num = 14;
//	G->edge_num = 20;
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
//			G->arc[i][j] = 0;
//		}
//	}
//
//	G->arc[0][4] = 1;
//	G->arc[0][5] = 1;
//	G->arc[0][11] = 1;
//	G->arc[1][2] = 1;
//	G->arc[1][4] = 1;
//	G->arc[1][8] = 1;
//	G->arc[2][5] = 1;
//	G->arc[2][6] = 1;
//	G->arc[2][9] = 1;
//	G->arc[3][2] = 1;
//	G->arc[3][13] = 1;
//	G->arc[4][7] = 1;
//	G->arc[5][8] = 1;
//	G->arc[5][12] = 1;
//	G->arc[6][5] = 1;
//	G->arc[8][7] = 1;
//	G->arc[9][10] = 1;
//	G->arc[9][11] = 1;
//	G->arc[10][13] = 1;
//	G->arc[12][9] = 1;
//}
//
////�����ǳ�ʼ���ڽӱ���
//void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG)
//{
//	EdgeNode* e;
//
//	//��̬�ڴ����һ��Adj_Graph���ڴ�ռ�,Ҳ�����������������ĸ��ṹ��,�����䰴�ڽӾ���ֵ�������ͱ���
//	*ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));
//	(*ALG)->vertex_num = G.vertex_num;
//	(*ALG)->edge_num = G.edge_num;
//
//	//��������ÿ���ڽӱ�������׽ڵ��ʼ��
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		(*ALG)->adj_list[i].in = 0;
//		(*ALG)->adj_list[i].data = G.vertex[i];
//		(*ALG)->adj_list[i].headnext = NULL;
//	}
//
//	//�����Ǹ����ڽӾ�����ڽӱ�ķ��׽ڵ��ʼ��
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		for (int j = 0; j < G.vertex_num; j++)
//		{
//			if (G.arc[i][j] == 1)
//			{
//				//��̬�ڴ������׽ڵ�Ĵ�С
//				e = (EdgeNode*)malloc(sizeof(EdgeNode));
//				//�����j�Ǵ���Ķ�����±�,������������
//				e->edge_vex = j;
//
//				//�ײ巨
//				e->next = (*ALG)->adj_list[i].headnext;
//				(*ALG)->adj_list[i].headnext = e;
//				(*ALG)->adj_list[j].in++;
//			}
//		}
//	}
//}
//
//void topological_sort(Adj_List_Graph ALG)
//{
//	EdgeNode* e;
//	int curr;
//	int k;
//
//	//����ȷ���Ϊ0�Ķ�����ջ
//	for (int i = 0; i < ALG->vertex_num; i++)
//	{
//		if (ALG->adj_list[i].in == 0)
//		{
//			push(i);
//		}
//	}
//
//	while (is_empty() != 0)
//	{
//		//��ջ
//		curr = pop();
//		printf("V%d -> ", ALG->adj_list[curr].data);
//		//e��¼��ǰ��ջ�Ľڵ��Ӧ���׽ڵ���¸��ڵ�
//		e = ALG->adj_list[curr].headnext;
//
//		while (e != NULL)
//		{
//			k = e->edge_vex;
//			ALG->adj_list[k].in--;
//			if (ALG->adj_list[k].in == 0)
//			{
//				push(k);
//			}
//			e = e->next;
//		}
//	}
//}
//
//int main(int argc, char const* argv[])
//{
//	Mat_Graph G;
//	Adj_List_Graph ALG;
//	create_graph(&G);
//	create_adj_graph(G, &ALG);
//	topological_sort(ALG);
//	return 0;
//}