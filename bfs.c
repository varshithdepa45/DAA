#include<stdio.h>

// global variables
int cost[10][10], visited[10];
int queue[10], f = 0, r = 0;
int n;

// function declaration
void bfs(int start);

int main()
{
    int i, j, k, m, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // initialize adjacency matrix
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cost[i][j] = 0;

    // initialize visited array
    for(i=1;i<=n;i++)
        visited[i] = 0;

    printf("Enter edges (u v):\n");

    // input edges
    for(k=1;k<=m;k++)
    {
        scanf("%d %d", &i, &j);

        // undirected graph
        cost[i][j] = 1;
        cost[j][i] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal:\n");

    bfs(start);   // call BFS

    return 0;
}

// BFS function
void bfs(int start)
{
    int i, v;

    // insert starting node into queue
    queue[r++] = start;

    // mark as visited
    visited[start] = 1;

    // loop until queue is empty
    while(f < r)
    {
        // remove from queue
        v = queue[f++];

        // print node
        printf("%d ", v);

        // check neighbors
        for(i = 1; i <= n; i++)
        {
            if(cost[v][i] == 1 && visited[i] == 0)
            {
                queue[r++] = i;   // add to queue
                visited[i] = 1;   // mark visited
            }
        }
    }
}
