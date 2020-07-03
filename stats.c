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

double freemanNetworkCentrality(char name[]) {
	FILE* fp;
	int degree;
	fp = fopen(name, "r");
	if (fp == NULL) {
		printf("\nwhere is your file,bro?\n");
		exit(0);
	}
	while (fscanf(fp, "%d%d%d", &u, &v, &w) != EOF) {
		g.adjlist[u].count++;
		degree = g.adjlist[u].count > degree ? g.adjlist[u].count : degree;
	}
	long long  sumfreeman = 0;
	double freeman;
	for (int i = 0; i < numberOfVertices(name); i++) {
		sumfreeman += (degree - g.adjlist[i].count);
	}
	freeman = (double)(sumfreeman); 
	freeman = (freeman / ((numberOfVertices(name) - 1) * (numberOfVertices(name) - 2)));
	return freeman;
}
