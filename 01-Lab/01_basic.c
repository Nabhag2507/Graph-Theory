// create a basic graph using array

#include <stdio.h>
#include <stdlib.h>

void main () {
    int edge, vertex;
    printf("Enter size of edge array :");
    scanf("%d", &edge);

    printf("Enter size of vertex array :");
    scanf("%d", &vertex);

    int edgeArray[edge];

    for(int j = 0; j < edge; j++){
        printf("Enter element no %d :", j);
        scanf("%d", &edgeArray[j]);
    } 

    int vertexArray[edge][2];

    for(int i = 0; i < edge; i++){
        for(int j = 0; j < 2; j++){
            printf("Enter element no %d, %d :", i, j);
            scanf("%d", &vertexArray[i][j]);
        }
    }

    // this only works for sorted inputs
    printf("%d -> %d ", vertexArray[0][0], vertexArray[0][1]);
    for(int i = 1; i < edge; i++){
        if(vertexArray[i - 1][0] != vertexArray[i][0]){
            printf("\n%d -> %d ", vertexArray[i][0], vertexArray[i][1]);
        } else {
            printf(" %d ", vertexArray[i][1]);
        }
    }

    // this works for anything
    for(int i = 0; i < vertex; i++){
        printf("%d -> ", i);
        for(int j = 0; j < edge; j++){
            if(vertexArray[j][0] == i){
                printf(" %d", vertexArray[i][j]);
            }
        }
        printf("\n");
    }
}