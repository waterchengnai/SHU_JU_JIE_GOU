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

//��ʼ��
DL* intit_Dlist();

//ͷ�巨

void Dheadinsert(DL* L, int inputdata);

//����

void Dergolist(DL* L);


//β�巨
DL* Dget_tail(DL* L);
DL* Dendinsert(DL* tail, int inputdata);

//ָ��λ�ò���

DL* Dinsert(DL* L, int inputdata, int place);

// ��ָ��λ��ɾ��
DL* DDelete(DL* L, int place);
#endif;