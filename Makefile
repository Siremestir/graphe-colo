main: main.o graph.o parser.o graph_colo.o
	gcc -o main main.o graph.o parser.o graph_colo.o

graph.o: graph/graph.c
	gcc -c graph/graph.c

parser.o: parser/parser.c
	gcc -c parser/parser.c

graph_colo.o: graph_colo/graph_colo.c
	gcc -c graph_colo/graph_colo.c

clean:
	rm main
	rm *.o