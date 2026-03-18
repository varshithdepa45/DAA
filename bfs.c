#include<stdio.h>
#include<stdlib.h>
void bfs();
int cost[10][10],explored[10],visited[10];
int queue[10],f=0,r=0;
int i,j,k,n,v,m;
int main()
{
        printf("enter no.of vertices\n");
        scanf("%d",&n);
        printf("enter no of edges:\n");
        scanf("%d",&m);
        for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                        cost[i][j]=0;
        for(k=1;k<=m;k++)
        {
                visited[i]=0;
                explored[i]=0;
        }
        printf("enter edges\n");
	for(k=1;k<=m;k++)
	{
		scanf("%d%d",&i,&j);
		cost[i][j]=cost[j][i]=1;
	}
	printf("initial vertex");
	scanf("%d",&v);
        printf("visited vertices\n");
        printf("%d\n",v);
        visited[v]=1;
        bfs();
        return 0;
}
void bfs()
{
        k=1;
        while(k<n)
        {
                for(j=1;j<=n;j++)
                {
                        if(cost[v][j]!=0&&visited[j]!=1&&explored[j]!=1)
                        {
                                explored[j]=1;
                                queue[r++]=j;
                        }
                }
		v=queue[f++];
                printf("%d",v);
                k++;
	        explored[v]=0;
                visited[v]=1;
                printf("\n");
       }
}
