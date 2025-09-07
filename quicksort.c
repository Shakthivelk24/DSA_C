#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int pivot = arr[mid];
    swap(arr, mid, high);
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }

    swap(arr, i, high);
    return i;
}

void quick(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
