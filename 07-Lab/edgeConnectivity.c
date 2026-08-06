#include <stdio.h>
#include <time.h>

void dfs(int node, int vertex, int adjMat[vertex][vertex], int visited[]){
    visited[node] = 1;

    int* tempAdjList = adjMat[node];
    for(int i = 0; i < vertex; i++){
        if(tempAdjList[i] == 1 && visited[i] == 0){
            dfs(i, vertex, adjMat, visited);
        }
    }
}

int isConnected(int adjMat[4][4]){
    int visited[4] = {0};
    dfs(0, 4, adjMat, visited);

    for(int i = 0; i < 4; i++){
        if(visited[i] == 0){
            return 0;
        }
    }
    return 1;
}

void main () {
    clock_t startTime, endTime, time_taken;
    startTime = clock();

    int vertex = 4;
    int globalMinimum = 5;

    int adjMat[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };

    int edges[4][2] = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}
    };

    int edgeGroups[16][4] = {
        {-1, -1, -1, -1},
        {0, -1, -1, -1},
        {1, -1, -1, -1},
        {2, -1, -1, -1},
        {3, -1, -1, -1},
        {0, 1, -1, -1},
        {0, 2, -1, -1},
        {0, 3, -1, -1},
        {1, 2, -1, -1},
        {1, 3, -1, -1},
        {2, 3, -1, -1},
        {0, 1, 2, -1},
        {1, 2, 3, -1},
        {0, 2, 3, -1},
        {0, 1, 3, -1},
        {0, 1, 2, 3},
    };

    for(int i = 0; i < 16; i++){

        int temp[4][4] = {0};
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                temp[j][k] = adjMat[j][k];
            }
        }

        for(int j = 0; j < 4; j++){
            if(edgeGroups[i][j] != -1){
                int u = edges[edgeGroups[i][j]][0];
                int v = edges[edgeGroups[i][j]][1];

                temp[u][v] = 0;
                temp[v][u] = 0;
            }
        }

        int count = 0;
        if(!isConnected(temp)){
            for(int j = 0; j < 4; j++){
                if(edgeGroups[i][j] != -1){
                    count++;
                    int u = edges[edgeGroups[i][j]][0];
                    int v = edges[edgeGroups[i][j]][1];

                    printf("(%d %d) ", u, v);
                }
            }
        }
        if(globalMinimum > count && count != 0){
            globalMinimum = count;
        }
        printf("\n");
    }
    printf("Edge connectivity : %d ", globalMinimum);

    endTime = clock();

    time_taken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}