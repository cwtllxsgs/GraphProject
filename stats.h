#ifndef _STATS_H
#define _STATS_H

#define MAXV 666666
#define INF  32767

//参考上学期数据结构的教材对邻接表和图声明
typedef int InfoType;
typedef struct ANode {
	int adjvex;	
	struct ANode* nextarc;
	int weight;
} ArcNode;
typedef struct Vnode {
	InfoType info;
	int count;
	int dis;
	ArcNode* firstarc;
} VNode;
typedef struct {
	VNode adjlist[MAXV];
	int n, e;
} AdjGraph;	

void CreateAdj(char name[]);
int numberOfEdges(char name[]);
int numberOfVertices(char name[]);
double freemanNetworkCentrality(char name[]);

#endif

	
