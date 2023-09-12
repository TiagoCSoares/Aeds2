//2. Usando somente aritmética de ponteiros, faça um programa que leia os valores de uma matriz de 2 por 2. 
//Ao final, exibir na tela os valores lidos na tela.
//
//Exemplo:
//
//m[2][2] = { 1,2,3,4 }; // Valores preenchidos após a leitura do teclado
//
//Exibição na tela:
//
//m[0][0]: 1
//
//m[0][1]: 2
//
//m[1][0]: 3
//
//m[1][1]: 4

#include <stdio.h>

int main() {
    int m[2][2];
    int *p1 = &m[0][0];

    printf("Digite os valores da matriz: \n");
    for(int i = 0; i < 4; i++) {
        scanf("%d", (p1 + i));
    }

    int a = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("m[%d][%d]: %d\n", i, j, *(p1 + a));
            a++;
        }  
    }
}