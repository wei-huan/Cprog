#include <stdio.h>

#include "../common/queue.h"
#include "search.h"

/*广度优先搜索联通子图的算法如下：*/
void Search(Graph *g, int v0, CALLBACK visit) /*广度优先搜索图g中v0所在的连通子图*/
{
    Queue q, *Q = &q;
    ArcNode *p;
    int w, v;

    visit(g->vertex[v0].data);
    visited[v0] = true;

    InitQueue(Q);      /*初始化空队*/

    EnterQueue(Q, v0); /* v0进队*/
    while (!IsEmpty(Q))
    {
        DeleteQueue(Q, &v);      /*队头元素出队*/
        p = g->vertex[v].firstarc;
        while (p != NULL)
        {
            w = p->adjvex;
            if (!visited[w])
            {
                visit(g->vertex[w].data);
                visited[w] = true;
                EnterQueue(Q, w);
            }
            p = p->nextarc;
        }
    }

    DestroyQueue(Q);
}