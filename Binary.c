/*
Este tipo de algoritmo tem a necessidade de estar ordenado pelo fato de precisar
saber o seu exato ponto para não ter que percorrer toda a lista, tendo um numero
em meio aos numeros grandes este lado não pode simplesmente ser descartado.
*/

#include <stdio.h>
int binary(int arr[],int pesquisa, int length);


int main()
{
    int ordenada[] = {1,2,3,4,5,6};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(ordenada)/sizeof(ordenada[0]);
    int result = binary(ordenada,2,length);
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