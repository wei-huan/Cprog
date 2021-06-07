#include<stdio.h>
#include<stdlib.h>

#include"list.h"
#include"list_interface.h"

void print(ElemType *e)
{
    printf("%4d",*e);
}

int main()
{
    LListPtr list;

    InitList(&list);
    
    for (int i = 1; i < 10; ++i)
        InsList(list, i, i + 10);

    traverse(list, print);
    printf("\n");

    //printf("%d\n", reverse_i(list, 3));

    //DestroyList(list);

    return 0;
}