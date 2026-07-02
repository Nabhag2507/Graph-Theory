#include <stdio.h>
#include <time.h>

int node = 6, edgesCount = 5;
int edges[][2] = {{0,1}, {1,2}, {1,3}, {3,4}, {3,5}};

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

int adjMat[6][6] = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };

int distance[6][6] = {0};

void bfs(int vertex, int visited[], int startingNode){
    push(startingNode);
    visited[startingNode] = 1;

    while(!isEmpty()){
        int node = poll();

        for(int j = 0; j < vertex; j++){
            if(adjMat[node][j] == 1 && visited[j] == 0){
                distance[startingNode][j] = distance[startingNode][node] + 1;
                visited[j] = 1;
                push(j);
            }
        }
    }
}

void disMat(int visited[]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            visited[j] = 0;
        }
        bfs(6, visited, i);
    }
}

int visited[6] = {0};
void main () {
    clock_t start, end, time_taken;
    start = clock();
    
    disMat(visited);
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf("%d ", distance[i][j]);
        }
        printf("\n");
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}