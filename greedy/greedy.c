#include "greedy.h"

void colorerGraphGreedy(graph_colo graphe)
{
    color col = 1;

    for(int i = 1; i <= graphe->g->size; i++)
    {
        for(int j = 0; j < graphe->g->size; j++)
        {
            if(graphe->colors[j] != 0 && !isNeighborColoredWithColoredColor(graphe, i, graphe->colors[j]))
            {
                setColor(graphe, i, graphe->colors[j]);
                break;
            }
        }
        if(!isColored(graphe, i))
        {
            setColor(graphe, i, col);
            col+= 1;
        }
    }
}