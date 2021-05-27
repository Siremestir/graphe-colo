#include "../parser/parser.h"
#include "greedy.h"

int main()
{
    graph graphe = readGraph("../graphes/inithx.i.2.col");
    graph_colo graphe_colo = createGraphColo(graphe->size);
    graphe_colo->g = graphe;
    colorerGraphGreedy(graphe_colo);
    writePumlColo("test_greedy.puml", graphe_colo);
    color maxColor = getMaxColor(graphe_colo);
    printf("Nb couleurs : %i\n", maxColor);
    return 1;
}