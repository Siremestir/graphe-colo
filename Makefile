main: main.o graph.o greedy.o graph_colo.o
	gcc -o main main.o graph.o greedy.o graph_colo.o

graph.o: graph/graph.c
	gcc -c graph/graph.c

greedy.o: greedy/greedy.c
	gcc -c greedy/greedy.c

graph_colo.o: graph_colo/graph_colo.c
	gcc -c graph_colo/graph_colo.c

clean:
	rm main
	rm *.o