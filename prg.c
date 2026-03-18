include<stdio.h>
#include<stdlib.h>
int A[20][20],visited[20],stack[20];
int n,i,j,k,s,top=-1;
void DFS();
void main()
{
        printf("enter no.of nodes\n");
        scanf("%d",&n);
        printf("enter adjacency matrix");
        for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                        scanf("%d",&A[i][j]);
        for(i=1;i<=n;i++)
                visited[i]=0;
	printf("Enter starting vertex: ");
	scanf("%d",&v);
	printf("Enter no of nodes \n");
	scanf("%d",&n);
	printf("Depth first search");
