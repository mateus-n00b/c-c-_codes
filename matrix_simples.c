#include "stdlib.h"
#include "stdio.h"

/*
Matriz com vetor simples
Usando a estratégia com um vetor simples, o tipo matriz pode ser representado por uma
estrutura que guarda a dimensão da matriz e o vetor que armazena os elementos.
*/


typedef struct matrix {
    int lin;
    int col;
    float* v;
} M;

M* cria(int m, int n);
void libera(M* mat);
float atribui(M* mat, int i,int j, float v);
float acessa(M* mat,int i, int j);

int main(int argc, char const *argv[]) {
  M* mat ;
  mat = cria(4,4);
  atribui(mat, 2,2,5);
  printf("%.2f\n",acessa(mat, 2,2) );
  return 0;
}


M* cria(int m, int n){
  M* mat = (M*)malloc(sizeof(M));
  mat->lin = m;
  mat->col = n;
  mat->v = (float*) malloc(m*n*sizeof(float));
  return mat;
}

void libera(M* mat) {
    free(mat->v);
    free(mat);
}

float acessa(M* mat,int i, int j)
{
  int k;
  if(i<0 || i>=mat->lin || j<0 || j>=mat->col){
    printf("Entrada invalida\n" );
    exit(0);
  }
  k = i*mat->col+j;
  return mat->v[k];
}

float atribui(M* mat, int i,int j, float v)
{
  int k;
  if(i<0 || i>=mat->lin || j<0 || j>=mat->col){
    printf("Entrada invalida\n" );
    exit(0);
  }
  k = i*mat->col+j;
  mat->v[k] = v;
}
