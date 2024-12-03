#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketCount = max / 10 + 1;
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucketSizes[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        buckets[index][bucketSizes[index]] = arr[i];
        bucketSizes[index]++;
    }

    for (int i = 0; i < bucketCount; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(desordenada)/sizeof(desordenada[0]);
    printArray(desordenada,length);
    bucketSort(desordenada,length);
    printArray(desordenada,length);

    return 0;
}
