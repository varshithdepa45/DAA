#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *a,*b,n;
int i,j,h,k;
void mergesort(int,int);
void merge(int,int,int);
void main(){
	int i;
	double st,et,tt;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	b = (int *)malloc(n*sizeof(int));
	/*worst case
	for(i = n;i>=0;i--)
		for(j = 0;j<n;j++)
		a[j] = i;
	*/
	/*best case
	for(i=0;i<n;i++)
		a[i] = i;
	*/
	/*
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	*/
	for(i=0;i<n;i++)
		//a[i] = (rand() %(n-0+1)) +0;
		a[i] = rand()%n;
		//
	st = clock();
	mergesort(0,n-1);
	et = clock();
	tt = (double)(et-st)/CLOCKS_PER_SEC;
	printf("\nTime taken = %.6lf",tt);
	/*
	printf("elements after sort are: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	*/	

}
void mergesort(int low, int high){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}
void merge(int low,int mid, int high){
	i = low;
	h = low; 
	j = mid+1;
	while((h<=mid) && (j<=high))
	{
		if(a[h]<=a[j]){
			b[i] = a[h];
			h++;
		}
		else{
			b[i] = a[j];
			j++;
		}
		i++;
	}
	if(h>mid){
		for(k=j;k<=high;k++){
			b[i] = a[k];
			i = i+1;
		}
	}
	else{
		for(k=h;k<=mid;k++){
			b[i] = a[k];
			i++;
		}
	}
	for(k=low;k<=high;k++){
		a[k] = b[k];
	}
}

