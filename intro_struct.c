#include "stdio.h"

/*
Em resumo, se temos uma variável estrutura e queremos acessar seus campos, usamos o
operador de acesso ponto ( p.x ); se temos uma variável ponteiro para estrutura, usamos o
operador de acesso seta ( pp->x ). Seguindo o raciocínio, se temos o ponteiro e queremos
acessar o endereço de um campo, fazemos &pp->x !
*/

struct ponto {
  float x;
  float y;
};

int main(int argc, char const *argv[]) {
  struct ponto p;

  // if ( argc < 2){
  //     printf("Usage: %s <pontoX> <pontoY>\n", argv[0]);
  //     return 0;
  // }

  printf("Digite os valores (x,y) ");
  scanf("%f %f", &p.x, &p.y);
  // p.x = (float) argv[1];
  // p.y = (float) argv[2];

  printf("p.x = %.2f; p.y = %.2f\n",p.x,p.y );
  return 0;
}
