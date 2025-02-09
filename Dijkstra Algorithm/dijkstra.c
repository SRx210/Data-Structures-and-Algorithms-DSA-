#include<stdio.h>
#define INF 999
#define MAX 10

void dijkstra(int Graph[MAX][MAX], int n, int start_node);

int main()
{
    int Graph[MAX][MAX];
    int i, j, n, source;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("Graph[%d][%d]: ", i, j);
            scanf("%d", &Graph[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(Graph, n, source);

    return 0;
}

void dijkstra(int Graph[MAX][MAX], int n, int start_node)
{
    int cost[MAX][MAX]; //creating as cost matrix
    int dist[MAX], predecessor[MAX], visited[MAX]; //predecessor[] stores the predecessor of each node
    int count, min_dist, next_node, i, j; //count gives the number of nodes visited
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(Graph[i][j]==0)
                cost[i][j] = INF;
            else
                cost[i][j] = Graph[i][j];
        }
    }
    for(i=1; i<=n; i++)
    {
        dist[i] = cost[start_node][i];
        predecessor[i] = start_node;
        visited[i] = 0;
    }
    dist[start_node] = 0;
    visited[start_node] = 1;
    count = 1;
    while(count < n-1)
    {
        min_dist = INF;
        //next node gives the node at minimum dist
        for(i=1;i<=n;i++)
        {
            if(dist[i]< min_dist&&!visited[i])
            {
                min_dist=dist[i];
                next_node=i;
            }
        }
        //check if a better path exists through nextnode
        visited[next_node]=1;
        for(i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                if((min_dist+cost[next_node][i]<dist[i]))
                {
                    dist[i]=min_dist+cost[next_node][i];
                    predecessor[i]=next_node;
                }
            }
        }
        count++;
    }

    // Printing the table header
    printf("\n\n%-12s%-12s%-18s%-12s", "Source", "Node", "Cost", "Path");

    // Printing the path and distance of each node in tabular form
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {printf("\n%-12d%-12d%-18d%-d", start_node, i, dist[i], i);}
        else if(i!=start_node)
        {
            printf("\n%-12d%-12d%-18d%-d", start_node, i, dist[i], i);
            j=i;
            do
            {
                j=predecessor[j];
                printf("<-%d",j);
            }while(j!=start_node);

        }
    }
}
