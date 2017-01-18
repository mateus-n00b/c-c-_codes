#include <stdio.h>

int fat (int n){
  if (n == 0)
    return 1;
  else
      return n*fat(n-1);
}

int main(int argc, char const *argv[]) {
  int n;

   n = fat(5)  ;
   printf("%d\n",n);
  return 0;
}
