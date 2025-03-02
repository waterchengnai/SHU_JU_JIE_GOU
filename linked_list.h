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
//��ʼ��

lklist* intit_list();
//ͷ�巨

void headinsert(lklist* L, Int inputdata);


// 1. ���β�ڵ�ĺ���
lklist* get_tail(lklist* L);

// 2. ���������ݣ��������β�ڵ�ĺ���
lklist* endinsert(lklist* L, int inputdata);


//ָ��λ�ò���

lklist* insert(lklist* L, Int inputdata, int place);

//��ָ��λ��ɾ��

lklist* Delete(lklist* L, int place);
//����

void ergolist(lklist* L);

//����������,ע��,һ�㲻�����׽ڵ�

int length(lklist* L);

//�ͷ�����ռ�
//������ͷ��ǽ������ʼ��,�׽ڵ㻹��Ҫ�����,�׽��ָ�򻹵���NULL;

void freelist(lklist* L);
#endif;