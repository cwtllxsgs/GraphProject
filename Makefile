cc = gcc
CFLAGS = -g -Wall
MAIN = main.o cmp.o search.o stats.o

search-cli: main.o
	cc -o search-cli main.o
cmp.o: cmp.c cmp.h
	cc -c -o cmp.o cmp.c
search.o: search.c search.h cmp.h
	cc -c -o search.o search.c cmp.c
stats.o: stats.c stats.h
	cc -c -o stats.o stats.c
main.o: main.c search.h stats.h cmp.h
	cc -c main.c cmp.c search.c stats.c
.PHONY:clean
clean:
	rm -rf stats.o cmp.o search.o main.o search-cli
