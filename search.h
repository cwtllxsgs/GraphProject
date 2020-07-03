#ifndef _SEARCH_H
#define _SEARCH_H
#include "stats.h"


typedef struct {
	int data;
	int parent;
}GARLIC;

int* DFS(AdjGraph* G, int u, int v);
int* BFS(AdjGraph* G, int u, int v);
int* Dijkstra(AdjGraph* G, int u, int v);
void Dispath(int dist[], int path[], int S[], int u, int v);
char* shortestPath(int u, int v, char algorithm[], char name[]);

#endif

