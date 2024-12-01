#include <stdio.h>
int getMax(int arr[], int length);
void countSort(int arr[], int length, int exp);
void radixSort(int arr[], int length);


int main() {
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(desordenada)/sizeof(desordenada[0]);
    printArray(desordenada,length);
    radixSort(desordenada,length);
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

void countSort(int arr[], int length, int exp){
    int output[length];
    int count[10] = {0};

    for(int i = 0; i< length; i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i = 1; i<10;i++){
        count[i] += count[i-1];
    }
    for(int i = length - 1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i = 0; i< length;i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int length){
    int m = getMax(arr,length);
    for(int exp = 1; m / exp > 0; exp *=10){
        countSort(arr,length,exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}