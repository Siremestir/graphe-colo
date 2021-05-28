#ifndef COLO_GENETIQUE_H
#define COLO_GENETIQUE_H

#include "../graph_colo/graph_colo.h"

#include <time.h>

/**
 * \brief Cette fonction génére une population aléatoire.
 * \param taille - La taille de la population à créer.
 * \param graphe - Le graphe pour lequel on génére une populaion.
 * 
 * \return elle retourne une population de coloration aléatoire.
 */
color** genererPopulationAleatoire(int taille, graph_colo graphe);

/**
 * \brief Cette fonction génére une coloration aléatoire pour le graphe.
 * \param graphe - Le graphe pour lequel on génére des colorations.
 * 
 * \return elle retourne une coloration aléatoire.
 */
color* genererColorationAleatoire(graph_colo graphe);

/**
 * \brief Cette fonction vérifie si il n'y a pas de conflict de coloration au niveau d'un noeud donné.
 * \param graphe - Le graphe à vérifier.
 * \param tableauCouleur - Le tableau des couleurs qu'on veut utiliser sur le graphe.
 * \param noeudModifie - Le noeud qui vient d'être modifié.
 * 
 * \return 1 Si il trouve un conflict.
 * \return 0 Si il ne trouve aucun conflict.
 */
int creeConflit(graph_colo graphe, color* tableauCouleur, node noeudModifie);

/**
 * \brief Cette fonction vérifie si il n'y a pas de conflict de coloration dans tout le graphe.
 * \param graphe - Le graphe à vérifier.
 * \param tableauCouleur - Le tableau des couleurs qu'on veut utiliser sur le graphe.
 * 
 * \return 1 Si il trouve un conflict.
 * \return 0 Si il ne trouve aucun conflict.
 */
int contientConflit(graph_colo graphe, color* tableauCouleur);

/**
 * \brief Cette fonction change aléatoirement la couleur d'un noeud aléatoire
 * \param coloration - coloration à muter
 * \param taille - taille de la coloration
 * 
 * \return rien
 */
void muterColoration(color* coloration, int taille);

/**
 * \brief Cette fonction compte le nombre de couleurs distinctes.
 * \param coloration - la coloration dont on veut compter le nombre de couleurs distinctes
 * \param taille - taille de la coloration
 * 
 * \return int: le nombre de couleurs
 */
int nombreCouleurs(color* coloration, int taille);

/**
 * \brief Cette fonction trouve la coloration ayant le moins de couleurs distinctes
 * \param population - population de coloration
 * \param taillePopulation - nombre de coloration dans la population
 * \param tailleColoration - taille de toutes les colorations dans la population
 * 
 * \return l'index de la pire coloration
 */
int pireColoration(color** population, int taillePopulation, int tailleColoration);

/**
 * \brief Cette fonction trouve la coloration ayant le plus de couleurs distinctes
 * \param population - population de coloration
 * \param taillePopulation - nombre de coloration dans la population
 * \param tailleColoration - taille de toutes les colorations dans la population
 * 
 * \return l'index de la meilleure coloration
 */
int meilleureColoration(color** population, int taillePopulation, int tailleColoration);

/**
 * \brief Cette fonction sélectionne la meilleure moitié de colorations parmi une population
 * \param colorations - population de colorations
 * \param taillePopulation - taille de colorations
 * \param graphe - graphe sur lequel on travaille
 * 
 * \return la meilleure moitié de colorations parmi la population
 */
color** selectionnerColorations(color** colorations, int taillePopulation, graph_colo graphe);

/**
 * \brief Cette fonction produit un enfant à l'aide de deux parents.
 * \param parent1 - Le premier parent
 * \param parent2 - Le deuxième parent
 * \param taille - la taille des parents
 * 
 * \return l'enfant
 */
color* faireEnfant(color* parent1, color* parent2, int taille);

/**
 * \brief Cette fonction crée des couples de parents aléatoires et bigame.
 * \param population - tous les parents
 * \param taillePopulation - tailles de tous les parents
 * \param tailleColoration - tailles de chaque parent individuel
 * 
 * \return les enfants des couples bigames.
 */
color** croiserColorations(color** population, int taillePopulation, int tailleColoration);

/**
 * \brief Cette fonction exécute une coloration génétique sur le graphe.
 * \param graphe - le graphe à colorer
 * \param iterations - le nombre de génération
 * \param taillePopulation - taille de population initial
 * 
 * \return rien
 */
void colorationGenetique(graph_colo graphe, int iterations, int taillePopulation);

#endif