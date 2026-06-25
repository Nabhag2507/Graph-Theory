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

void main(){
    clock_t start, end, time_taken;
    start = clock();

    
    // adj[][] = [[1,2], [0,2], [0,1,3,4], [2], [2]] 
    // ans = [0, 1, 2, 3, 4] 

    int vertex = 6;
    // printf("Enter number of vertex : ");
    // scanf("%d", &vertex);

    // creating adjacency metrix 
    // int adjacencyMatrix[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 1, 1, 0}, {1, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int adjacencyMatrix[6][6] = {{0, 1, 1, 0, 0, 0}, {1, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 1}, {0, 0, 1, 1, 0, 0}, {0, 0, 0, 1, 0, 0}};
    // int adjacencyMatrix[3][3] = {{0, 1, 1}, {1, 0, 0}, {1, 0, 0}};

    int visited[5] = {0, 0, 0, 0, 0};

    // printf("Enter inputs for adjacency matrix: \n");
    // for(int i = 0; i < vertex; i++){
    //     for(int j = 0; j < vertex; j++){
    //         printf("Enter element for %d %d : ", i, j);
    //         scanf("%d",&adjacencyMatrix[i][j]);
    //     }
    // }

    push(0);
    visited[0] = 1;

    while(!isEmpty()){
        int node = poll();
        printf("%d ", node);

        for(int j = 0; j < vertex; j++){
            if(adjacencyMatrix[node][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                push(j);
            }
        }
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}
