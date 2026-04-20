#include<stdio.h>

int cost[10][10], visited[10];
int n;

void dfs(int v);

int main()
{
    int i, j, k, m, start;

    scanf("%d", &n);
    scanf("%d", &m);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cost[i][j] = 0;

    for(i=1;i<=n;i++)
        visited[i] = 0;

    for(k=1;k<=m;k++)
    {
        scanf("%d %d", &i, &j);
        cost[i][j] = 1;
        cost[j][i] = 1;
    }

    scanf("%d", &start);

    dfs(start);

    return 0;
}

void dfs(int v)
{
    int i;

    printf("%d ", v);
    visited[v] = 1;

    for(i=1;i<=n;i++)
    {
        if(cost[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}
