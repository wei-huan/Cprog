#include <stdio.h>

//#define NONRECURSIVE

#ifdef NONRECURSIVE
#include "../common/stack.h"
#endif

#include "search.h"

#ifndef NONRECURSIVE

void Search(Graph *g, int v0, CALLBACK visit)
{
    visit(g->vertex[v0].data);
    visited[v0] = true;
    
    Arc w = FirstAdjVertex(g, v0);
    while (w.adj != -1)
    {
        if (!visited[w.adj])
            Search(g, w.adj, visit);
        w = NextAdjVertex(g, v0, w);
    }
}

#else

void Search(Graph *g, int v0, CALLBACK visit)
{
    Stack s, *S = &s;
    Arc w;
    int v;

    InitStack(S);      /*初始化空队*/

    Push(S, v0);
    while (!IsEmpty(S))
    {
        Pop(S, &v);
        if (!visited[v])
        {
            visit(g->vertex[v].data);
            visited[v] = true;

            w = FirstAdjVertex(g, v);
            while (w.adj != -1)
            {
                if (!visited[w.adj])
                    Push(S, w.adj);
                w = NextAdjVertex(g, v, w);
            }
        }
    }

    DestroyStack(S);
}
#endif