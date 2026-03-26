#include<stdio.h>
#include<math.h>
int knapsack(float p[],float w[],float capacity,int n)
{
	int A[20]={0},bestchoice[20],i,k;
	float bestweight=0,bestvalue=0,tempweight,tempvalue;
	for(i=1;i<=pow(2,n);i++)
	{
		int j=n-1;
		float tempweight=0,tempvalue=0;
		while(A[j]!=0 && j>0)
		{
			A[j]=0;
			j=j-1;
		}
		A[j]=1;
		for(k=0;k<n;k++)
		{
			if(A[k]==1)
			{
				tempweight=tempweight+w[k];
				tempvalue=tempvalue+p[k];
			}
		}
		if((tempvalue>bestvalue)&&(tempweight<=capacity))
		{
			bestvalue=tempvalue;
			bestweight=tempweight;
			for(k;k>=0;k--)
			bestchoice[k]=A[k];
		}
	}
	printf("solution vector:\n{");
	for(i=0;i<n;i++)
	printf("%d, ",bestchoice[i]);
	printf("}");
	return bestvalue;
}
int main()
{
	float weight[20],profit[20],capacity,bestprofit;
	int A[20];
	int i,j,k,n;
	printf("enter the no of objects");
	scanf("%d",&n);
	printf("enter weights of %d objects:\n",n);
	for(i=0;i<n;i++)
	scanf("%f",&weight[i]);
	printf("enter the profits of %d objects:\n",n);
	for(i=0;i<n;i++)
	scanf("%f",&profit[i]);
	printf("enter the capacity of knapsack:");
	scanf("%f",&capacity);
	bestprofit=knapsack(profit,weight,capacity,n);
	printf("\n profit:%f\n",bestprofit);
	return 0;
}
