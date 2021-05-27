#ifndef RECHERCHE_LOCALE_H
#define RECHERCHE_LOCALE_H

#include "../graph_colo/graph_colo.h"
#include "../parser/parser.h"

int creeConflit(graph_colo graphe, int* tableauCouleur, node noeudModifie);

int estSolutionOptimale(graph_colo graphe, node s);

void colorationRechercheLocale(graph_colo graphe);


#endif