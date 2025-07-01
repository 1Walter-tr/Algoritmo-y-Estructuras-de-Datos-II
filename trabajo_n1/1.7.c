/*Desarrollar un programa en lenguaje C que permita registrar productos, visualizarlos y buscar por código identificador, utilizando una lista enlazada simple.*/
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
  tProductos productos;
  struct tNodos *siguiente;
}tNodosProductos;

tProductos ingresoProductos();
tNodosProductos *agregarNodo(tNodosProductos *lista, tProductos productos);
void mostrarProductos(tProductos productos);
tNodosProductos *buscarCodigo(tNodosProductos *lista, int codigo);
void mostrarLista(tNodosProductos *lista);

int main(){
  tProductos productos;
  tNodosProductos *lista = NULL;
  int opcion;
  int codigo;

  do{
    printf("1. Ingresar producto\n");
    printf("2. Mostrar lista\n");
    printf("3. Buscar producto por codigo\n");
    printf("4. Salir\n");
    printf("Elija una de las opciones: ");
    scanf("%d",&opcion);

    switch(opcion){
      case 1:
        productos = ingresoProductos();
        lista = agregarNodo(lista,productos);
        break;
      case 2:
        mostrarLista(lista);
        break;
      case 3:
        printf("Ingrese el codigo del producto: ");
        scanf("%d",&codigo);
        lista = buscarCodigo(lista,codigo);
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

tProductos ingresoProductos(){
  tProductos productos;

  printf("Ingrese el codigo del producto: ");
  scanf("%d",&productos.codigoProducto);
  printf("Ingrese el nombre del codigo: ");
  scanf(" %[^\n]",productos.nombreProducto);

  return productos;
}

tNodosProductos *agregarNodo(tNodosProductos *lista, tProductos productos){
  tNodosProductos *nuevoNodo = (tNodosProductos*)malloc(sizeof(tNodosProductos));

  if(nuevoNodo!=NULL){
    nuevoNodo->productos = productos;
    nuevoNodo->siguiente = lista;
  }

  return nuevoNodo;
}

void mostrarProductos(tProductos productos){
  printf("--- Lista de productos ---\n");
  printf("Codigo: %d\n",productos.codigoProducto);
  printf("Nombre: %s\n",productos.nombreProducto);
  printf("---------------------");
  printf("\n");
}

tNodosProductos *buscarCodigo(tNodosProductos *lista, int codigo){
  tNodosProductos *actual = lista;

  while(actual!=NULL){
    if(actual->productos.codigoProducto == codigo){
      printf("\nProducto encontrado\n");
      mostrarProductos(actual->productos);
      return actual;
    }
    actual = actual->siguiente;
  }

  printf("Producto no encontrado\n");
  
  return NULL;
}

void mostrarLista(tNodosProductos *lista){
  if(lista==NULL){
    printf("\nLa lista esta vacia\n");
    return;
  }

  tNodosProductos *actual = lista;

  while(actual!=NULL){
    mostrarProductos(actual->productos);
    actual = actual->siguiente;
  }
}