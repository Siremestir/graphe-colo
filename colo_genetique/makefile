colo_genetique: graph.o colo_genetique.o graph_colo.o parser.o test_colo_genetique.o
	gcc -o colo_genetique graph.o colo_genetique.o graph_colo.o parser.o test_colo_genetique.o

graph.o: ../graph/graph.c
	gcc -c ../graph/graph.c

colo_genetique.o: colo_genetique.c
	gcc -c colo_genetique.c

graph_colo.o: ../graph_colo/graph_colo.c
	gcc -c ../graph_colo/graph_colo.c

parser.o: ../parser/parser.c
	gcc -c ../parser/parser.c

test_colo_genetique.o: test_colo_genetique.c
	gcc -c test_colo_genetique.c

clean:
	rm colo_genetique
	rm *.o