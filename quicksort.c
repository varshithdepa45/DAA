#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[1000], n;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int low, int high) {
    int pivot = a[high];   // take last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quicksort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % n;
    }

    quicksort(0, n - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
