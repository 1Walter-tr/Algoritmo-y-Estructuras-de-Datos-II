/*Desarrollar un programa en lenguaje C que permita registrar, visualizar y eliminar productos de un inventario, utilizando una lista enlazada simple. El programa debe ofrecer un menú interactivo con funcionalidades claras y controladas por el usuario.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CAR 25
typedef char tString[MAX_CAR];

typedef struct{
  int codigoProducto;
  tString nombreProducto;
}tProductos;

typedef struct tNodos{
  tProductos producto;
  struct tNodos *siguiente;
}tNodosProductos;

tProductos ingresarProducto();
tNodosProductos *agregarNodo(tNodosProductos *lista, tProductos productos);
tNodosProductos *eliminarPosicion(tNodosProductos *lista, int posicion);
void mostrarProductos(tProductos productos);
void mostrarLista(tNodosProductos *lista);

int main(){
  tProductos productos;
  tNodosProductos *lista = NULL;
  int opcion;
  int posicion;

  do{
    printf("1. Ingresar producto\n");
    printf("2. Mostrar lista\n");
    printf("3. Eliminar nodo\n");
    printf("4. Salir\n");
    printf("Elija una de las opciones: ");
  scanf("%d",&opcion);
    switch(opcion){
    case 1:
      productos = ingresarProducto();
      lista = agregarNodo(lista,productos);
      break;
    case 2:
      mostrarLista(lista);
      break;
    case 3:
      printf("Ingrese la posicion que desea eliminar: ");
      scanf("%d",&posicion);
      lista = eliminarPosicion(lista,posicion);
    break;
    case 4:
      printf("Saliendo...\n");
      break;
    default:
      printf("Incorrecto. Elija una de las opciones predeterminadas\n");
      break; 
    }
  }while(opcion!=4);

  return 0;
}

tProductos ingresarProducto(){
  tProductos producto;

  printf("Ingrese el codigo del producto: ");
  scanf("%d",&producto.codigoProducto);
  
  printf("Ingrese el nombre del producto: ");
  scanf(" %[^\n]",producto.nombreProducto);

  return producto;
}

tNodosProductos *agregarNodo(tNodosProductos *lista, tProductos productos){
  tNodosProductos *nuevoNodo = (tNodosProductos*)malloc(sizeof(tNodosProductos));

  if(nuevoNodo!=NULL){
    nuevoNodo->producto = productos;
    nuevoNodo->siguiente = lista;
  }

  return nuevoNodo;
}

tNodosProductos *eliminarPosicion(tNodosProductos *lista, int posicion){
  if(lista == NULL){
    printf("La lista esta vacia\n");
    return lista;
  }

  tNodosProductos *actual = lista;

  if(posicion == 1){
    lista = actual->siguiente;
    free(actual);
    printf("Posicion 1 eliminada\n");
    return lista;
  }

  for(int i = 1; actual != NULL && i < posicion - 1; i++){
    actual = actual->siguiente;
  }

  if(actual == NULL || actual->siguiente == NULL){
    printf("La posicion elegida no existe\n");
    return lista;
  }

  tNodosProductos *eliminar = actual->siguiente; //Ubicamos el nodo a eliminar
  actual->siguiente = eliminar->siguiente; //Saltamos el nodo eliminado
  free(eliminar); //Liberamos memoria
  printf("Posicion %d eliminada\n",posicion);

  return lista;
}

void mostrarProductos(tProductos productos){
  printf("Codigo del producto: %d\n",productos.codigoProducto);
  printf("Nombre del producto: %s\n",productos.nombreProducto);
  printf("\n");
  printf("--------------------------\n");
  printf("\n");
}

void mostrarLista(tNodosProductos *lista){
  printf("--- Lista de productos ---\n");

  if(lista==NULL){
    printf("La lista esta vacia\n");
    return;
  }

  tNodosProductos *actual = lista;
  while(actual!=NULL){
    mostrarProductos(actual->producto);
    actual=actual->siguiente;
  }
}
