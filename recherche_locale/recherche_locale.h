#ifndef RECHERCHE_LOCALE_H
#define RECHERCHE_LOCALE_H

#include "../graph_colo/graph_colo.h"
#include "../parser/parser.h"

/**
 * \brief Cette fonction vérifie si il n'y a pas de conflict de coloration au niveau d'un noeud donné.
 * \param graphe - Le graphe à vérifier.
 * \param tableauCouleur - Le tableau des couleurs qu'on veut utiliser sur le graphe.
 * \param noeudModifie - Le noeud qui vient d'être modifié.
 * 
 * \return 1 Si il trouve un conflict.
 * \return 0 Si il ne trouve aucun conflict.
 */
int creeConflit(graph_colo graphe, int* tableauCouleur, node noeudModifie);

/**
 * \brief Cette fonction vérifie si la solution actuelle est optimale.
 * \param graphe - Le graphe à vérifier.
 * \param s - un sommet.
 * 
 * \return 1 si la solution n'est pas optimale.
 * \return 0 si la solution est optimale.
 */
int estSolutionOptimale(graph_colo graphe, node s);

/**
 * \brief Cette fonction utilise recherche locale pour colorer le graphe de manière optimale.
 * \param graphe - Le graphe à colorer.
 * 
 * \return rien.
 */
void colorationRechercheLocale(graph_colo graphe);


#endif