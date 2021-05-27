#ifndef COLO_GENETIQUE_H
#define COLO_GENETIQUE_H

#include "../graph_colo/graph_colo.h"

#include <time.h>

void genererAretesAleatoires(graph_colo graphe, node s);

graph_colo genererGrapheAleatoire(int taille);

void muterGraphe(graph_colo graphe);

graph_colo selectionnerGraphe(graph_colo* graphes);

#endif