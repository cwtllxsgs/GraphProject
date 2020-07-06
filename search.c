#include <stdio.h>
#include <stdlib.h> 
#include "stats.h"
#include "search.h"
#include "cmp.h"

extern AdjGraph g;
int path[MAXV];
int d; 
int visited[MAXV];
int dist[MAXV];
int ss[MAXV];
int A[MAXV];
int Mindis;
int apath[MAXV];
//actually..
void* DFS(AdjGraph *G, int u, int v, int visited[], int path[], int d)  //������ȱ��� 
{
	int w,i;
	ArcNode *p;
	visited[u] = 1;
	d++;
	path[d] = u;
	if(u == v) {
		printf("%d", path[0]);
		for(i = 1; i <=d; i++) {
			if(visited[path[i]] == 1)
				printf("->%d", path[i]);
		}
		return;
	}
	p = G->adjlist[u].firstarc;
	if(p == NULL && u != v) {
		visited[u] = 2;
	} 
	while(p!=NULL) {
		w = p->adjvex;
		if(visited[w] == 0)
			DFS(G,w,v,visited,path,d);
		p = p->nextarc;
		if(p == NULL && u != v)
			visited[u] = 2;
	}
}

//BFS  参考数据结构教程第5版P276,277 
int* BFS(AdjGraph* G, int u, int v) {
	ArcNode *p;
	int w, i, n;
	int step = 0;
	GARLIC qu[MAXV];
	int front = -1, rear = -1;
	
	for (i = 0; i < G->n; i++) {
		visited[i] = 0;
	}
	rear++;
	qu[rear].data =u;
	qu[rear].parent = -1;
	visited[u] = 1;
	while (front != rear) {
		front++;
		w = qu[front].data;
		if (w == v) {
			i = front;
			while (qu[i].parent != -1 ) {
				step++;
				i = qu[i].parent;
			}
			n = step;
			i = front;
			while (qu[i].parent != -1) {
				path[step] = qu[i].data;
				i = qu[i].parent;
				step--;
			}
			path[0] = u;
			break;
		}
		p=G->adjlist[w].firstarc;
		while (p != NULL) {
			if (visited[p->adjvex] == 0) {
				visited[p->adjvex] == 1;
				rear++;
				qu[rear].data = p->adjvex;
				qu[rear].parent =front;
			}
			p = p->nextarc;
		} 
		
	}
    printf("%d -> ", u);
	for (int j = 1; j <= n; j++) {
	    printf("%d -> ", path[j]);
		}
	printf("NULL\n");
}


//Dijkatra  参考数据结构第5版P294,295 
int* Dijkstra(AdjGraph* G, int u, int v){
    memset(path, -1, sizeof(int) * G->n );
    ArcNode* s;
    G->adjlist[u].dis = 0;
    s = G->adjlist[u].firstarc;
    while (s != NULL) {
		int v = s->adjvex;
		path[v] = u;
		G->adjlist[v].dis = s->weight;
		s = s->nextarc;
	}
	path[u] = 0;
	int snum = 0;
	int unum = G->n;
	G->adjlist[u].dis = 0;
	for (int i = 0; i < unum; i++) {
		A[i] = i;
	}
	while (snum < G->n) {
		int min = 0x3f3f3f3f;
		int index;
		for (int i = 0; i < unum; i++) {
			int a = A[i];
			if (G->adjlist[a].dis < min && G->adjlist[a].dis != 0) {
				min = G->adjlist[a].dis;
				index = i;
			}
		}
		int b = A[index];
		ss[snum++] = b;
		unum--;
		for (int j = index; j < unum; j++)
		{
			A[j] = A[j + 1];
		}
		ArcNode* s;
		s = G->adjlist[b].firstarc;
		while (s != NULL) {
			if (s->weight + G->adjlist [b].dis < G->adjlist[s->adjvex].dis)
			{
				G->adjlist[s->adjvex].dis = s->weight + G->adjlist [b].dis;
				path[s->adjvex] = b;
			}
			s = s->nextarc;
		}
	}
	for (int i = 0; i < G->n; i++) {
		dist[i] = G->adjlist[i].dis;
	}
	Dispath(dist, path, ss, u, v);
}
    

void Dispath(int dist[], int path[], int S[], int u, int v) {
	int k, d = 0;
	
	apath[d] = v;
	k = path[v];
	while (k != u) {
		d++;
		apath[d] = k;
		k = path[k];
	}
	d++;
	apath[d] = u;
	printf("%d->", apath[d]);
	for (int i = d - 1; i >= 0; i--) {
		printf("%d->", apath[i]);
	}
	printf("NULL\n");
}

//评分函数 应该是这样的没错吧 ---我哪知道啊兄弟？
char* shortestPath(int u, int v, char algorithm[], char name[]) {
	char garlic[3][9] = {"DFS", "BFS", "Dijkstra"} ;
	CreateAdj(name);
     	if(strcmp(algorithm, garlic[0]) == 0) {
     		return DFS(&g, u, v,visited,path,d);
		 }
	    else if (strcmp(algorithm, garlic[1]) == 0) {
		return BFS(&g, u, v);
	}
        else if (strcmp(algorithm, garlic[2]) == 0) {
		return Dijkstra(&g, u, v);
	}
}



