/*Diseñar un programa en lenguaje C que permita al usuario ingresar los datos de un color (código numérico y nombre) y luego mostrar esa información de forma organizada por pantalla.
Requisitos técnicos:
- Definir un tipo de dato struct personalizado tColor que contenga:
- Un número entero codigoColor.
- Un arreglo de caracteres nombreColor de longitud fija.
- Utilizar typedef para definir un alias de arreglo de caracteres llamado tString.
- Mostrar por consola el código y el nombre del color ingresado.*/
#include <stdio.h>
#include <string.h>

#define MAXCAR 25
typedef char tString[MAXCAR];

typedef struct{
  int codigoColor;
  tString nombreColor;
}tColor;

tColor ingresarColor();
void mostrarColor(tColor c);

int main(){
  tColor colores;

  colores = ingresarColor();
  mostrarColor(colores);
  
  return 0;
}

tColor ingresarColor(){
  tColor c;

  printf("Ingrese el codigo del color: ");
  scanf("%d",&c.codigoColor);
  printf("Ingrese el nombre del color: ");
  scanf(" %[^\n]",c.nombreColor);

  return c;
}

void mostrarColor(tColor c){
  printf("----- MOSTRAR COLOR -----\n");
  printf("Codigo: %d\n",c.codigoColor);
  printf("Nombre: %s\n",c.nombreColor);
}