#include "graph.h"


int main(int argc, char const *argv[])
{
    graph g = createGraph(4);

    newEdge(g, 1, 3);

    printGraph(g);

    freeGraph(&g);

    printGraph(g);

    return 0;
}
