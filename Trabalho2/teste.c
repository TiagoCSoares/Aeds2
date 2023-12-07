#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int unidadeTempo;
    int identificador;
    struct fila* proximo;
} Fila;

typedef struct {
    Fila* frente;
    Fila* tras;
} FilaEstrutura;

// Função para inicializar a fila
void inicializarFila(FilaEstrutura* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

// Função para enfileirar um elemento
void enfileirar(FilaEstrutura* fila, int unidadeTempo, int identificador) {
    Fila* novoElemento = (Fila*)malloc(sizeof(Fila));
    novoElemento->unidadeTempo = unidadeTempo;
    novoElemento->identificador = identificador;
    novoElemento->proximo = NULL;

    if (fila->tras == NULL) {
        // A fila está vazia
        fila->frente = novoElemento;
        fila->tras = novoElemento;
    } else {
        // Adiciona ao final da fila
        fila->tras->proximo = novoElemento;
        fila->tras = novoElemento;
    }
}

// Função para desenfileirar um elemento
void desenfileirar(FilaEstrutura* fila) {
    if (fila->frente == NULL) {
        // Fila vazia
        printf("Fila vazia.\n");
        return;
    }

    Fila* elementoRemovido = fila->frente;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        // A fila agora está vazia
        fila->tras = NULL;
    }

    free(elementoRemovido);
}

// Função para imprimir os elementos da fila
void imprimirFila(FilaEstrutura* fila) {
    Fila* atual = fila->frente;
    while (atual != NULL) {
        printf("Unidade de Tempo: %d, Identificador: %d\n", atual->unidadeTempo, atual->identificador);
        atual = atual->proximo;
    }
}

int main() {
    FilaEstrutura minhaFila;
    inicializarFila(&minhaFila);

    enfileirar(&minhaFila, 1, 101);
    enfileirar(&minhaFila, 2, 102);
    enfileirar(&minhaFila, 3, 103);

    printf("Fila inicial:\n");
    imprimirFila(&minhaFila);

    desenfileirar(&minhaFila);

    printf("\nFila após desenfileirar:\n");
    imprimirFila(&minhaFila);

    return 0;
}