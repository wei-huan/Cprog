#include "search.h"

/*用邻接矩阵方式实现深度优先搜索*/
void Search(Graph *g, int v0, CALLBACK visit) /* 图g 为邻接矩阵类型AdjMatrix */
{
    visit(g->vertex[v0].data);
    visited[v0] = true;

    for (int vj = 0; vj < g->vexnum; vj++)
        if (!visited[vj] && g->arcs[v0][vj].adjvex == 1)
            Search(g, vj, visit);
} /* DepthFirstSearch */
