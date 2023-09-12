//1. Usando somente aritmética de ponteiros, faça um programa que some dois vetores (de mesmo tamanho e já preenchidos) e armazene o resultado da soma em um terceiro vetor (inicialmente vazio).
//
//Exemplo:
//
//v1[5] = { 1,2,3,4,5 }; // Vetor 1
//
//v2[5] = { 6,7,8,9,10 }; // Vetor 2
//
//v3[5] = { 7,9,11,13,15 }; // Vetor 3 → Soma do Vetor 1 + Vetor 3

#include <stdio.h>

int main() {

    int v1[5] = { 1,2,3,4,5 };
    int v2[5] = { 6,7,8,9,10 };
    int v3[5];

    int *p1 = &v1[0];
    int *p2 = &v2[0];
    int *p3 = &v3[0];

    for(int i = 0; i < 5; i++) {
        *(p3 + i) = *(p1 + i) + *(p2 + i);
    }

    for(int i = 0; i < 5; i++) {
        printf("%d\n", *(p3 + i));
    }

    return 0;
}