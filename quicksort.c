#include <stdio.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int a[100], n, i;
    clock_t start, end;
    double time_taken;

    // Input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Start time
    start = clock();

    // Call quicksort
    quicksort(a, 0, n - 1);

    // End time
    end = clock();

    // Calculate time
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Output sorted array
    printf("\nSorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Print execution time
    printf("\nExecution time = %f seconds", time_taken);

    return 0;
}


// Quick Sort
void quicksort(int a[], int low, int high){
    if(low < high){
        int p = partition(a, low, high);

        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}


// Partition function
int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(i <= j){
        while(a[i] <= pivot && i <= high)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Place pivot in correct position
    a[low] = a[j];
    a[j] = pivot;

    return j;
}
