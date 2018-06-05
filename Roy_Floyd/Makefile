CC=gcc

# -c = compilation
# -Wall = throws all warnings
CFLAGS=-c -Wall

all: Floyd
# -c = compilation
# -Wall = throws all warnings
Floyd: main.o generate.o roy_floyd.o print.o
	$(CC) main.o generate.o roy_floyd.o print.o -o Floyd

main.o: main.c
	$(CC) $(CFLAGS) main.c

generate.o: generate.c
	$(CC) $(CFLAGS) generate.c

roy_floyd.o: roy_floyd.c
	$(CC) $(CFLAGS) roy_floyd.c

print.o: print.c
	$(CC) $(CFLAGS) print.c


