#include <stdio.h>
#include <time.h>

int node = 6, edgesCount = 5;
int edges[][2] = {{0,1}, {1,2}, {1,3}, {3,4}, {3,5}};

void degree_pendentVertex(){
    int deg[6] = {0};

    for(int i = 0; i < edgesCount; i++){
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
    }

    for(int i = 0; i < node; i++){
        printf("%d ", deg[i]);
    }

    printf("\nPendent vertex : ");

    for(int i = 0; i < node; i++){
        if(deg[i] == 1){
            printf("%d ", i);
        }
    }
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    degree_pendentVertex();

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}