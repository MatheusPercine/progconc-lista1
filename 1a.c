#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float soma;

float pi(int n){
    soma = 0;
    float parcela;
    printf("%d\n", n);

    for (int i=0; i < n; i++){
        parcela = ((4/(8*i+1)) - (2/(8*i+4)) - (1/(8*i+5)) - (1/(8*i+6))) * (1/(pow(16, i)));
        printf("%d\n", parcela);
        soma += parcela;
    }

}

int main (int argc, char * argv[]){
    int n;
    float resultado;
    n = 5;

    resultado = pi(n);
    printf("%f", resultado);

}