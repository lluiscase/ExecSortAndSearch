#include <stdio.h>

int interpolation( int arr[],int pesquisa,int max, int min);



int main()
{
    int ordenada[] = {1,2,3,4,5,6};
    int desordenada[] = {5,77,8,3,99,10};
    int length = sizeof(ordenada)/sizeof(ordenada[0]);
    int result = interpolation(ordenada,6,length-1,0);
    printf("Posição do elemento: %d \n",result);

    return 0;
}

int interpolation(int arr[],int pesquisa, int max, int min){
    
    while(min <= max && pesquisa >= arr[min] && pesquisa <=arr[max]){
        int meio = min +(pesquisa-arr[min]) * (max-min)/(arr[max] - arr[min]); 
        if(pesquisa == arr[meio]){
            return meio;
        }else if(pesquisa < arr[meio]){
             max = meio-1;
        }else{
             min = meio+1;
        }
    }
}