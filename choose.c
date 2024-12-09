#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void radixSort(int arr[], int n);
void bucketSort(float arr[], int n);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void shellSort(int arr[], int n);
int binarySearch(int arr[], int n, int target);
int interpolationSearch(int arr[], int n, int target);
int ternarySearch(int arr[], int left, int right, int target);
int exponentialSearch(int arr[], int n, int target);
int jumpSearch(int arr[], int n, int target);
void printArray(int arr[], int size);
void printFloatArray(float arr[], int size);

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 29};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice, target, result;
    clock_t start, end;
    double time_taken;

    printf("=== Programa de Busca e Ordenação ===\n");
    printf("Escolha uma opção:\n");
    printf("Ordenação:\n");
    printf("1. Quick Sort\n");
    printf("2. Radix Sort\n");
    printf("3. Bucket Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Shell Sort\n");
    printf("\nBusca:\n");
    printf("7. Binary Search\n");
    printf("8. Interpolation Search\n");
    printf("9. Ternary Search\n");
    printf("10. Exponential Search\n");
    printf("11. Jump Search\n");
    printf("Opção: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            start = clock();
            quickSort(arr, 0, n - 1);
            end = clock();
            printf("\nArray ordenado usando Quick Sort:\n");
            printArray(arr, n);
            break;
        case 2:
            start = clock();
            radixSort(arr, n);
            end = clock();
            printf("\nArray ordenado usando Radix Sort:\n");
            printArray(arr, n);
            break;
        case 3: {
            float bucketArr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
            int size = sizeof(bucketArr) / sizeof(bucketArr[0]);
            start = clock();
            bucketSort(bucketArr, size);
            end = clock();
            printf("\nArray ordenado usando Bucket Sort:\n");
            printFloatArray(bucketArr, size);
            break;
        }
        case 4:
            start = clock();
            selectionSort(arr, n);
            end = clock();
            printf("\nArray ordenado usando Selection Sort:\n");
            printArray(arr, n);
            break;
        case 5:
            start = clock();
            mergeSort(arr, 0, n - 1);
            end = clock();
            printf("\nArray ordenado usando Merge Sort:\n");
            printArray(arr, n);
            break;
        case 6:
            start = clock();
            shellSort(arr, n);
            end = clock();
            printf("\nArray ordenado usando Shell Sort:\n");
            printArray(arr, n);
            break;
        case 7:
            printf("\nDigite o número a ser buscado: ");
            scanf("%d", &target);
            start = clock();
            result = binarySearch(arr, n, target);
            end = clock();
            if (result != -1)
                printf("\nElemento encontrado na posição: %d\n", result);
            else
                printf("\nElemento não encontrado.\n");
            break;
        case 8:
            printf("\nDigite o número a ser buscado: ");
            scanf("%d", &target);
            start = clock();
            result = interpolationSearch(arr, n, target);
            end = clock();
            if (result != -1)
                printf("\nElemento encontrado na posição: %d\n", result);
            else
                printf("\nElemento não encontrado.\n");
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
    }

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.5f segundos.\n", time_taken);

    return 0;
}
