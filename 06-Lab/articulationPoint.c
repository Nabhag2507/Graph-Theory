#include <stdio.h>
#include <time.h>

void dfsRec(int node, int size, int node_to_remove, int adjMat[size][size], int visited[]){
    visited[node] = 1;

    int *tempAdjList = adjMat[node];
    for(int i = 0; i < size; i++){
        if(visited[i] == 0 && tempAdjList[i] == 1 && i != node_to_remove){
            dfsRec(i, size, node_to_remove, adjMat, visited);
        }
    }
}

void print_points(int vertex, int adjMat[vertex][vertex], int visited[]){
    for(int i = 0; i < vertex; i++){
        for(int k = 0; k < vertex; k++){
            visited[k] = 0;
        }
        /*
        int start = 0;
        if(i == start){
            start = 1;
        }
         */
        int node_to_remove = i;
        int node_start = 0;
        for(int j = 0; j < vertex; j++){
            if(j != node_to_remove){
                node_start = j;
                break;
            }
        }

        dfsRec(node_start, vertex, node_to_remove, adjMat, visited);

        for(int i = 0; i < vertex; i++){
            if(visited[i] == 0 && i != node_to_remove){
                printf("%d ", node_to_remove);
                break;
            }
        }
    }
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int vertex = 6;
    int adjMat[][6] = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };

//     int adjMat[][5] = {
//     {0, 1, 1, 0, 0},
//     {1, 0, 1, 0, 0},
//     {1, 1, 0, 1, 0},
//     {0, 0, 1, 0, 1},
//     {0, 0, 0, 1, 0}
// };

    int visited[6] = {0};

    print_points(vertex, adjMat, visited);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}