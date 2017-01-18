#include "stdio.h"
#define MAX 5

int main(int argc, char const *argv[]) {
  int array[MAX] = {2,3,4,5};
  int i;
  int value = 1 , n = 4, j = n;


  printf("Before\n",n );
  for ( i = 0; i < n; i++) {
      printf("A[%d] = %d\n",i,array[i] );
  }

  // jogando os valores para uma posicao a frente
  // Foi necessario criar j = n pois o loop modificou o valor de n
  //

  for ( i = j; i >=0 ; i--) {
      array[i+1] = array[i];
  }

  // Inserindo novo item na primeira posicao

  array[0] = value;
  n++;
  printf("After \n" );

  for ( i = 0; i < n; i++) {
      printf("A[%d] = %d\n",i,array[i] );
  }

  return 0;
}
