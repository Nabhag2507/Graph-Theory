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

int isConnected(int adjMat[6][6]){
    int visited[6] = {0};
    dfs(0, 6, adjMat, visited);

    for(int i = 0; i < 6; i++){
        if(visited[i] == 0){
            return 0;
        }
    }
    return 1;
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int vertex = 6;

    int adjMat[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0},
    };

    int spanningTree[6][6] = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
    };

    int visited[6] = {0};

    // branches
    int branchCount = 5;
    int branches[5][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}};

    // chords
    int chordsCount = 3;
    int chords[3][2] = {{0, 2}, {2, 4}, {4, 5}};

    // chord combos
    int maxBranchesCount = 8;
    int combination[8][3][2] = {
        {},{{0,2}},{{2,4}},{{4,5}},{{0, 2},{2, 4}}, {{2, 4},{4, 5}}, {{0, 2},{4, 5}}, {{0, 2}, {2, 4}, {4, 5}}
    };

    int size[8] = {0, 1, 1, 1, 2, 2, 2, 3};

    for(int b = 0; b < branchCount; b++){
        for(int c = 0; c < maxBranchesCount; c++){
            int temp[vertex][vertex];

            for(int i = 0; i < vertex; i++){
                for(int j = 0; j < vertex; j++){
                    temp[i][j] = adjMat[i][j];
                }
            }

            int u = branches[b][0];
            int v = branches[b][1];

            temp[u][v] = 0;
            temp[v][u] = 0;

            for(int k = 0; k < size[c]; k++){
                int x = combination[c][k][0];
                int y = combination[c][k][1];

                temp[x][y] = 0;
                temp[y][x] = 0;
            }

            if(!isConnected(temp)){
                printf("{ ");

                printf("(%d, %d) ", u, v);
                for(int k = 0; k < size[c]; k++){
                    printf("(%d, %d) ", combination[c][k][0], combination[c][k][1]);
                }

                printf("}\n");
                break;
            }
        }
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}