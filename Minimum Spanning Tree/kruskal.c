#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 9
#define INF 999

int parent[MAX_VERTICES];

int find(int);
int uni(int, int);

int main()
{
    int i, j, k, a, b, u, v, n, ne = 1;
    int min, mincost = 0, cost[MAX_VERTICES][MAX_VERTICES];

    printf("\n\tImplementation of Kruskal's Algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Initialize parent array
    for (i = 1; i <= n; i++)
        parent[i] = 0;

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n) {
        for (i = 1, min = INF; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = INF;
    }
    printf("\n\tMinimum cost = %d\n", mincost);

    return 0;
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
