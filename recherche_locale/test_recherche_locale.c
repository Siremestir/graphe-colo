#include "recherche_locale.h"

int main()
{
    graph graphe = readGraph("../graphes/inithx.i.2.col");
    graph_colo graphe_colo = createGraphColo(graphe->size);
    graphe_colo->g = graphe;
    colorationRechercheLocale(graphe_colo);
    writePumlColo("test_recherche_locale.puml", graphe_colo);


    // Compter les couleurs
    int nbCouleurs = 0;
    // Compte
    for(int i = 0; i<graphe->size; i++)
    {
        int j=0;
        for (j; j<i; j++)
        {
            if (graphe_colo->colors[i] == graphe_colo->colors[j])
            {
                break;
            }
        }
        if (i == j)
        {
            nbCouleurs++;
        }
        
    }

    color maxColor = getMaxColor(graphe_colo);
    printf("Nb couleurs : %i\n", nbCouleurs);
    return 1;
}