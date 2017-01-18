#include <stdio.h>
#include <math.h>

main()
{
  float w,h,imc;
  
  printf("Weight: ");
  scanf("%f",&w);
 
  printf("Height: ");
  scanf("%f",&h);
  
  imc = w/pow(h,2.0);
  
  if (imc < 17 ){
	printf("muito abaixo do peso\n");
	
  }else if(imc >= 17 && imc <= 18.49){
	 printf("abaixo do peso\n");
  }
  else if (imc >= 18.5 && imc <= 24.99){
	printf("peso normal\n");
	}
	else if (imc >= 25 && imc <= 29.99){
		printf("acima do peso\n");
	}
	else if (imc >= 30 && imc <= 34.99){
		printf("obesidade\n");
	}
	else if (imc >= 40){
		printf("obesidade morbida");
	}
	return 0;
}
