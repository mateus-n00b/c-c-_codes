#include <stdio.h>

int main(){
	float F,C;
	printf("Fahrenheit >> ");
	scanf("%f",&F);		
	C=(F-32)/1.8;
	//F=((C/5)*9)+32;
	printf("Em Celsius %f\n",C);
return 0;
}
