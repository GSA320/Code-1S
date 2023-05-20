//Faça uma função que receba dois números inteiros positivos por parâmetro e retorne a soma dos N números inteiros existentes entre eles.
#include <stdio.h>
#include <string.h>

int fibonacci(int a, int b){
    int i,resultado;
    for(i=a;i<b-1;i++){
        a=a+1;
        resultado = resultado + a;
    }
   return resultado;
}

int main()
{
    int v1,v2;
    printf("Digite o valor 1: ");
    scanf("%d", &v1);
    printf("Digite o valor 2: ");
    scanf("%d", &v2);

    int resultado = fibonacci(v1,v2);
    printf("Resultado: %d", resultado);
   
    return 0;
}