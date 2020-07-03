#include <stdio.h>
#include <stdlib.h>
#include "stats.h"


AdjGraph g;
int u,v,w,m,n;

void CreateAdj(char name[]){
	FILE* fp;
	ArcNode* p;
	fp = fopen(name, "r");
	if (fp == NULL) {
		printf("\nwhere is your file,bro?\n");
		exit(0);
	}
	while (fscanf(fp, "%d%d%d", &u, &v, &w) != EOF) {
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = v;
		p->weight = w;
		p->nextarc = g.adjlist[u].firstarc;
		g.adjlist[u].firstarc = p;
	}
	fclose(fp);
}

void DispAdj(){
	int i;
	ArcNode* p;
	for (i = 0; i < g.n; i++) {
		p = g.adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p != NULL)
		{
			printf("%3d[%d]¡ú", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("¡Ä\n");
	}
}

int numberOfEdges(char name[]) {
	FILE* fp;
	fp = fopen(name, "r");
	if (fp == NULL) {
		printf("\nwhere is your file,bro?\n");
		exit(0);
	}
	while (fscanf(fp, "%d%d%d", &u, &v, &w) != EOF) {
		g.e++;
	}
	fclose(fp);
	return g.e;
} 

int numberOfVertices(char name[]) {
	FILE* fp;
	int *toexplore;
	toexplore=(int *)malloc(MAXV*sizeof(int));
	int i;
	fp = fopen(name, "r");
	if (fp == NULL) {
		printf("\nwhere is your file,bro?\n");
		exit(0);
	}
	while (fscanf(fp, "%d%d%d", &u, &v, &w) != EOF) {
		toexplore[u]=1;
		toexplore[v]=1;
	}	
	for (i = 0; i < MAXV; i++) {
		if (toexplore[i])
			g.n++;
	}
	fclose(fp);
	return g.n;
}


