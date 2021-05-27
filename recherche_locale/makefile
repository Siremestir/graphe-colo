recherche_locale: graph.o recherche_locale.o graph_colo.o parser.o test_recherche_locale.o
	gcc -o recherche_locale graph.o recherche_locale.o graph_colo.o parser.o test_recherche_locale.o

graph.o: ../graph/graph.c
	gcc -c ../graph/graph.c

recherche_locale.o: recherche_locale.c
	gcc -c recherche_locale.c

graph_colo.o: ../graph_colo/graph_colo.c
	gcc -c ../graph_colo/graph_colo.c

parser.o: ../parser/parser.c
	gcc -c ../parser/parser.c

test_recherche_locale.o: test_recherche_locale.c
	gcc -c test_recherche_locale.c

clean:
	rm recherche_locale
	rm *.o