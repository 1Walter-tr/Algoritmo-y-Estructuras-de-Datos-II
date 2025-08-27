#include <stdio.h>

int main(){
    int numero = 10;
    int *ptr = &numero;

    printf("Valor de numero: %d\n",numero);
    printf("Direccion de numero: %p\n",&ptr);
    printf("Direccion a la cual apunta ptr: %p\n",ptr);
    printf("Valor al cual accede ptr: %d\n",*ptr);

    return 0;
}