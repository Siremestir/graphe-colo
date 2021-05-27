#include "colo_genetique.h"
#include "../parser/parser.h"

int main()
{
    graph graphe = readGraph("../graphes/inithx.i.2.col");
    graph_colo graphe_colo = createGraphColo(graphe->size);
    graphe_colo->g = graphe;
    colorationGenetique(graphe_colo, 30, 100);
    /*writePumlColo("test_colo_genetique.puml", graphe_colo);
    
    printf("Nb couleurs : %i\n", nombreCouleurs(graphe_colo->colors, graphe_colo->g->size));*/
    return 1;
}