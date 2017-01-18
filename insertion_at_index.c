#include "stdio.h"
#define MAX 5

int main(int argc, char const *argv[]) {
    int A[] = {1,2,4,5};
    int i = 0, n = 4, j = n;
    int value = 3,index = 2;

    printf("Before - \n" );
    for ( i = 0; i < n; i++) {
        printf("A[%d] = %d\n",i,A[i] );
    }

    for ( i = j; i >= index; i--) {
        A[i+1] = A[i];
    }

    n++;
    A[index] = value;

    printf("After - \n" );
    for ( i = 0; i < n; i++) {
        printf("A[%d] = %d\n",i,A[i] );
    }

  return 0;
}
