#include <stdio.h>

#define TAM 8

typedef struct{
    int info;
    int prox;
} Node;

void iniciaLista(Node *lista) {
    for (int i = 0; i < TAM; i++){
        lista[i].info = i;
        lista[i].prox = i + 1;
    }
    lista[6].prox = 5;
    lista[4].prox = 6;
    lista[5].prox = 7;
    lista[TAM - 1].prox =-1;
}

void imprimeLista(Node *lista, int comeco) {
    int i = lista[comeco].prox;
    printf("Lista / Info: %d, Prox; %d\n", lista[comeco].info, lista[comeco].prox);
    while(i != comeco) {
        printf("Lista / Info: %d, Prox; %d\n", lista[i].info, lista[i].prox);
        i = lista[i].prox;
    }
}


int main() {

    int comeco = 0;
    Node lista[TAM];
    iniciaLista(lista);
    imprimeLista(lista, comeco);


    return 0;
}