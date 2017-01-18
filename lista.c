#include "stdio.h"
#include "string.h"
/*
  Tentando criar uma lista
*/

#define AGENDA "/tmp/agenda.txt"

struct agenda  {
      char * nome;
      char * numero;
      char * telefone;
};

void cadastro(char *nome);
void remover(char *nome);
void buscar(char * nome);
void listar();

int main(int argc, char const *argv[]) {
    int opt;
    char nome[0];

    FILE *fp;
    printf("Choose an option:\n\
    [1] Sign up\n\
    [2] Remove\n\
    [3] Update\n\
    [4] Search\n\
    [*] Exit\n\
    >> " );
    scanf("%d",&opt );
    switch (opt) {
       case 1:
              printf("Insert your name: ");
              scanf(" %80[^\n]", &nome);
              cadastro(nome);
              printf("%s login sucessfull!\n",nome);
              return 0;
       case 2:
                listar();
                printf("Remove>> " );
                scanf(" %80[^\n]", &nome);
                // strcat(nome,"\n"); // Gambis pois as strings no texto estao com \n no fim da linha
                remover(nome);
                return 0;
        case 3:
                listar();
                printf("Alter>> ");
                scanf("%s",&nome);
                strcat(nome,"\n");
                remover(nome);
                printf("New name>> " );
                scanf("%s", &nome);
                cadastro(nome);
                return 0;
        case 4:
            printf("Procurar: " );
            scanf(" %80[^\n]", &nome);
            buscar(nome);
            return 0;
        default :
            return 0;
    }
}

void cadastro(char *nome) {
    //  strcat(agenda,nome);
    FILE *fp;
    fp = fopen(AGENDA,"a+");
    if (!fp) {
      printf("Arquivo inexistente!\n" );
      exit(1);
    }

    fprintf(fp, "%s\n",nome);
    fclose(fp);
}

void remover(char *nome) {
    FILE *fp;
    char buffer[255];
    char bombril[500];
    int find = 0 ;
    fp = fopen(AGENDA,"r");
     while ( fgets(buffer, 255, (FILE*)fp)) {
            if (strstr(buffer,nome) != NULL){
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
        printf("%s",buffer );
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
          printf("%s\n",buffer );
      }
  }

}
