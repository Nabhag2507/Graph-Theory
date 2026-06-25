#include <stdio.h>
#include <time.h>

// input: adj[][] = [[1,2], [0,2], [0,1,3,4], [2], [2]] 
// Output: [0, 1, 2, 3, 4] 

void dfsRec(int node, int size, int adjMat[size][size], int visited[]){
    printf("%d ", node);
    visited[node] = 1;

    int *tempAdjList = adjMat[node];
    for(int i = 0; i < size; i++){
        if(visited[i] == 0 && tempAdjList[i] == 1){
            dfsRec(i, size, adjMat, visited);
        }
    }
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    // int vertex = 5;
    // int adjMat[5][5] = {
    //     {0, 1, 1, 0, 0},
    //     {1, 0, 1, 0, 0},
    //     {1, 1, 0, 1, 1},
    //     {0, 0, 1, 0, 0},
    //     {0, 0, 1, 0, 0}
    // };

    // int n = 5, m = 5;

    // int visited[] = {0, 0, 0, 0, 0};

    // dfsRec(0, 5, adjMat, visited);

    int vertex;
    printf("Enter number of vertex in your graph: ");
    scanf("%d",&vertex);

    printf("Enter elementes of your adjacency matrix.\n");
    int adjMat[vertex][vertex];

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            printf("Enter element for index, %d, %d : ", i, j);
            scanf("%d",&adjMat[i][j]);
        }
    }

    int visited[vertex];
    for(int i = 0; i < vertex; i++){
        visited[i] = 0;
    }

    int startNode;
    printf("Enter your starting node : ");
    scanf("%d",&startNode);

    dfsRec(startNode, vertex, adjMat, visited);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}