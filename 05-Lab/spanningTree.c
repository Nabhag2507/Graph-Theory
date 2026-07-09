#include <stdio.h>
#include <time.h>

int queue[10];
int rear = -1, front = -1;

void push(int n){
    if(rear == 9){
        // printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = n;
}

int poll(){
    if(front == -1 || front > rear){
        printf("Queue underflow\n");
        return -1;
    } else {
        int val = queue[front++];
        if(front > rear){
            front = rear = -1;
        }
        return val;
    }
}

int peek(){
    if(front == -1 || front > rear){
        printf("Queue underflow\n");
        return -1;
    } else {
        return queue[rear];
    }
}

int isEmpty(){
    return (front == -1 || front > rear) ? 1 : 0;
}

void findSpannigTree(int start, int vertex, int visited[], int adjMat[][vertex], int spanningTree[][vertex]){
    push(start);
    visited[start] = 1;

    printf("Branches : \n");
    while(!isEmpty()){
        int node = poll();

        for(int j = 0; j < vertex; j++){
            if(adjMat[node][j] == 1 && visited[j] == 0){
                printf("%d %d\n", node, j);
                visited[j] = 1;
                spanningTree[node][j] = 1;
                spanningTree[j][node] = 1;
                push(j);
            }
        }
    }
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int vertex = 5;
    int adjMat[][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int visited[5] = {0};
    int counter = 0;

    int spanningTree[5][5] = {0};

    findSpannigTree(0, vertex, visited, adjMat, spanningTree);

    printf("Spanning Tree : \n");
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            printf("%d ", spanningTree[i][j]);
        }
        printf("\n");
    }

    printf("Chords : \n");
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if(adjMat[i][j] == 1 && spanningTree[i][j] == 0){
                printf("%d %d \n", i, j);
            }
        }
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}