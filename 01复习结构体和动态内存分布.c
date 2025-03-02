#include<stdio.h>
//结构体
/*struct point
{
	int x;
	int y;
};
//起别名
typedef struct
{
	int x;
	int y;
}another_name;
struct point mypoint(int x, int y)//函数的类型是根据返回值确定的

{
	struct point temp;
	temp.x=x;
	temp.y=y;
	return temp;
};

int main()
{
	struct point p = {0,50};
	struct point* pp = &p;
	p = mypoint(50, 0);
	printf("%d %d\n", pp->x, p.y);
	another_name a = { 10,50 };
	printf("%d %d", a.x, a.y);
}*/

//#include<stdlib.h>
//int main()
//{
//	int* arr = (int*)malloc(4 * sizeof(int));
//	//arr[] = {1,3,5,6};错误的写法
//	//动态内存分配定义的地址只能一个一个赋值
//	if (arr == NULL)
//	{
//		printf("Error");
//		return 1;
//	}
//	free(arr);
//}

