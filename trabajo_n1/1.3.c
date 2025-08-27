#include <stdio.h>

void modificar(int *p);

int main(){
    int dato = 10; //Creamos una variable que tiene su propia direccion de memoria
    modificar(&dato); //Ahora *p tendra la direccion de dato
    printf("Valor nuevo: %d\n",dato);
}

void modificar(int *p){ //Creamos una funcion que nos almacenara la direccion de la variable que cambiaremos
    *p = 90; //Al acceder a esta variable cambiamos el valor
}