#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
        double start_time, end_time, tt;

        int *a,size,key,c = 0,low,high,mid;
        printf("Enter the size of the array");
        scanf("%d",&size);
        a = (int *)malloc(size*sizeof(int));
	low = 0;
	high =size-1;
        for(int i = 0;i<size;i++){
                a[i]=i;
        }
        printf("enter the key element to be searched ");
        scanf("%d",&key);
        start_time = clock();
        while(low<=high){
		mid = (low+high)/2;
		if(key == a[mid]){
			c = 1;
			break;
		}
		else if(key<a[mid]){
			high = mid -1;
		}
		else{
			low = mid + 1;
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

