#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
    int *a, key, i, n, flag = 0;
    double st,et,tt;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        a[i]=i+1;
    }

    printf("Enter key element to search: ");
    scanf("%d", &key);
    st=clock();

    for (i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            flag = 1;
            break;
        }
    }
    et=clock();
    tt=(double)(et-st)/CLOCKS_PER_SEC;
    printf("\n time required for searching %f",tt);

    if (flag == 0)
    {
        printf("Element not found");
    }
    else
    {
        printf("%d found at %d location", key, i + 1);
    }
    return 0;
}

