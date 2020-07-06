#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int toexplore[MAXV];
AdjGraph g;
int u,v,w,degree;
//refer to 数据结构教程（上学期教材）邻接表构造方式
void CreateAdj(char name[]){
	FILE* fp;
	ArcNode* p;
    int i;
	fp = fopen(name, "r");
	if (fp == NULL) {
		printf("\nwhere is your file,bro?\n");
		exit(0);
	}
	while (fscanf(fp, "%d%d%d", &u, &v, &w) != EOF) {
		g.adjlist[u].count++;
		g.e++;
		toexplore[u] = 1;
		toexplore[v] = 1;
		degree = g.adjlist[u].count > degree ? g.adjlist[u].count : degree;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = v;
		p->weight = w;
		p->nextarc = g.adjlist[u].firstarc;
		g.adjlist[u].firstarc = p;
		g.adjlist[u].dis = 0x3f3f3f3f;
	}
	for (i = 0; i < MAXV; i++) {
		if (toexplore[i])
			g.n++;
		}
	fclose(fp);
}


int numberOfEdges(char name[]) {
    CreateAdj(name); 
	return g.e;
} 

int numberOfVertices(char name[]) {
	CreateAdj(name); 
	return g.n;
}

double freemanNetworkCentrality(char name[]) {
	CreateAdj(name); 
	long long  sumfreeman = 0;
	double freeman;
	for (int i = 0; i < g.n; i++) {
		sumfreeman += (degree - g.adjlist[i].count);
	}
	freeman = (double)(sumfreeman); 
	freeman = (freeman / ((g.n - 1) * (g.n- 2)));
	return freeman;
}
