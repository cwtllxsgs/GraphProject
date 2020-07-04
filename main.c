#include <stdio.h>
#include <stdlib.h>
#include "stats.h"
#include "stats.c"
#include "search.c"
#include "search.h" 
#include "cmp.h"
#include "cmp.c"

extern AdjGraph g;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("\nxd your argc is dying\n\n");
		return 0;
	}
	if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		printf("\ninput -g/--graph FILE_PATH -s/--stats STATS_PARAMS \n for details of the map!\n");
		printf("\nhow can you be quicker?\n -g/--graph FILE_PATH -sp/--shortestpath SEARCH_PARAMS -u STARTING_POINT -v TARGET_POINT\n");
		printf("\n input -j\n memorize the image of the garlic!!!\n");
	}
	if (strcmp(argv[1], "-j") == 0) {
		printf("             o			            \n");
		printf("            oOo			            \n");
		printf("        o  o   o  o		            \n");
		printf("     o o  o     o   o o	           \n");
		printf("    o o  o       o   o o             \n");
		printf("  o o   o --- --- o    o o           \n");
		printf("   o o   o 0   0 o    o o             \n");
		printf("   o o   o   W   o    o o               \n");
		printf("    o o  o       o   o o                  \n");
		printf("     o o  o     o   o o	            \n");
		printf("           |uuu|		             \n");
		printf("       ---------------                 \n");
		printf("       |             |               \n");
		printf("       | garlic head |               \n");
		printf("       |_____________|              \n");
		printf("          |      |                 \n");		
	
	}
	if (strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--graph") == 0) {
		if (strcmp(argv[3], "-s") == 0 || strcmp(argv[3], "--stats") == 0) {
			if (strcmp(argv[4], "edges") == 0) {
				printf("%d\n", numberOfEdges(argv[2]));
			}
			else if (strcmp(argv[4], "vertices") == 0) {
				printf("%d\n", numberOfVertices(argv[2]));
			}
			else if (strcmp(argv[4], "freeman") == 0) {
				printf("%lf\n", freemanNetworkCentrality(argv[2]));
			}
		}
		else if (strcmp(argv[3], "-sp") == 0 || strcmp(argv[3], "--shortestpath") == 0) {
			char choice[3][15] = { "DFS","BFS","Dijkstra" };
			CreateAdj(argv[2]);
			int start = atoi(argv[6]);
			int end = atoi(argv[8]);
			if (strcmp(argv[4], choice[0]) == 0) {
				if (strcmp(argv[5], "-u") == 0 && strcmp(argv[7], "-v") == 0) {
		            DFS(&g,start,end);
		            } 
		        }
		    else if (strcmp(argv[4], choice[1]) == 0) {
				if (strcmp(argv[5], "-u") == 0 && strcmp(argv[7], "-v") == 0) {
		            BFS(&g,start,end);
		            } 
		        }
			else if (strcmp(argv[4], choice[2]) == 0) {
				if (strcmp(argv[5], "-u") == 0 && strcmp(argv[7], "-v") == 0) {
					Dijkstra(&g,start,end);
				}
			}
		} 	
	
		} 	
 
	return 0;
	
}

