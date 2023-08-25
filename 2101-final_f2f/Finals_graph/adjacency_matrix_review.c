#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTINEL 999
#define MAX_VERTEX 10
#define ARRAY_SIZE 0xF

/* Data Structure Definition */
typedef int adjMatrix[MAX_VERTEX][MAX_VERTEX];
    
    typedef struct {
        int u,v;
        int weight;
    }edgetype;

    typedef struct{
        edgetype edges[ARRAY_SIZE];
        int count; /* actual # of edges in the array */
    }edgelist;


/* Function Specification: Function createEdgeList() creates and returns
a list of edges arranged in ascending order according to weights, given a labeled
adjacency matrix M of an undirected graph. Assume that in the adjacency matrix,
a sentinel value represents no edge which includes the diagonal of the Matrix.
Also note that in a undirected graph the edge (u,v) = (v,u) */

edgelist createEdgeList(adjMatrix M) //Blank 1
{
    int x, y, pos;
    edgelist E = {0};        //Blank 2   // Declares and initializes the edge list E to be empty 
                                              // Note: for the array, just initialize one component
    for(x = 0; x < MAX_VERTEX; x++){
        for(y = x+1; y<MAX_VERTEX; y++){     //Blank 3 and 4  Reminder: (u,v) == (v,u)
            if (M[x][y]!=SENTINEL){                    //Blank 5     // Edge is found
      
                /* finds the proper position of the edge in the list */ 
                for(pos = 0; pos < E.count && E.edges[pos].weight<M[x][y]; pos++){}  //Blank 6 and 7                  
       
                /* Shifts succeeding elements to make room for the new edge */
                memcpy(&E.edges[pos+1], &E.edges[pos], (E.count-pos)*sizeof(edgetype));   //Blank 8,9,10 

                /* Insertion Proper */
                edgelist edge = {x,y,M[x][y]};         //Blank 11 declares and initialize edge to contain
                                                 //the edge data to be inserted in the list
                //E.edges[pos]=edge;        //Blank 12 inserts the edge in the list
                E.count++;          
            }
        }
    }
    return E;
}

int main(){

}