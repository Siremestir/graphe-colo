#include "recherche_locale.h"

int creeConflit(graph_colo graphe, int* tableauCouleur, node noeudModifie)
{
    return isNeighborColoredWithColoredColor(graphe, noeudModifie, tableauCouleur[noeudModifie-1]);
}

int indexCouleurMax(graph_colo graphe)
{
    int indexMax = 0;
    color couleurMax = 0;
    for (int i = 0; i < graphe->g->size; i++)
    {
        if(couleurMax < graphe->colors[i])
        {
            couleurMax = graphe->colors[i];
            indexMax = i;
        }
    }
    return indexMax;
}

int estSolutionOptimale(graph_colo graphe, node s)
{
    return getMaxColor(graphe) == graphe->colors[s-1];
}

void colorationRechercheLocale(graph_colo graphe)
{
    colorColoredGraphWithColoredColors(graphe);
    int maxCouleurIndex = indexCouleurMax(graphe);
    int tableauCouleur[graphe->g->size];
    for (int c = 0; c<graphe->g->size; c++)
    {
        tableauCouleur[c] = graphe->colors[c];
    }
    for (int i = 1; i <= graphe->g->size; i++)
    {
        tableauCouleur[maxCouleurIndex] = i;
        if (!creeConflit(graphe, tableauCouleur, maxCouleurIndex+1))
        {
            for (int s = i; s<=graphe->g->size; s++)
            {
                setColor(graphe, s, tableauCouleur[s-1]);
            }
            if(estSolutionOptimale(graphe, i))
            {
                return;
            }
        }
    }
}