#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTAS 101

void bucketSort(int notas[], int n);
int interpolationSearch(int notas[], int n, int chave);
void printArray(int arr[], int size);

int main() {
    int notas[] = {88, 95, 70, 55, 92, 85, 100, 67, 45, 80};
    int n = sizeof(notas) / sizeof(notas[0]);

    printf("Notas antes da ordenação:\n");
    printArray(notas, n);

    bucketSort(notas, n);

    printf("\nNotas após a ordenação:\n");
    printArray(notas, n);

    int chave = 85;
    int posicao = interpolationSearch(notas, n, chave);

    if (posicao != -1) {
        printf("\nNota %d encontrada na posição %d.\n", chave, posicao);
    } else {
        printf("\nNota %d não encontrada.\n", chave);
    }

    return 0;
}

void bucketSort(int notas[], int n) {
    int buckets[MAX_NOTAS] = {0};

    for (int i = 0; i < n; i++) {
        buckets[notas[i]]++;
    }

    int index = 0;
    for (int i = 0; i < MAX_NOTAS; i++) {
        while (buckets[i] > 0) {
            notas[index++] = i;
            buckets[i]--;
        }
    }
}

int interpolationSearch(int notas[], int n, int chave) {
    int inicio = 0, fim = n - 1;

    while (inicio <= fim && chave >= notas[inicio] && chave <= notas[fim]) {
        int pos = inicio + ((chave - notas[inicio]) * (fim - inicio)) / (notas[fim] - notas[inicio]);

        if (notas[pos] == chave) {
            return pos;
        }
        if (notas[pos] < chave) {
            inicio = pos + 1;
        } else {
            fim = pos - 1;
        }
    }

    return -1;  // Elemento não encontrado
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
