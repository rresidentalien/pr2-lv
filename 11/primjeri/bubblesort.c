#include <stdio.h>

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *a, int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-1-i; j++)
            if (a[j+1] < a[j])
                swap(&a[j], &a[j+1]);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}