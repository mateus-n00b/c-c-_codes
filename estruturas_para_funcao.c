#include "stdio.h"

/*
Passagem de estruturas para funções


A passagem de estruturas para funções se processa de forma análoga à passagem de
variáveis simples, porém exige uma análise mais detalhada. Da forma como está escrita no
código acima, a função recebe uma estrutura inteira como parâmetro. Portanto, faz-se uma
cópia de toda a estrutura para a pilha e a função acessa os dados desta cópia. Existem dois
pontos a serem ressaltados. Primeiro, como em toda passagem por valor, a função não tem
como alterar os valores dos elementos da estrutura original (na função imprime isso
realmente não é necessário, mas seria numa função de leitura). O segundo ponto diz
respeito à eficiência, visto que copiar uma estrutura inteira para a pilha pode ser uma
operação custosa (principalmente se a estrutura for muito grande). É mais conveniente
passar apenas o ponteiro da estrutura, mesmo que não seja necessário alterar os valores dos
elementos dentro da função, pois copiar um ponteiro para a pilha é muito mais eficiente do
que copiar uma estrutura inteira. Um ponteiro ocupa em geral 4 bytes, enquanto uma
estrutura pode ser definida com um tamanho muito grande.
*/

struct ponto {
  float x;
  float y;
};

void imprime(struct ponto* pp) {
    printf("ponto X = %.2f; ponto Y = %.2f \n", pp->x, pp->y);
}

void captura(struct ponto* pp) {
    printf("Digite os valores (x,y) ");
    scanf("%f %f", &pp->x, &pp->y);
}

int main(int argc, char const *argv[]) {
  struct ponto p;
  captura(&p);
  imprime(&p);
  return 0;
}
