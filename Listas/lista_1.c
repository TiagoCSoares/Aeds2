#include<stdio.h>
#define TAM 8

typedef struct {
    int info;
    int prox;
} Node;

int comeco;
int disponivel;

void iniciaLista(Node *lista, int *comeco, int *disponivel) {

    for (int i = 0; i < TAM-1; i++) {
        lista[i].info = 0;
        lista[i].prox = i + 1;
    }
    lista[TAM-1].info = 0;
    lista[TAM-1].prox = -1;
    *comeco = -1;
    *disponivel = 0;
}

// Comeco == 0
void imprimeLista(Node *lista, int comeco, int disponivel) {
    if(comeco == -1){
        printf("Lista vazia! \n");
    }
    else {
        int proximo = lista[comeco].prox;
        printf("Lista / Info: %d, Prox: %d\n", lista[comeco].info, lista[comeco].prox);
        while(proximo != -1 && proximo != disponivel) {  
            printf("Lista / Info: %d, Prox: %d\n", lista[proximo].info, lista[proximo].prox);
            proximo = lista[proximo].prox;
        }
    }
}

void adicionaNaLista(Node lista[], int *disponivel, int valor) {

}
int main() {
    Node lista[TAM];
    iniciaLista(lista, &comeco, &disponivel);
    imprimeLista(lista, comeco, disponivel);
    adicionaNaLista(lista, &disponivel, 18);
    return 0;
}