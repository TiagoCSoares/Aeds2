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

void adicionaNaLista(Node lista[], int *disponivel, int *comeco, int valor) {
    lista[*disponivel].info = valor;
    lista[*disponivel].prox = *disponivel + 1;
    *disponivel += 1;
    if(*comeco == -1){
        *comeco += 1;
    }
}
int main() {
    Node lista[TAM];
    iniciaLista(lista, &comeco, &disponivel);

    int opcao, valor;
    do {
        printf("\n\nMenu de operações\n");
        printf("Case 0: Sair do menu\n");
        printf("Case 1: Imprimir a lista\n");
        printf("Case 2: Adicionar elemento na lista\n");
        printf("Selecione o valor:");
        scanf("%d", &opcao);
        printf("\n\n");
        switch (opcao) {
        case 1:
        printf("Imprimindo a lista:\n");
            imprimeLista(lista, comeco, disponivel);
            break;
        case 2:
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &valor);
            adicionaNaLista(lista, &disponivel, &comeco, valor);
            break;
        case 0:
            printf("Saindo do menu\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
    } while(opcao != 0);
    return 0;
}