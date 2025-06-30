/*Desarrollar un programa en lenguaje C que permita registrar, almacenar y visualizar productos de un depósito utilizando una lista enlazada simple. Además, debe poder contar la cantidad total de productos registrados.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CAR 25
typedef char tString[MAX_CAR];

typedef struct{
  int codigoProducto;
  tString nombreProducto;
  int cantStock;
}tProductos;

typedef struct nodoProducto{
  tProductos productos;
  struct nodoProducto *siguiente;
}tNodosProductos;

tProductos ingresarProducto();
void mostrarProductos(tProductos p);
tNodosProductos *agregarNodo(tNodosProductos *lista, tProductos p);
int contarNodos(tNodosProductos *lista);
void mostrarFila(tNodosProductos *lista);

int main(){
  tProductos productos;
  tNodosProductos *lista = NULL;
  int opcion;

  do{
    printf("1. Ingresar producto\n");
    printf("2. Mostrar lista de productos\n");
    printf("3. Mostrar cantidad de nodos\n");
    printf("4. Salir\n");
    printf("Elija una de las opciones: ");
    scanf("%d",&opcion);

    switch(opcion){
      case 1:
        productos = ingresarProducto();
        lista = agregarNodo(lista,productos);
        break;
      case 2: 
        printf("--- Lista de productos ---\n");
        mostrarFila(lista);
        break;
      case 3:
        printf("Cantidad de nodos en la lista %d\n",contarNodos(lista));
        break;
      case 4:
        printf("Saliendo...\n");
        break;
      default:
        printf("Incorrecto. Elija una de las opciones establecidas\n");
        break;
    }
  }while(opcion!=4);

  return 0;
}

tProductos ingresarProducto(){
  tProductos p;

  printf("Ingrese el codigo del producto: ");
  scanf("%d",&p.codigoProducto);

  printf("Ingrese el nombre del producto: ");
  scanf(" %[^\n]",p.nombreProducto);

  printf("Ingrese la cantidad en stock: ");
  scanf("%d",&p.cantStock);

  return p;
}

void mostrarProductos(tProductos p){
  printf("Codigo: %d\n",p.codigoProducto);
  printf("Nombre: %s\n",p.nombreProducto);
  printf("Cant en stock: %d\n",p.cantStock);
  printf("\n");
  printf("-------------------\n");
  printf("\n");
}

tNodosProductos *agregarNodo(tNodosProductos *lista, tProductos p){
  tNodosProductos *nuevoNodo = (tNodosProductos*)malloc(sizeof(tNodosProductos));

  if(nuevoNodo!=NULL){
    nuevoNodo->productos = p;
    nuevoNodo->siguiente = lista;
  }

  return nuevoNodo;
}

int contarNodos(tNodosProductos *lista){
  int contador = 0; //Variable que nos almacena la cantidad
  tNodosProductos *actual = lista;

  while(actual!=NULL){
    contador++;
    actual = actual->siguiente;
  }

  return contador;
  
}

void mostrarFila(tNodosProductos *lista){
  if(lista==NULL){
    printf("La lista esta vacia\n");
    return;
  }

  tNodosProductos *actual = lista;

  while(actual!=NULL){
    mostrarProductos(actual->productos);
    actual=actual->siguiente;
  }

}