#include <stdio.h>

#define V 4

int adj[V][V] = {
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {0,1,0,0}
};

int singles[4][1] = {
    {0},
    {1},
    {2},
    {3}
};

int pairs[6][2] = {
    {0,1},
    {0,2},
    {0,3},
    {1,2},
    {1,3},
    {2,3}
};

int triplets[4][3] = {
    {0,1,2},
    {0,1,3},
    {0,2,3},
    {1,2,3}
};

int all[1][4] = {
    {0,1,2,3}
};

int isDominatingSet(int set[], int size)
{
    int dominated[V] = {0};
	int i = 0, j = 0;
    for(i=0;i<size;i++)
    {
        int u = set[i];

        dominated[u] = 1;

        for(j=0;j<V;j++)
        {
            if(adj[u][j])
                dominated[j] = 1;
        }
    }

    for(i=0;i<V;i++)
    {
        if(!dominated[i])
            return 0;
    }

    return 1;
}

void printSet(int set[], int size)
{
	int i = 0;
    printf("{ ");

    for(i=0;i<size;i++)
        printf("%d ", set[i]);

    printf("}\n");
}

void main()
{
    int dominationNumber = V + 1;
	int i = 0;
    printf("Dominating Sets:\n\n");

    for(i=0;i<4;i++)
    {
        if(isDominatingSet(singles[i],1))
        {
            printSet(singles[i],1);
            dominationNumber = 1;
        }
    }

    for(i=0;i<6;i++)
    {
        if(isDominatingSet(pairs[i],2))
        {
            printSet(pairs[i],2);

            if(dominationNumber > 2)
                dominationNumber = 2;
        }
    }

    for(i=0;i<4;i++)
    {
        if(isDominatingSet(triplets[i],3))
        {
            printSet(triplets[i],3);

            if(dominationNumber > 3)
                dominationNumber = 3;
        }
    }

    if(isDominatingSet(all[0],4))
    {
        printSet(all[0],4);

        if(dominationNumber > 4)
            dominationNumber = 4;
    }

    printf("\nDomination Number = %d\n", dominationNumber);

}