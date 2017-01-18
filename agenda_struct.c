#include "stdio.h"
#include "string.h"
/*
  Aprendendo C. Uma simples agenda usando
  estruturas, ponteiros para estruturas e arquivos.

  Mateus-n00b, Dezembro 2016

  Versao 1.0

  Licensa GPL

*/

#define AGENDA "/tmp/agenda.txt"

struct agenda  {
      char  nome[80];
      char email[90];
      char telefone[20];
};

void cadastro(struct agenda* a);
void remover(char * telefone);
void buscar(char * nome);
void listar();

int main(int argc, char const *argv[]) {
    int opt;
    struct agenda a;
    FILE *fp;
    while (1) {
        printf("Choose an option:\n\
        [1] Sign up\n\
        [2] Remove\n\
        [3] Update\n\
        [4] Search\n\
        [5] List\n\
        [*] Exit\n\
        >> " );
        scanf("%d",&opt );
        switch (opt) {
           case 1:
                  cadastro(&a);
                  printf("%s login sucessfull!\n",a.nome);
                  return 0;
           case 2:
                    listar();
                    printf("Remove>> " );
                    scanf(" %80[^\n]", &a.telefone);
                    // strcat(nome,"\n"); // Gambis pois as strings no texto estao com \n no fim da linha
                    remover(a.telefone);
                    continue;
            case 3:
                    listar();
                    printf("Alter>> ");
                    scanf("%s",&a.nome);
                    // strcat(nome,"\n");
                    remover(a.email);
                    cadastro(&a);
                    continue;
            case 4:
                printf("Procurar: " );
                scanf(" %80[^\n]", &a.nome);
                buscar(a.nome);
                continue;
            case 5:
                listar();
                continue;
            default :
                return 0;
        }
    }
}

void cadastro(struct agenda* a) {
    //  strcat(agenda,nome);
    FILE *fp;
    fp = fopen(AGENDA,"a+");
    if (!fp) {
      printf("Arquivo inexistente!\n" );
      exit(1);
    }

    printf("Insert your name: ");
    scanf(" %80[^\n]", &a->nome);
    printf("Insert your telephone number: ");
    scanf(" %80[^\n]", &a->email);
    printf("Insert your email: ");
    scanf(" %80[^\n]", &a->telefone);

    fprintf(fp, "%s ",a->nome);
    fprintf(fp, "%s ",a->email);
    fprintf(fp, "%s\n",a->telefone);
    fclose(fp);
}

void remover(char* telefone) {
    FILE *fp;
    char buffer[255];
    char bombril[500];
    int find = 0 ;
    fp = fopen(AGENDA,"r");
     while ( fgets(buffer, 255, (FILE*)fp)) {
            if (strstr(buffer,telefone) != NULL){
                // strcmp(buffer,nome) Invalida
                strcat(bombril,"");
            }else{
                strcat(bombril,buffer);
            }

     }
     fp = fopen(AGENDA,"w");
     fprintf(fp, "%s",bombril);
     fclose(fp);
}

void listar() {
  FILE *fp;
  char buffer[255];
  fp = fopen(AGENDA,"r");
  if (!fp) {
    printf("Arquivo inexistente!\n" );
    exit(1);
  }

  printf("\t\t========== CONTENT ==========\n" );
   while ( fgets(buffer,255,(FILE*)fp)) {
        printf("==> %s",buffer );
   }
}

void buscar(char * nome){
  FILE *fp;
  char buffer[255];
  fp = fopen(AGENDA,"r");
  if (!fp) {
    printf("Arquivo inexistente!\n" );
    exit(1);
  }

  while ( fgets(buffer,255,(FILE*)fp)) {
      if (strstr(buffer,nome) != NULL ) {
          printf("==> %s\n",buffer );
      }
  }
}
