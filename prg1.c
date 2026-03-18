#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	double start_time, end_time, tt;

	int *a,size,key,c = 0;
	printf("Enter the size of the array");
	scanf("%d",&size);
	a = (int *)malloc(size*sizeof(int));
	for(int i = 0;i<size;i++){
		a[i]=i;
	}
	printf("enter the key element to be searched ");
	scanf("%d",&key);
	start_time = clock();
	for(int i=0;i<size;i++){
		if(a[i]==key){
			c = 1;
			break;
			}
	}
	end_time = clock();
	tt =(double)(end_time-start_time)/CLOCKS_PER_SEC;
	printf("\ntime spent for searching n elements is : %f\n",tt);
	if(c == 0)
		printf("Element is not found ");
	else
		printf("element is found");
}
