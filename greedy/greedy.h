#ifndef GREEDY_H
#define GREEDY_H

#include "../graph_colo/graph_colo.h"

void genererAreteAleatoire(graph_colo graphe, node s);

graph_colo genererGraphAleatoire(int taille);

/**
 * \brief Génére aléatoirement une couleur encore inutilisée
 * 
 * \param graphe: le graphe coloré pour lequel on génère la couleur
 */
color genererNouvelleCouleurAleatoire(graph_colo graphe);

void colorerGraphGreedy(graph_colo graphe);


#endif