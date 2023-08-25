#include <stdio.h>
#include<stdlib.h>

#define MAX 5 
#define INF 200

typedef int Matrix[MAX][MAX];
typedef int Vertex;
typedef Vertex Set[MAX];

int* Dijkstra(Matrix * M, Vertex v);
void main(){
    Matrix graph = {
        {INF, 10, INF, 30, 100},
        {INF, INF, 50, INF, INF},
        {20, INF, INF, INF, 10},
        {INF, INF, 20, INF, 60},
        {INF, INF, INF, INF, INF}
    };
    int* SPF = Dijkstra(graph, 1);
    displayDijkstra(SPF);
}

int* Dijkstra(Matrix* M, Vertex v){
    int* path = malloc(sizeof(int)*MAX);
    int cost[MAX];
    int visited[MAX] = {0,0,0,0,0}; // init visited vertices
    int x, y, minCost, minV, Scount = 0;
    path[0] = v; //set the first path to be the source vertex
    for (x = 0; x < MAX; x++){ //Copy first the initial Distances from Vertex v to nodes 0, 1 ... MAX
        cost[x] = (*M)[v][x];
    }
    cost[v] = 0; //set the source node's cost to 0
    minCost = INF; //REQUIRED for the next loop to avoid uninitialized errors
    minV = -1; //REQUIRED for the next loop to avoid uninitialized errors

    while(Scount < MAX){ //loop untill all the possible vertices are evaluated
            for (x = 0; x < MAX; x++){  ///loops untill all the unvisited vertices' costs are evaluated
                if (visited[x] != 1 && cost[x] < minCost){//gets the minimum Cost Vertex from the Unvisited Nodes
                    minCost = cost[x]; //used to take note of the minimum cost 
                    minV = x; //get the minimum Vertex
                    }
            }
                path[Scount++] = minV;//add the vertex to the path
                visited[minV] = 1; // V-S -> u set the newly added vertext to the visited nodes not to visit it again

            if (minV != -1){//check if there is a path
                for (x = 0; x < MAX; x++){ //Relaxation / Updates the SPF if there is any from the minV
                if ((*M)[minV][x] + cost[minV] < cost[x]){//if there is a shorter path through a vertex, then update the cost
                    cost[x] = (*M)[minV][x] + cost[minV];
                }
            }
            }
        minCost = INF; //reset the minCost
        minV = -1;//reset the minimum Vertex for the next loop
    }

    printf("Cost: \n");
    for (x = 0 ; x < MAX; x++){
        printf("Vertex [%d] : %d\n", x, cost[x]);
    }
    printf("\n");
    return path;
    
}

void displayDijkstra(int *path){
    int x;
    printf("Path of Dijkstra: \n");
    for (x = 0; x < MAX; x++){
        printf("%d ", path[x]);
    }
    printf("\n");
}