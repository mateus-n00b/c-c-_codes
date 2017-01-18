#include <stdio.h>
#include "stdlib.h"

float mean(int n, float* v){
      int i;
      float sum = 0.0;
      for (i = 0; i < n; i++)
          sum += v[i];
      return sum/n;
}

int main(void) {
  int i,n;
  float m, *v;

  scanf("%d\n",&n );
  v = (float*) malloc(n*sizeof(float));
  if (v == NULL) {
    printf("Memoria insuficiente!\n");
    return 1;
  }

  for ( i = 0; i < n; i++)
      scanf("%f",&v[i]);
  m = mean(n,v);
  printf("%3.2f\n",m );
  free(v);
  return 0;
}
