#include <stdio.h>
#include <stdlib.h>

int main(){
    int edad = 42;
    int *punteroEdad = &edad; //Accedemos a la direccion de la variable edad

    printf("Valor original: %d\n",edad);
    printf("Valor desde puntero: %d\n", *punteroEdad); //Accedemos al valor a traves del puntero

    *punteroEdad = 90; //Ahora accedemos a la direccion de memoria y a traves de ella cambiamos el valor

    printf("Valor nuevo desde puntero: %d\n",*punteroEdad);

    return 0;
}