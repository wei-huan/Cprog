#include"list_interface.h"
#include"list.h"

void InitList(LListPtr L)
{
    L->last=0;
}

bool InsList(LListPtr L, int i,ElemType e)
{
    if(i<1||i>L->last+2)
    return false;
    for ( int j= L->last; j>=i-1; j--)
        L->elem[j+1]=L->elem[j];
    L->elem[i-1]=e;
    ++L->last;
    return true;
}

bool DelList(LListPtr L, int i,ElemType *e);

void TraverseList(LListPtr L,CALLBACK f)
{
    for (int i = 0; i < L->last; i++)
        f(&L->elem[i]);
    
}