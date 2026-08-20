#include <stdio.h>
#include <time.h>

#define E 5
#define V 7

int edges[][2] = {
    {0, 3},
    {0, 4},
    {1, 4},
    {1, 5},
    {2, 5}
};

int combinations[32][5] = {
    {-1,-1,-1,-1,-1},

    {0,-1,-1,-1,-1},
    {1,-1,-1,-1,-1},
    {2,-1,-1,-1,-1},
    {3,-1,-1,-1,-1},
    {4,-1,-1,-1,-1},

    {0,1,-1,-1,-1},
    {0,2,-1,-1,-1},
    {0,3,-1,-1,-1},
    {0,4,-1,-1,-1},
    {1,2,-1,-1,-1},
    {1,3,-1,-1,-1},
    {1,4,-1,-1,-1},
    {2,3,-1,-1,-1},
    {2,4,-1,-1,-1},
    {3,4,-1,-1,-1},

    {0,1,2,-1,-1},
    {0,1,3,-1,-1},
    {0,1,4,-1,-1},
    {0,2,3,-1,-1},
    {0,2,4,-1,-1},
    {0,3,4,-1,-1},
    {1,2,3,-1,-1},
    {1,2,4,-1,-1},
    {1,3,4,-1,-1},
    {2,3,4,-1,-1},

    {0,1,2,3,-1},
    {0,1,2,4,-1},
    {0,1,3,4,-1},
    {0,2,3,4,-1},
    {1,2,3,4,-1},

    {0,1,2,3,4}
};

int arr[32];
int p = 0;

void printMatching(int index){
    int j;

    for(j = 0; j < E; j++){
        if(combinations[index][j] != -1){
            int u = edges[combinations[index][j]][0];
            int v = edges[combinations[index][j]][1];
            printf("{ %d, %d } ", u, v);
        }
    }
}

void findMatching(){
    //code for Find Matching
    for(int i = 0; i < 32; i++){
        int frequency[V] = {0};

        for(int j = 0; j < E; j++){
            if(combinations[i][j] != -1){
                int edgeIdx = combinations[i][j];
                frequency[edges[edgeIdx][0]]++;
                frequency[edges[edgeIdx][1]]++;
            }
        }

        int flag = 1;
        for(int k = 0; k < V; k++){
            if(frequency[k] != 1){
                flag = 0;
                break;
            }
        }
        if(flag){
            printMatching(i);
            arr[p++] = i;
            printf("\n");
        }
    }
}

void main () {
    clock_t startTime, endTime, time_taken;
    startTime = clock();

    findMatching();

    endTime = clock();

    time_taken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}