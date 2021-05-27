greedy: graph.o greedy.o graph_colo.o parser.o test_greedy.o
	gcc -o greedy graph.o greedy.o graph_colo.o parser.o test_greedy.o

graph.o: ../graph/graph.c
	gcc -c ../graph/graph.c

greedy.o: greedy.c
	gcc -c greedy.c

graph_colo.o: ../graph_colo/graph_colo.c
	gcc -c ../graph_colo/graph_colo.c

parser.o: ../parser/parser.c
	gcc -c ../parser/parser.c

test_greedy.o: test_greedy.c
	gcc -c test_greedy.c

clean:
	rm greedy
	rm *.o