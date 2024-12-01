 #include <stdio.h>
#include <math.h>

void Merge(int arr[], int l, int m, int r);
void Mergesort(int arr[],int pesquisa, int length);


int main()
{
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(desordenada)/sizeof(desordenada[0]);
    printArray(desordenada,length);
    Mergesort(desordenada,0,length-1);
    printArray(desordenada,length);

    return 0;
}

void Merge(int arr[], int l, int m, int r){
    int i,j,aux;
    int n1 = m - l +1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i = 0; i<n1;i++){
        L[i] = arr[l+i];
    }
    for(j = 0; j< n2;j++){
        R[j] = arr[m+1+j];
    }

    i = 0;
    j=0;
    aux=l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[aux] = L[i];
            i++;
        } else {
            arr[aux] = R[j];
            j++;
        }
        aux++;
    }

 
    while (i < n1) {
        arr[aux] = L[i];
        i++;
        aux++;
    }

    while (j < n2) {
        arr[aux] = R[j];
        j++;
        aux++;
    }

}

void Mergesort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;

        Mergesort(arr,l,m);
        Mergesort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}