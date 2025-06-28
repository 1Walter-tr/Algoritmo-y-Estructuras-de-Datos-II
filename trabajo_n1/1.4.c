/*Desarrollar un programa en lenguaje C que permita registrar colores personalizados utilizando una lista enlazada simple, gestionada mediante un menú interactivo.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CAR 25
typedef char tString[MAX_CAR];

typedef struct{
  int codigoColor;
  tString nombreColor;
}tColor;

typedef struct nodoColor{
  tColor color;
  struct nodoColor *siguiente;
}tNodoColor;

tColor ingresoDatos();
void mostrarColores(tColor color);
tNodoColor *agregarNodo(tNodoColor *lista, tColor color);
void mostrarLista(tNodoColor *lista);

int main(){
  tColor color;
  tNodoColor *lista = NULL;
  int opcion;

  do{
    printf("1. Ingresar color\n");
    printf("2. Mostrar lista\n");
    printf("3. Salir\n");
    printf("Elija una de las opciones: ");
    scanf("%d",&opcion);

    switch(opcion){
      case 1:
        color = ingresoDatos();
        lista = agregarNodo(lista,color);
        break;
      case 2:
        printf("----- LISTA DE COLORES -----\n");
        mostrarLista(lista);
        break;
      case 3:
        printf("Saliendo...\n");
        break;
      default:
        printf("Incorrecto. Elija una de las opciones predeterminadas\n");
        break;
    }
  }while(opcion!=3);

  return 0;
}

tColor ingresoDatos(){
  tColor color;

  printf("Ingrese el codigo del color: ");
  scanf("%d",&color.codigoColor);

  printf("Ingrse el nombre del color: ");
  scanf(" %[^\n]",color.nombreColor);

  return color;
}

void mostrarColores(tColor color){
  printf("Codigo: %d\n",color.codigoColor);
  printf("Nombre: %s\n",color.nombreColor);
  printf("----------------------\n");
}

tNodoColor *agregarNodo(tNodoColor *lista, tColor color){
  tNodoColor *nuevoNodo = (tNodoColor*)malloc(sizeof(tNodoColor));

  if(nuevoNodo != NULL){
    nuevoNodo->color = color;
    nuevoNodo->siguiente = lista;
  }

  return nuevoNodo;
}

void mostrarLista(tNodoColor *lista){
  if(lista == NULL){
    printf("La fila esta vacia\n");
    return;
  }

  tNodoColor *actual = lista;
  while(actual != NULL){
    mostrarColores(actual->color);
    actual = actual->siguiente;
  }
}