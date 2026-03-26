#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int *a,n,i,j,minindex,t;
	double st,et,ts;
	printf("enter no of elements");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	//for(i=0;i<n;i++)
	//	a[i]=i+1;
	//j=0;
	//for(i=n;i>=0;i--)
	//	a[j++]=i;
	for(i=1;i<=n;i++)
		a[i]=rand()%n;
	printf("\nbefore sort elements are");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	
	st=clock();
	for(i=0;i<n;i++)
	{
		minindex=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[minindex])
				minindex=j;
		}
		if(i!=minindex)
		{
			t=a[i];
			a[i]=a[minindex];
			a[minindex]=t;
		}
	}
	et=clock();
	ts=(double)(et-st)/CLOCKS_PER_SEC;

	printf("\nelements after selection sort");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\nTime complexity is %lf ",ts);
}
