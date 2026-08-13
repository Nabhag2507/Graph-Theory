#include <stdio.h>

#define E 5
#define V 6

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

    printf("{ ");

    for(j = 0; j < E; j++){
        if(combinations[index][j] != -1){
            int u = edges[combinations[index][j]][0];
            int v = edges[combinations[index][j]][1];
            printf("{ %d, %d } ", u, v);
        }
    }

    printf("}");
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
            if(frequency[k] > 1){
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

void findMaximalMatching(){
    int maximalList[32];
    int maximalCount = 0;

    for(int i = 0; i < p; i++){
        int frequency[V] = {0};
        int u, v;
        int isMaximal = 1;

        for(int j = 0; j < E; j++){
            int edgeIdx = combinations[i][j];
            if(edgeIdx != -1){
                u = edges[edgeIdx][0];
                v = edges[edgeIdx][1];

                frequency[u]++;
                frequency[v]++;
            }
        }

        for(int j = 0; j < E; j++){
            u = edges[j][0];
            v = edges[j][1];
            
            if(frequency[u] == 0 && frequency[v] == 0){
                isMaximal = 0;
                break;
            }
        }

        if(isMaximal){
            maximalList[maximalCount++] = arr[i];
            printMatching(arr[i]);
            printf("\n");
        }
    }
}

void findMaximumMatching(){
    int i, j;
    int index;
    int size;
    int maxSize = 0;
	
    // Find maximum size
    for(i = 0; i < p; i++){
        index = arr[i];
        size = 0;

        for(j = 0; j < E; j++){
            if(combinations[index][j] != -1){
                size++;
            }
        }

        if(size > maxSize){
            maxSize = size;
        }
    }

    printf("\nMaximum Matching(s) of size %d:\n", maxSize);

    // Print all maximum matchings
    for(i = 0; i < p; i++){
        index = arr[i];
        size = 0;

        for(j = 0; j < E; j++){
            if(combinations[index][j] != -1){
                size++;
            }
        }

        if(size == maxSize){
            printMatching(index);
            printf("\n");
        }
    }
}

void main(){
    findMatching();

    findMaximalMatching();

    findMaximumMatching();
}
