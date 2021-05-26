#include "./greedy/greedy.h"

int main(int argc, char const *argv[])
{
    graph_colo graphe = genererGraphAleatoire(5);
    colorerGraphGreedy(graphe);

    printGraphColo(graphe);

    return 0;
}