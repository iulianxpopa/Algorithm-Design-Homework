CC=gcc

# -c = compilation
# -Wall = throws all warnings
CFLAGS=-c -Wall

all: Dijks
# -c = compilation
# -Wall = throws all warnings
Dijks: main.o generate.o dijkstra.o print.o
	$(CC) main.o generate.o dijkstra.o print.o -o Dijks

main.o: main.c
	$(CC) $(CFLAGS) main.c

generate.o: generate.c
	$(CC) $(CFLAGS) generate.c

dijkstra.o: dijkstra.c
	$(CC) $(CFLAGS) dijkstra.c

print.o: print.c
	$(CC) $(CFLAGS) print.c


