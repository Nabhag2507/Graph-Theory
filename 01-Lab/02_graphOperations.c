#include <stdio.h>
#include <stdlib.h>

void main () {
    int vertex;
    printf("Enter number of vertex : ");
    scanf("%d", &vertex);

    int edge;
    printf("Enter number of edges : ");
    scanf("%d", &edge);

    int edgeMatrix[edge][2];
    for(int i = 0; i < edge; i++){
        for(int j = 0; j < 2; j++){
            printf("Enter element no %d, %d: ", i, j);
            scanf("%d", &edgeMatrix[i][j]);
        }
    }

    // creating adjacency metrix 
    int adjacencyMatrix[vertex][vertex];
    for(int i = 0; i < edge; i++){
        adjacencyMatrix[edgeMatrix[i][0]][edgeMatrix[i][1]] = 1;
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if(adjacencyMatrix[i][j] == 1){
                continue;
            } else {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}