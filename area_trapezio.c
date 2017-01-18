#include "stdio.h"

typedef struct ponto {
      float x;
      float y;
} Ponto;

float area (int n, Ponto* p)
{
int i, j;
float a = 0;
for (i=0; i<n; i++) {
  j = (i+1) % n;
/* próximo índice (incremento circular) */
  a += (p[j].x-p[i].x)*(p[i].y + p[j].y)/2;
}
if (a < 0)
    return -a;
else
    return a;
}

int main(int argc, char const *argv[]) {
  Ponto p[3] = {{1.0,1.0},{5.0,1.0},{4.0,3.0}};
  printf("area = %f\n",area(3,p) );
  return 0;
}
