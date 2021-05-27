#include "colo_genetique.h"

int main()
{
    graph_colo graphe = genererGrapheAleatoire(5);
    printGraphColo(graphe);
    return 1;
}