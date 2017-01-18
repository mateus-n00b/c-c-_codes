#include "stdio.h"
#include "stdlib.h"
/*
Da mesma forma que podemos declarar vetores de estruturas, podemos também declarar
vetores de ponteiros para estruturas. O uso de vetores de ponteiros é útil quando temos que
tratar um conjunto elementos complexos. Para ilustrar o uso de estruturas complexas,
consideremos um exemplo em que desejamos armazenar uma tabela com dados de alunos.
Podemos organizar os dados dos alunos em um vetor.

Vale salientar que, sempre que possível, optamos por trabalhar com vetores criados
estaticamente. Eles tendem a ser mais eficientes, já que os vetores alocados dinamicamente
têm uma indireção a mais (primeiro acessa-se o valor do endereço armazenado na variável
ponteiro para então acessar o elemento do vetor).
*/


#define MAX 100

typedef struct aluno {
  char nome[81];
  char mat[11];
  char end[121];
  char tel[21];
} *A;

A tab[MAX];
void inicializa(void);

void preenche(int i);

void remover(int i);

void imprime(int i);

void imprime_tudo(void);

int main(int argc, char const *argv[]) {
  int opt,i;
  inicializa();

  while (1) {
      printf("\
      [1] - Cadastrar\n\
      [2] - Remover\n\
      [3] - Procurar usuario\n\
      [4] - Listar tudo\n\
      [*] - Exit\n\
      ==> ");
      scanf("%d",&opt );

      switch (opt) {
        case 1:
              printf("Array position " );
              scanf("%d",&i);
              preenche(i);
              continue;
        case 2:
              printf("Array position " );
              scanf("%d",&i);
              remover(i);
              continue;
        case 3:
              printf("Array position " );
              scanf("%d",&i);
              imprime(i);
              continue;
        case 4:
              imprime_tudo();
              continue;
        default :
              return 0;
  }
}
  return 0;
}

void inicializa(void) {
  int i;
  for ( i = 0; i < MAX; i++) {
    tab[i] = NULL;
  }
}

void preenche(int i){
    if (tab[i]==NULL)
        tab[i] = (A) malloc(sizeof(struct aluno));
    printf("Nome " );
    scanf(" %80[^\n]",tab[i]->nome );
    printf("Matricula ");
    scanf(" %10[^\n]", tab[i]->mat);
    printf("Endereco ");
    scanf(" %120[^\n]",tab[i]->end );
    printf("Telefone " );
    scanf(" %20[^\n]",tab[i]->tel );
    system("clear||cls");
    printf("Cadastrado!\n" );
}

void remover(int i){
    if (tab[i]!=NULL){
      free(tab[i]);
      tab[i]=NULL;
    }
}

void imprime(int i) {
    if (tab[i]!=NULL){
      printf("Nome: %s\n",tab[i]->nome);
      printf("Matricula: %s\n", tab[i]->mat);
      printf("Endereco: %s\n", tab[i]->end );
      printf("Telefone: %s\n", tab[i]->tel );
    }
}

void imprime_tudo(void) {
    system("clear||cls");
    int i;
    for ( i = 0; i < MAX; i++)
        imprime(i);
}
