#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir; 
} Node;



// Inserir novo elemento na Arvore
Node* insere (Node *raiz, int valor){
    Node* node = (Node *) malloc(sizeof(Node));
    node->info = valor;
    node->esq = NULL;
    node->dir = NULL;

    if(raiz == NULL) {
        raiz = node;
    } else {
        Node* aux = raiz;
        if(raiz->info > valor) {
            raiz->esq = insere(raiz->esq, valor);
        }
        if(raiz->info < valor) {
            raiz->dir = insere(raiz->dir, valor);
        }
    }

    return raiz;

}



//TODO: Mostrar a árvore
//Notações: Pré-Ordem, Em-ordem e Pós-ordem



//TODO: Remover da árvore
//DECISÃO: Maior item subárvore ou menor item subárvore direita




//TODO: Buscar elemento na árvore O(log n)

int main() {
    //Podemos suprimir a função "inicia" / "iniciaArvore" com essa declaração 
    //Node *raiz = (Node *) malloc(sizeof(Node));
    Node *raiz = NULL;
    
    raiz = insere(raiz, 50);
    raiz = insere(raiz, 30);
    raiz = insere(raiz, 60);
    //printf("O valor da informação é: %d \n", raiz->info);

    return 0;
}