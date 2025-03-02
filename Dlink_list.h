#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include<stdlib.h>

typedef struct suibianba {
	int data;
	struct suibianba* prev;
	struct suibianba* next;
}DL;

//初始化
DL* intit_Dlist();

//头插法

void Dheadinsert(DL* L, int inputdata);

//遍历

void Dergolist(DL* L);


//尾插法
DL* Dget_tail(DL* L);
DL* Dendinsert(DL* tail, int inputdata);

//指定位置插入

DL* Dinsert(DL* L, int inputdata, int place);

// 在指定位置删除
DL* DDelete(DL* L, int place);
#endif;