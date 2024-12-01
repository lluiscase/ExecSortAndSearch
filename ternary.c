 #include <stdio.h>
#include <math.h>

int Ternary(int arr[], int l,int r, int key);


int main()
{
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(desordenada)/sizeof(desordenada[0]);
    printArray(ordenada,length);
   int p= Ternary(ordenada,0,length,13);
    printArray(ordenada,length);

    printf("Index of 13 is %d\n",p);

    return 0;
}

int Ternary(int arr[], int l,int r, int key){
    if(r>=l){
        int mid1 = l + (r-l)/3;
        int mid2 = r-(r-l)/3;
        if(arr[mid1] == key){
            return mid1;
        }
        if(arr[mid2] == key){
            return mid2;
        }

        if(key < arr[mid1]){
            return Ternary(arr,l,mid1-1,key);
        }
        else if(key > arr[mid2]){
            return Ternary(arr,mid2+1,r,key);
        }else{
            return Ternary(arr,mid1+1,mid2-1,key);
        }
    }
    return -1;
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}