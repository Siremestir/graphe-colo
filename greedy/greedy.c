#include "greedy.h"

void genererAreteAleatoire(graph_colo graphe, node s)
{
    for (int i=1; i <= graphe->g->size; i++)
    {
        if (i != s)
        {
            if (!edgeExists(graphe->g, s, i))
            {
                //Pas tellement aléatoire ce rand...
                //printf("%i\n", rand()%2);
                if((rand()%2))
                {
                    newEdgeColo(graphe, s, i);
                }
            }
        }
    }
}

graph_colo genererGraphAleatoire(int taille)
{
    graph_colo graphe = createGraphColo(taille);
    int arret = ((int)graphe->g->size / 2) + 1;
    for (int i=1; i < arret; i++)
    {
        genererAreteAleatoire(graphe, i);
    }
    return graphe;
}

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
            col++;
        }
    }
}