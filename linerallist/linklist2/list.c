#pragma once

#include"listelemtype.h"
#include"list.h"
#include"list_interface.h"
#include"stdio.h"

void traverse(LListPtr L, CALLBACK f)
{
    NodePtr p = L->next;
	while (p != NULL)
	{
        f(&p->data);
        p = p->next;
	}
}

bool InsList(LListPtr L, int i, ElemType e)
{
	NodePtr p = L, q;
	int k = 1;
    
    /*从"头"开始，查找第i-1个结点*/
	while (p != NULL && k < i)  /*表未查完且未查到第i-1个时重复，找到p指向第i-1个*/ 
	{ 
		p = p->next;
		++k; 
	}
    
	if (p == NULL && k < i)   /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return false;
	}

	q = (NodePtr)malloc(sizeof(Node));   /*申请一个新的结点S */
	q->data = e;                       /*值e置入s的数据域*/
	q->next = p->next;				/*修改指针，完成插入操作*/
	p->next = q;
	
    return true;
}

void DestroyList(LListPtr L)
{
    NodePtr p = L, q;
	while (p != NULL)
	{
        q = p;
		p = p->next;
		free(q);
	}
}