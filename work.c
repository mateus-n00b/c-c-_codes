/*
Um funcionário trabalha de Segunda a Sexta, de 8 até 11:59 e de
14 até 17:59. ATENÇÃO: As 17:59 é pra ele ainda estar trabalhando!
No Sábado ele trabalho de 8 até 11:59.
O chefe cansou de tentar decorar isso tudo e deu 15 contos pra você fazer um código onde ele informa o dia da semana, a hora e o minuto 
e seu código informa se ainda é para funcionário estar trabalhando!
Entrada:
A entrada é formada por um valor inteiro representando 
o dia:(1 = DOM, 2 = SEG, 3 = TER, 4 = QUA, 5 =QUI, 6 = SEX, 7 = SAB, ) 
e mais dois inteiros representando hora e minuto. A saída dever ser SIM se ele deve estar trabalhando ou NAO se ele não deve estar trabalhando.
*/

#include <stdio.h>

int main(){
    int dia,min,hora;
    scanf("%d",&dia);
    scanf("%d",&hora);
    scanf("%d",&min);

    if (dia >= 2 && dia <= 6){
        if (hora >= 8 && hora <= 11 && min <= 59){
            printf("SIM\n");
        }else if(hora >= 14 && hora <= 17 && min <= 59){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }

    }else if(dia == 7 && hora >= 8 && hora <= 11 && min <=59){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }
}