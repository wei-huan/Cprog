#include "search.h"

bool visited[MAX_VERTEX_NUM]; /*访问标志数组*/

void TraverseGraph(SEARCHMETHOD search, Graph *g, CALLBACK visit)
/*对图g进行深/广度优先搜索，Graph 表示图的一种存储结构，如邻接矩阵表示法或邻接表等*/
{
    int vi;

    for (vi = 0; vi < g->vexnum; vi++)
        visited[vi] = false;          /*访问标志数组初始*/

    for (vi = 0; vi < g->vexnum; vi++) /*调用深/广度遍历连通子图的操作*/
        if (!visited[vi])
            search(g, vi, visit); /*若图g是连通图，则此循环调用函数只执行一次*/
} /* TraverseGraph */