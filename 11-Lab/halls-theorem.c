#include <stdio.h>
#include <time.h>

int graph[4][4] = {
    {1, 1, 0, 0},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {0, 0, 1, 1}
};

int subsets[15][4] = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},

    {1,1,0,0},
    {1,0,1,0},
    {1,0,0,1},
    {0,1,1,0},
    {0,1,0,1},
    {0,0,1,1},

    {1,1,1,0},
    {1,1,0,1},
    {1,0,1,1},
    {0,1,1,1},

    {1,1,1,1}
};

int checkHallsCondition(){
    for(int subset = 0; subset < 15; subset++){
        int leftCount = 0;
        int rightCount = 0;
        int neighbor[4] = {0};

        for(int i = 0; i < 4; i++){
            if(subsets[subset][i] == 1) {
                leftCount++;
                for(int j = 0; j < 4; j++){
                    if(graph[i][j] == 1){
                        neighbor[j] = 1;
                    }
                }
            }
        }

        for(int j = 0; j < 4; j++){
            if(neighbor[j] == 1){
                rightCount++;
            }
        }

        if(leftCount > rightCount){
            return 0;
        }
    }

    return 1;
}

void main () {
    clock_t startTime, endTime;
    double time_taken;
    startTime = clock();

    int ans;

    ans = checkHallsCondition();

    if(ans == 1)
        printf("Hall's condition is satisfied");
    else
        printf("Hall's condition is not satisfied");

    endTime = clock();

    time_taken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %f ", time_taken);
}