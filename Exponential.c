 #include <stdio.h>
#include <math.h>

int Exponential( int arr[],int pesquisa,int n);
int binary(int arr[],int pesquisa, int length);


int main()
{
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(ordenada)/sizeof(ordenada[0]);
    int result = Exponential(ordenada,13,length);
    printf("Posição do elemento: %d \n",result);

    return 0;
}

int binary(int arr[],int pesquisa, int length){
    int inicio = 0;
    int fim = length-1;
    
    while(inicio <= fim){
        int meio = inicio + (fim - inicio)/2;    
        if(pesquisa == arr[meio]){
            return meio;
        }else if(pesquisa < arr[meio]){
             fim = meio-1;
        }else{
             inicio = meio+1;
        }
    }
}

int Exponential(int arr[],int pesquisa, int length){
    int i = 1;
    while (i<length && arr[i]<=pesquisa)
    {
        i=i*2;
    }
    
    return binary(arr,pesquisa,length);
}