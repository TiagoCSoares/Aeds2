#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    int fb;
    struct no *esq;
    struct no *dir;
} Node;




Node* rotacaoEsquerda(Node* raiz) {
    Node* temp = raiz;
    raiz = raiz->dir;
    temp->dir = raiz->esq;
    raiz->esq = temp;
    //temp->dir = raiz->esq;
    return raiz;
}

int main() {
    Node *n1 = (Node*) malloc(sizeof(Node));
    n1->info = 1;
    Node *n2 = (Node*) malloc(sizeof(Node));
    n2->info = 2;
    Node *n3 = (Node*) malloc(sizeof(Node));
    n3->info = 3;
    Node *n4 = (Node*) malloc(sizeof(Node));
    n4->info = 4;
    n1->dir = n2;
    n2->dir = n3;
    n2->esq = n4;
    Node* raiz = n1;
    raiz = rotacaoEsquerda(raiz);
    return 1;
}