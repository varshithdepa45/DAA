#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *a,n;
int i,j;
int partition(int,int);
void quicksort(int p,int q){
	if(p<q){
		j = partition(p,q);
		quicksort(p,j-1);
		quicksort(j+1,q);
	}
}
int partition(int m , int p){
	int v = a[m];
	i = m;
	j = p+1;
	do{
		do{
			i++;
		}while(i<=p && a[i]<=v);
		do{
			j--;
		}while(j>=0 && a[j]>v);
		if(i<j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}while(i<=j);
	a[m] = a[j];
	a[j] = v;
	return j;
}
void main(){
	int i,j;
	double st,et,tt;
	printf("Enter no of elements");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
                //a[i] = (rand() %(n-0+1)) +0;
                a[i] = rand()%n;
		

	st = clock();
	quicksort(0,n-1);
	et = clock();
	tt = (double)(et-st)/CLOCKS_PER_SEC;
        printf("\nTime taken = %.6lf",tt);
	/*
	printf("Elements after sort are: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	*/
	
}
