#include <stdio.h>
#include <math.h>

int jump( int arr[],int pesquisa,int n);



int main()
{
    int ordenada[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(ordenada)/sizeof(ordenada[0]);
    int result = jump(ordenada,7,length);
    printf("Posição do elemento: %d \n",result);

    return 0;
}

int jump(int arr[],int pesquisa, int length){
    
    int pulo = (int)sqrt(length);
    int inicio = 0;

    while (arr[pulo - 1]< pesquisa){
        inicio = pulo;
        pulo += (int)sqrt(length);
        if (inicio >= length) return -1;
        
    }for (int i = inicio; i < pulo && i < length; i++)
    {
        if(arr[i] == pesquisa) return i;
    }
    return -1;
}