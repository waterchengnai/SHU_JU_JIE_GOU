#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include<stdlib.h>
typedef int Int;

typedef struct linked_list
{
	Int data;
	struct linked_list* next;

}lklist;
//初始化

lklist* intit_list();
//头插法

void headinsert(lklist* L, Int inputdata);


// 1. 获得尾节点的函数
lklist* get_tail(lklist* L);

// 2. 插入新数据，并获得新尾节点的函数
lklist* endinsert(lklist* L, int inputdata);


//指定位置插入

lklist* insert(lklist* L, Int inputdata, int place);

//在指定位置删除

lklist* Delete(lklist* L, int place);
//遍历

void ergolist(lklist* L);

//计算链表长度,注意,一般不计算首节点

int length(lklist* L);

//释放链表空间
//这里的释放是将链表初始化,首节点还是要保存的,首届点指向还得是NULL;

void freelist(lklist* L);
#endif;