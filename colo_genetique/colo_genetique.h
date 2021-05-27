#ifndef COLO_GENETIQUE_H
#define COLO_GENETIQUE_H

#include "../graph_colo/graph_colo.h"

#include <time.h>

color** genererPopulationAleatoire(int taille, graph_colo graphe);

color* genererColorationAleatoire(graph_colo graphe);

int creeConflit(graph_colo graphe, color* tableauCouleur, node noeudModifie);

int contientConflit(graph_colo graphe, color* tableauCouleur);

void muterColoration(color* coloration, int taille);

int nombreCouleurs(color* coloration, int taille);

int pireColoration(color** population, int taillePopulation, int tailleColoration);

int meilleureColoration(color** population, int taillePopulation, int tailleColoration);

color** selectionnerColorations(color** colorations, int taillePopulation, graph_colo graphe);

color* faireEnfant(color* parent1, color* parent2, int taille);

color** croiserColorations(color** population, int taillePopulation, int tailleColoration);

void colorationGenetique(graph_colo graphe, int iterations, int taillePopulation);

#endif