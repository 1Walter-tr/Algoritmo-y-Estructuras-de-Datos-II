/*Intercambiar valores entre variables*/
#include <stdio.h>

void intercambiarValores(int *a, int *b);

int main(){
  int x = 10;
  int b = 90;

  printf("Valores antes del cambio\n");
  printf("x = %d\n",x);
  printf("b = %d\n",b);

  intercambiarValores(&x,&b);

  printf("Valores despues del cambio\n");
  printf("x = %d\n",x);
  printf("b = %d\n",b);
}

void intercambiarValores(int *a, int *b){
  int temp = *a; //Tenemos tres lugares, guardamos el lugar uno en el lugar vacio
  *a = *b; //Guuardamos el lugar dos en el lugar uno
  *b = temp; //Guardamos el lugar uno que estaba en el lugar vacio, en el lugar dos
}