 #include <stdio.h>
#include <math.h>

void Selection(int arr[],int length);


int main()
{
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(desordenada)/sizeof(desordenada[0]);
    printArray(desordenada,length);
    Selection(desordenada,length);
    printArray(desordenada,length);

    return 0;
}

void Selection(int arr[], int length){
    for(int i = 0; i<length - 1; i++){
        int index_min = i;
        for(int j = i + 1; j<length;j++){
            if(arr[j] < arr[index_min]){
                index_min = j;
            }
        }
        int aux = arr[i];
        arr[i] = arr[index_min];
        arr[index_min] = aux;
    }

}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}