#include <stdio.h>
#include <stdlib.h>

int main(){
    int *punteroNumero; //Creamos un puntero que no apunta generalmente a nada
    punteroNumero = malloc(sizeof(int)); //Asignamos memoria para el puntero

    if(punteroNumero==NULL){ //Verificamos si se guardo memoria
        printf("Error al asignar memoria\n");
        return 1;
    }

    *punteroNumero = 77; //Ahora apuntaria al heap asignado

    printf("Valor de puntero: %d\n",*punteroNumero);

    free(punteroNumero); //Una vez que usamos la memoria la liberamos

    return 0;
}