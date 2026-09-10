#include <stdio.h>
#include <time.h>

void main () {
    clock_t startTime, endTime, time_taken;
    startTime = clock();

    int vertex, edges;

    printf("Enter number of vertexes: ");
    scanf("%d",&vertex);

    printf("Enter number of edges: ");
    scanf("%d",&edges);

    int edges_matrix[edges][2];

    for(int i = 0; i < edges; i++){
        printf("Enter first vertex for edge %d : ", i + 1);
        scanf("%d",&edges_matrix[i][0]);

        printf("Enter second vertex for edge %d : ", i + 1);
        scanf("%d",&edges_matrix[i][1]);
    }

    int degree_matrix[vertex][vertex];
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            degree_matrix[i][j] = 0;
        }
    }

    int degree_array[vertex];
    for (int i = 0; i < vertex; i++) {
        degree_array[i] = 0;
    }

    for(int i = 0; i < edges; i++){
        degree_array[edges_matrix[i][0]]++;
        degree_array[edges_matrix[i][1]]++;
    }

    for(int i = 0; i < vertex; i++){
        degree_matrix[i][i] = degree_array[i];
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            printf("%d ", degree_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int adjacency_matrix[vertex][vertex];
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            adjacency_matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < edges; i++){
        adjacency_matrix[edges_matrix[i][0]][edges_matrix[i][1]] = 1;
        adjacency_matrix[edges_matrix[i][1]][edges_matrix[i][0]] = 1;
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int laplacian_matrix[vertex][vertex];

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            laplacian_matrix[i][j] = degree_matrix[i][j] - adjacency_matrix[i][j];
        }
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            printf("%d ", laplacian_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    endTime = clock();

    time_taken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}