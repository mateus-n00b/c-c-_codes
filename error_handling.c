#include "stdio.h"
#include "string.h"
#include "errno.h"

extern int errno;

int main(int argc, char const *argv[]) {
  FILE *fp;
  int errnum;
  fp = fopen("null.txt","rb");

  if (fp == NULL) {
      errnum = errno;
      fprintf(stderr, "Value: %d\n",errno );
      perror("Error printed by perror> ");
      fprintf(stderr, "Error opening file: %s\n",strerror(errnum) );
  }else
  {
    fclose(fp);
  }

  return 0;
}
