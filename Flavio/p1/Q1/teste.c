#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *ant;
    struct no_ *prox;
} no;


void inicia_lista(no **ptlista)
{
    *ptlista = malloc(sizeof(no));

    (*(*ptlista)).ant = (*ptlista);
    (*(*ptlista)).prox = (*ptlista);
}

void main(int argc, char **argv)
{
    no *ptlista;
    inicia_lista(&ptlista);

    printf("ptlista: %p\n", ptlista);
    printf("ptlista->ant: %p\n", (*ptlista).ant);
    printf("ptlista->prox: %p\n", ptlista->prox);
}