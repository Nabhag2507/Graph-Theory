#include <stdio.h>
#include <time.h>

int E, V;

void printMatching(int edges[][2], int combination[], int size) {
    for (int j = 0; j < size; j++) {
        int edgeIdx = combination[j];
        int u = edges[edgeIdx][0];
        int v = edges[edgeIdx][1];
        printf("{ %d, %d } ", u, v);
    }
}

void findMatching(int edges[][2]) {
    int totalCombinations = 1 << E;

    for (int i = 0; i < totalCombinations; i++) {
        int frequency[V];
        // Initialize frequency
        for (int k = 0; k < V; k++) {
            frequency[k] = 0;
        }

        int combination[E];
        int size = 0;
        // Generate one combination
        for (int j = 0; j < E; j++) {
            if (i & (1 << j)) {
                combination[size++] = j;
                int u = edges[j][0];
                int v = edges[j][1];
                frequency[u]++;
                frequency[v]++;
            }
        }

        // Check matching
        int flag = 1;
        for (int k = 0; k < V; k++) {
            if (frequency[k] != 1) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            printMatching(edges, combination, size);
            printf("\n");
        }
    }
}

void main() {

    clock_t startTime, endTime;
    double time_taken;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int edges[E][2];

    printf("\nEnter edges:\n");

    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    startTime = clock();

    findMatching(edges);

    endTime = clock();

    time_taken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %.3f ms\n", time_taken);
}