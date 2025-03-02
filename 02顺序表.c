//#include<stdio.h>
//#include<stdlib.h>
//#define maxlength 100
//typedef int Int;
//
////储存结构
//typedef struct list
//{
//	Int arr[maxlength];
//	Int len;
//}List;
////数据表实际上是在结构体里定义了一个数组和变量len
////数组用来记数据,len表示我要用到的长度,所以真正用的多的不是数组长度maxlength,而是len
//
////初始化
//void intit_list(List* p)
//{
//	p->len = 0;
//	//len是数据表长度,初始化后才能正常进行下面的数据表操作
//	//因为定义时没给len值
//}
//
////尾部添加元素
//int addlist(List* p,Int add_data)
//{
//
//	if (p->len >= maxlength)
//	{
//		printf("数据表已满");
//		return 0;
//	}
//	p->arr[p->len] = add_data;
//	p->len++;
//	return 1;
//}
//
////遍历
//
//void ergolist(List* p)
//{
//	for (int i = 0; i < p->len; i++)
//	{
//		printf("%d ", p->arr[i]);
//	
//	}
//	printf("\n");
//}
//
////插入数据
//
//int insertlist(List* p, int place, Int data)
//{
//	if (p->len >= place)
//	//判断插入位置是否在顺序表内
//	{
//		for (int i = p->len - 1; i >= place - 1; i--)
//			//注意数组要看索引
//		{
//			p->arr[i + 1] = p->arr[i];
//		}
//		p->arr[place - 1] = data;
//		p->len++;
//	}
//	//len是数据表长度,可看作数据表用到的长度;此处不len++,后面遍历便会少打印一位
//	return 0;
//}
//
////删除数据
//
//int dellist(List* p, int place)
//{
//	if(p->len>=place)
//	//判断插入元素是否在顺序表内
//	{
//		for (int i = place - 1; i <= p->len - 1; i++)
//		{
//			p->arr[i] = p->arr[i + 1];
//		}
//		p->len--;
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	//一.定义List类型的指针,方便后续函数的操作
//
//	//1.动态内存分布解决L的定义
//	//List* L=(List*)malloc(sizeof(List));
//	//if (L == NULL)
//	//{
//	//	printf("内存分配失败");
//	//	return 0;
//	//}
//
//	//2.先定义一个静态的结构体变量,再定义指针指向变量
//	List temp;
//	List* L = &temp;
//	
//	intit_list(L);
//	addlist(L, 50);
//	addlist(L, 100);
//	addlist(L, 90);
//	ergolist(L);
//	insertlist(L, 2, 80);
//	ergolist(L);
//	dellist(L, 1);
//	ergolist(L);
//}