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

void bfs(int start, int vertex, int adjMat[][vertex], int visited[]){
    push(start);
    visited[start] = 1;

    while(!isEmpty()){
        int node = poll();

        for(int j = 0; j < vertex; j++){
            if(adjMat[node][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                push(j);
            }
        }
    }
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int vertex = 4;
    int adjMat[][4] = {
        {0, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0}
    };

    int visited[4] = {0};
    int counter = 0;

    for(int i = 0; i < vertex; i++){
        if(visited[i] == 0){
            bfs(i, vertex, adjMat, visited);
            counter++;
        }
    }

    printf("Total components are %d.", counter);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}