#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *a, int low, int high) {
    int i = low, j = high;
    int s = a[(low + high) / 2];
    while (i <= j) {
        while (a[i] < s)
            i++;
        while (a[j] > s)
            j--;
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort(a, low, j);
    if (i < high)
        quickSort(a, i, high);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}