#pragma once

#include<stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
}Node,Stack,*StackPtr ;

extern void init(StackPtr s);
extern char pop(StackPtr s);
extern void push(StackPtr s, char c);
extern bool match(char *str);