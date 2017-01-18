#include "stdio.h"

main(){
  int A[] = {1,2,3,4,5};
  int n = 5, i, item = 2;
  int j = 0;

  printf("Items\n" );
  for ( i = 0; i < n; i++) {
      printf("A[%d] = %d\n",i,A[i] );
  }


  while (j < n) {
        if (A[j] == item)
            break;

        j++;
  }
  printf("Found item %d at the index %d\n",item,j );
  return 0;
}
