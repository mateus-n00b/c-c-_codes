#include <stdio.h>

int main(){
	float F,C;
	printf("Celsius >> ");
	scanf("%f",&C);		
	//C=(F-32)/1.8;
	F=((C/5)*9)+32;
	printf("Em F %f\n",F);
return 0;
}
