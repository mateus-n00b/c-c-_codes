#include "stdio.h"
#include "stdarg.h"

double average(int num,...){
      va_list valist;
      double sum = 0.0;
      int i;

      va_start(valist,num);

      for (i = 0; i < num; i++) {
          sum+=va_arg(valist,int);
      }

      va_end(valist);
      return sum/num;
}

int main(int argc, char const *argv[]) {
  printf("average %.2f\n", average(4,2,3,4,5));
  return 0;
}
