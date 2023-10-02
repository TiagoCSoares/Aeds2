#include <stdio.h>
#define TAM 4

int topo;

void empilhar(char *pilha, int *topo, char valor) { //push
    if(*topo >= TAM - 1){
        printf("Pilha cheia!\n\n");
    } else {
        *topo += 1;
        pilha[*topo] = valor;
    }
}

void imprimir(char *pilha, int topo) {
    if(topo < 0){
        printf("Pilha vazia!\n");
    } else {
        for(int i = topo; i > -1 ; i--){
            printf("Pilha [%d]: %c\n", i, pilha[i]);
        }
    }
    printf("-----------------------------\n");
}

char desempilha(char *pilha, int *topo) { //pop
    if(*topo < 0) {
        printf("Pilha vazia! Impossível remover.\n\n");
        return '\0';
    } else {
        *topo -= 1;
        printf("Elemento desempilhado!\n\n");
    }
    return pilha[*topo +1];
}
int main() {
    char pilha[TAM];
    topo = -1;
    
    //Mostrar lista vazia
    imprimir(pilha, topo);

    //Empilhar elementos
    empilhar(pilha, &topo, 's');
    empilhar(pilha, &topo, 'a');
    empilhar(pilha, &topo, 'b');
    empilhar(pilha, &topo, 'b');
    empilhar(pilha, &topo, 'b');

    //Mostrar a pilha com elementos
    imprimir(pilha, topo);

    //Desempilhar elementos da lista
    char c = desempilha(pilha, &topo);
    printf("Elemento desempilhado: %c\n", c);
    desempilha(pilha, &topo);
    desempilha(pilha, &topo);

    //Mostrar elementos após desempilhar
    imprimir(pilha, topo);
    /*
    char valor;
    int opcao;
    do{
        printf("Menu de operações\n");
        printf(0: Sair do Menu\n);
        printf(1: Imprimir Pilha.\n);
        printf(2: Adicionar elemento na Pilha.\n);
        printf(3: Desempilhar elemento da Pilha.\n);
        scanf("%d", &opcao);
        printf("\n\n");
        switch (opcao) {
            case 1:
                imprimir(pilha, topo);
                break;
            case 2:
                printf("Digite o caracter a ser inserido:");
                scanf("%c", &valor);
                empilhar(pilha, &topo, valor);
                break;
            case 3:
                desempilha(pilha, &topo);
                break;
            default:
                printf("Opção inválida\n");
                break;
        } 
    } while(opcao != 0);

    */
    return 0;
}