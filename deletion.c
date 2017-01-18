#include "stdio.h"

int main(int argc, char const *argv[]) {
  int LA[] = {1,2,3,4,5};
  int i,j,n = 5, k =3;

  printf("The elements are - \n" );
  for ( i = 0; i < n; i++) {
      printf("LA[%d] = %d\n",i,LA[i] );
  }
  j = k;

  // Comeca na 3º posicao e pega o item da posicao anterior
  // e aloca na posicao atual.

  while (j<n) {
      LA[j-1] = LA[j];
      j++;
  }

  // Decrementa a variavel n
  n--;

  printf("After the deletion \n" );
  for ( i = 0; i < n; i++) {
      printf("LA[%d] = %d\n",i,LA[i] );
  }

  return 0;
}
