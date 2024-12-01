 #include <stdio.h>
#include <math.h>

void swap(int* a,int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);


int main()
{
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(desordenada)/sizeof(desordenada[0]);
    printArray(desordenada,length);
    quickSort(desordenada,0,length-1);
    printArray(desordenada,length);

    return 0;
}

void swap(int* a,int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int arr[], int low, int high){
    int p = arr[low];
    int i = low;
    int j = high;
    while (i<j)
    {
        while (arr[i]<=p && i <=high - 1)
        {
            i++;
        }
        while (arr[j]>p&&j>=low+1)
        {
            j--;
        }if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
    
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }

}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}