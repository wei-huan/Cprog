#include <stdio.h>

#include "../common/queue.h"
#include "search.h"

void Search(Graph *g, int v0, CALLBACK visit)
{
    int v, j; // 用于遍历元素
    Arc w;
    Queue q, *Q = &q;

    visit(g->vertex[v0].data);
    visited[v0] = true; // 设置该顶点i已被访问

    InitQueue(Q); // 初始化队列

    EnterQueue(Q, v0); // 将该顶点i入队
    while (!IsEmpty(Q)) // 当队列非空时，进行循环
    {
        DeleteQueue(Q, &v); // 将队头元素出队，赋值给i

        w = FirstAdjVertex(g, v);
        while (w.adj != -1)
        {  
            j = w.adj;
            if (!visited[j])
            {
                visit(g->vertex[j].data);
                visited[j] = true; // 设置顶点j已被访问
                EnterQueue(Q, j);  // 将顶点j入队
            }

            w = NextAdjVertex(g, v, w);
        }
    }

    DestroyQueue(Q);
}