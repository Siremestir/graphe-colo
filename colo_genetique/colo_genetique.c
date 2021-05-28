#include "colo_genetique.h"

/*void genererAretesAleatoires(graph_colo graphe, node s)
{
    srand(time(NULL));
    for (node i = 1; i <= graphe->g->size; i++)
    {
        if (i != s && !edgeExists(graphe->g, i, s))
        {
            if (rand()%2)
            {
                newEdgeColo(graphe, s, i);
            }
        }
    }
}*/

int creeConflit(graph_colo graphe, color *tableauCouleur, node noeudModifie)
{
    return isNeighborColoredWithColoredColor(graphe, noeudModifie, tableauCouleur[noeudModifie - 1]);
}

int contientConflit(graph_colo graphe, color *tableauCouleur)
{
    for (node s = 1; s <= graphe->g->size; s++)
    {
        if (creeConflit(graphe, tableauCouleur, s))
        {
            return 1;
        }
    }
    return 0;
}

color *genererColorationAleatoire(graph_colo graphe)
{
    //srand(time(NULL));
    color *coloration = (color *)malloc(sizeof(color) * graphe->g->size);
    for (int i = 0; i < graphe->g->size; i++)
    {
        coloration[i] = rand() % graphe->g->size;
    }
    return coloration;
}

color **genererPopulationAleatoire(int taille, graph_colo graphe)
{
    srand(time(NULL));
    color **population = (color **)malloc(sizeof(color) * taille * graphe->g->size);
    for (int i = 0; i < taille; i++)
    {
        population[i] = genererColorationAleatoire(graphe);
    }
    return population;
}

int nombreCouleurs(color *coloration, int taille)
{
    if (coloration == NULL)
    {
        fprintf(stderr, "ERROR: nombreCouleurs appelé sur coloration nulle\n");
        exit(-1);
    }

    //printf("coloration : %li\n", coloration);
    int cpt = 0;
    for (int i = 0; i < taille; i++)
    {
        int j = 0;
        for (j; j < i; j++)
        {
            /*
            if (coloration[i] == coloration[j])
            {
                break;
            }*/
        }
        if (i == j)
        {
            cpt++;
        }
    }
    return cpt;
}

void muterColoration(color *coloration, int taille)
{
    node s = (rand() % taille) + 1;
    coloration[s-1] = rand() % (nombreCouleurs(coloration, taille)-1) + 1;
}

void muterPopulation(color **population, int taillePopulation, int tailleColoration)
{
    for (int i = 0; i < taillePopulation; i++)
    {
        muterColoration(population[i], tailleColoration);
    }
}

int pireColoration(color **population, int taillePopulation, int tailleColoration)
{
    int index = 0;
    int nbCouleurs = 0;
    for (int i = 0; i < taillePopulation; i++)
    {
        if (population[i] != NULL)
        {
            if (nbCouleurs < nombreCouleurs(population[i], tailleColoration))
            {
                index = i;
                nbCouleurs = nombreCouleurs(population[i], tailleColoration);
            }
        }
    }
    return index;
}

int meilleureColoration(color **population, int taillePopulation, int tailleColoration)
{
    int index = 0;
    int nbCouleurs = tailleColoration;
    for (int i = 0; i < taillePopulation; i++)
    {
        if (population[i] != NULL)
        {
            if (nbCouleurs > nombreCouleurs(population[i], tailleColoration))
            {
                index = i;
                nbCouleurs = nombreCouleurs(population[i], tailleColoration);
            }
        }
    }
    return index;
}

color **selectionnerColorations(color **colorations, int taillePopulation, graph_colo graphe)
{
    //TODO: réduire de moitié colorations
    // D'abord jeter les colorations non-viables
    // Ensuite si il reste des colorations à éjecter, les colorations les plus lourdes
    int moitieTaille = (int)taillePopulation / 2;
    color **res = (color **)malloc(sizeof(colorations[0]) * moitieTaille);
    color *coloViables[taillePopulation];

    // Initialisation res
    for (int i = 0; i < moitieTaille; i++)
    {
        res[i] = NULL;
    }

    // Sélectionner toutes les colorations viables
    for (int i = 0; i < taillePopulation; i++)
    {
        // On s'assure que res n'est pas plein
        if (res[moitieTaille - 1] != NULL)
        {
            if (!contientConflit(graphe, colorations[i]))
            {
                coloViables[i] = colorations[i];
            }
            else
            {
                coloViables[i] = NULL;
            }
        }
    }

    // Compter les colorations viables
    int cpt = 0;
    for (int i = 0; i < taillePopulation; i++)
    {
        cpt += coloViables[i] != NULL;
    }

    // 3 cas possibles

    int index;
    if (cpt < moitieTaille)
    {
        index = moitieTaille - cpt;
        // On sélectionne les premières colos non-viables qui viennent
        for (int i = 0; i < index; i++)
        {
            for (int j = 0; j < taillePopulation; j++)
            {
                if (contientConflit(graphe, colorations[j]))
                {
                    res[i] = colorations[j];
                    break;
                }
            }
        }
    }
    else if (cpt > moitieTaille)
    {
        int aEnlever = cpt - moitieTaille;
        for (int i = 0; i < aEnlever; i++)
        {
            int indexPireColo = pireColoration(coloViables, taillePopulation, graphe->g->size);
            coloViables[indexPireColo] = NULL;
        }

        index = 0;
    }
    else
    {
        index = 0;
    }

    for (int i = 0; i < taillePopulation; i++)
    {
        if (coloViables[i] != NULL)
        {
            res[index] = coloViables[i];
            index++;
        }
    }

    return res;
}

color *faireEnfant(color *parent1, color *parent2, int taille)
{
    srand(time(NULL));
    color *enfant = (color *)malloc(sizeof(parent1));
    for (int i = 0; i < taille; i++)
    {
        enfant[i] = rand() % 2 ? parent1[i] : parent2[i];
    }
    return enfant;
}

color **croiserColorations(color **population, int taillePopulation, int tailleColoration)
{
    srand(time(NULL));
    int distance = rand() % taillePopulation;
    color **res = (color **)malloc(sizeof(population) * 2);
    for (int i = 0; i < taillePopulation; i++)
    {
        res[i] = faireEnfant(population[i], population[(i + distance) % taillePopulation], tailleColoration);
    }
    return res;
}

void colorationGenetique(graph_colo graphe, int iterations, int taillePopulation)
{
    color **population = genererPopulationAleatoire(taillePopulation, graphe);
    //muterPopulation(population, taillePopulation, graphe->g->size);
    int tailleMoitie = (int)taillePopulation/2;
    int taillePopIteree = tailleMoitie*2;
    color** moitiePopulation = selectionnerColorations(population, taillePopulation, graphe);
    //color** populationIteree = croiserColorations(moitiePopulation, tailleMoitie, graphe->g->size);
    for (int i = 0; i < taillePopulation; i++)
    {
        printf("%i \ncoloration : %i \n", i, population[i][0]);

        printf("coloration : %i \n", population[i][taillePopulation-1]);
    }
    for (int i = 1; i < iterations; i++)
    {
        //muterPopulation(populationIteree, taillePopIteree, graphe->g->size);
        //populationIteree = croiserColorations(moitiePopulation, tailleMoitie, graphe->g->size);
    }
    //graphe->colors = populationIteree[meilleureColoration(populationIteree, taillePopIteree, graphe->g->size)];
}