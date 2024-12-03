#include <stdio.h>
int getMax(int arr[], int length);
void countSort(int arr[], int length, int exp, int base);
void radixSort(int arr[], int length, int base);


int main() {
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(desordenada)/sizeof(desordenada[0]);
    printArray(desordenada,length);
    radixSort(desordenada,length,16);
    printArray(desordenada,length);
    radixSort(desordenada,length,2);
    printArray(desordenada,length);

    return 0;
}

int getMax(int arr[], int length){
    int mx = arr[0];
    for(int i = 1; i< length; i++){
        mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int length, int exp, int base) {
    int output[length];
    int count[base];
    for (int i = 0; i < base; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        count[(arr[i] / exp) % base]++;
    }
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }
    for (int i = length - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }
    for (int i = 0; i < length; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int length, int base){
    int m = getMax(arr,length);
    for(int exp = 1; m / exp > 0; exp *=base){
        countSort(arr,length,exp,base);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}