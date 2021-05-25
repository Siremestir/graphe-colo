#include "./parser/parser.h"

int main(int argc, char const *argv[])
{
    graph myGraph = readGraph("./assets/1-FullIns_3.col");

    graph_colo myGraphColo = createGraphColo(myGraph->size);
    myGraphColo->g = myGraph;

    colorColoredGraphWithColoredColors(myGraphColo);

    printGraphColo(myGraphColo);

    writePumlColo("res2.puml", myGraphColo);

    return 0;
}