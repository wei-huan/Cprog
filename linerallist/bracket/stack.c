#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<stdbool.h>
#include "stack.h"

void init(StackPtr s)
{
    s->next=NULL;
}

void push(StackPtr s, char c)
{
    Node* p=(Node *)malloc(sizeof(Node));
    p->data=c;

    p->next = s->next;
    s->next = p;
}
char pop(StackPtr s)
{
    Node* p = s->next;

    if (p == NULL)
    {
        printf("Stack underflow!");
        exit(0);
    }
    
    char c = p->data;
    s->next = p->next;
    free(p);

    return c;
}

bool match(char *str)
{
    Stack s;
    char ch;

    init(&s);

    char *p = str;
    while (*p != '\0')
    {
        switch (*p)
        {
        case '(':
        case '{':
        case '[':
            push(&s, *p);
            break;

        case ')':
        case '}':
        case ']':
            ch = pop(&s);
            if (!(
                ch == '(' && *p == ')'
            ||  ch == '{' && *p == '}'
            ||  ch == '[' && *p == ']'
            ))
            {
                printf("Not match\n");
                return false;
            }
        }

        ++p;
    }

    return true;
}