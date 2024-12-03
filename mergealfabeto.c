#include <stdio.h>
#include <math.h>
#include <string.h>

void Merge(char arr[][100], int l, int m, int r);
void Mergesort(char arr[][100],int pesquisa, int length);


int main()
{
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    char desordenada[][100] = {"abacaxi","melão","banana","maça","uva"};
    int length = sizeof(desordenada)/sizeof(desordenada[0]);
    printArray(desordenada,length);
    Mergesort(desordenada,0,length-1);
    printArray(desordenada,length);

    return 0;
}

void Merge(char arr[][100], int l, int m, int r){
    int i,j,aux;
    int n1 = m - l +1;
    int n2 = r-m;

    char L[n1][100], R[n2][100];

    for(i = 0; i<n1;i++){
        strcpy(L[i], arr[l+i]);
    }
    for(j = 0; j< n2;j++){
        strcpy(R[j], arr[m+1+j]);
    }

    i = 0;
    j=0;
    aux=l;
    
    while (i < n1 && j < n2) {
        if (strcmp(L[i] ,R[j])<= 0) {
            strcpy(arr[aux] ,L[i]);
            i++;
        } else {
            strcpy(arr[aux] ,R[j]);
            j++;
        }
        aux++;
    }

 
    while (i < n1) {
        strcpy(arr[aux],L[i]);
        i++;
        aux++;
    }

    while (j < n2) {
        strcpy(arr[aux],R[j]);
        j++;
        aux++;
    }

}

void Mergesort(char arr[][100], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;

        Mergesort(arr,l,m);
        Mergesort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}

void printArray(char A[][100], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%s ", A[i]);
    printf("\n");
}