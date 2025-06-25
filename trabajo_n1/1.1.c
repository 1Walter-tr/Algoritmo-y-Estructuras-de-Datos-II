/*Declarar una variable y despues cambiar el valor de esta, para asi mostrar su valor original y su valor original*/
#include <stdio.h>

int main(){
  int x = 10; //Declaramos una variable
  int *ptr = &x; //Declaramos una variable puntero que apunta a la direccion de x

  printf("--- COMPRENDER VARIABLE Y DIRECCION DE MEMORIA\n");
  printf("Valor de x: %d\n",x);
  printf("Direccion de memoria de x: %p\n",&x); //Esto es solamente la direccion
  printf("Valor de ptr: %p\n",ptr); //Es la misma que la direccion de x, ya que esta la apunta
  printf("Contenido a cual apunta *ptr: %d\n",*ptr);

  printf("--- CAMBIAR VALOR DE VARIABLE ---\n");
  printf("Valor original de la variable: %d\n",x);
  *ptr = 20; //Actualizamos el valor de la variable
  printf("Valor cambiado de la variable: %d\n",x);

  return 0;
}