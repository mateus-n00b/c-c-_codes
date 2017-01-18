#include "stdio.h"

int main(int argc, char const *argv[]) {
  printf("%s\n",__FILE__ );
  printf("%s\n",__DATE__ );
  printf("%s\n",__TIME__ );
  printf("%s\n",__LINE__ );
  printf("%d\n",__STDC__ );
  return 0;
}
