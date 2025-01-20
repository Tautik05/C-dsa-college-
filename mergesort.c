// Recursive Merge Sort with User Input
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
// 6,4,8,2,5,3,7,11

void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[100]; // Temporary array
    
    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++]; 
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];
    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void MergeSort(int A[], int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
    
}

int main() {
    int n, i;

    // Taking input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int A[n]; // Static array allocation

    // Taking input for array elements
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Performing Merge Sort
    MergeSort(A, 0, n - 1);

    // Printing the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
