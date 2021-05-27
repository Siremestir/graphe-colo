#include "colo_genetique.h"

void genererAretesAleatoires(graph_colo graphe, node s)
{
    srand(time(NULL));
    for (node i = 1; i <= graphe->g->size; i++)
    {
        if (i != s && !edgeExists(graphe->g, i, s))
        {
            if (rand()%2)
            {
                newEdgeColo(graphe, s, i);
            }
        }
    }
}

graph_colo genererGrapheAleatoire(int taille)
{
    graph_colo graphe = createGraphColo(taille);
    int arret = ((int) taille/2) +1;
    for (node i = 1; i <= arret; i++)
    {
        genererAretesAleatoires(graphe, i);
    }
    return graphe;
}