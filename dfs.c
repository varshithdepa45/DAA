#include<stdio.h>
#include<stdlib.h>
int A[20][20],visited[20],stack[20];
int n,i,j,k,s,top=-1,count=1;
void DFS();
void main()
{
	printf("enter no.of nodes\n");
	scanf("%d",&n);
	printf("enter adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&A[i][j]);
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("enter starting vertex");
	scanf("%d",&s);
	visited[s]=1;
	printf("DFS=%d\t",s);
	DFS();
	if(count!=n){
		printf("\nGraph is disconnected ");
	}
	else{
		printf("\nGraph is connected");
	}
}
void DFS()
{
	stack[++top]=s;
	k=1;
	while(k<n)
	{
		for(i=1;i<=n;i++)
		{
			if(A[s][i]==1&&visited[i]==0)
			{
				stack[++top]=i;
				s=i;
				visited[i]=1;
				printf("%d\t",s);
				count ++;
				break;
			}
		}
		if(i>n)
		s=stack[--top];
		else
			k++;
	}
}
