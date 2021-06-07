#include<stdio.h>
#include"string.h"

int main()
{
    String s, t;

    StrSet(&s, "Hello, world!");
    StrSet(&t, "Aloha!");

    StrPrint(&s);
    StrPrint(&t);

    return 0;
}