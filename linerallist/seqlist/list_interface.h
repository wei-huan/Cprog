#pragma once

#include "list.h"
#include<stdbool.h>

extern void InitList(LListPtr L);
extern bool InsList(LListPtr L, int i,ElemType e);
extern bool DelList(LListPtr L, int i,ElemType *e);

typedef void (*CALLBACK)(ElemType*);

extern void TraverseList(LListPtr L,CALLBACK f);


