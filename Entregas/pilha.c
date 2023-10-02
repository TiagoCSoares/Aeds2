/*
*
*Nome: Tiago Costa Soares
*Matrícula: 2020.1.08.017
*
*/


#include <stdio.h>
#define TAM 50

int topo;



int tamanhoString(const char *palavra) {
    int tamanho = 0;

    while (palavra[tamanho] != '\0') {
        tamanho++;
    }

    return tamanho;
}


void verificaPalindromo(char *pilha, const char *palavra, int tamanho) {
    int j = tamanho-1;
    int verifica = 0;
    for(int i = 0; i < tamanho-1; i++){
        if(pilha[j] != palavra[i]){
            printf("\n\nA palavra não é um palíndromo\n");
            verifica = 1;
            i = tamanho;
        }
        j-=1;
    }
    if(verifica == 0) {
        printf("\n\nA palavra é um palíndromo\n");
    }

    
}


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
        //printf("Elemento desempilhado!\n\n");
    }
    return pilha[*topo +1];
}
int main() {
    char pilha[TAM];
    topo = -1;
    

    char palavra[20];
    char valor;
    int opcao;

    do{
        printf("------------------------------------------\n");
        printf("Menu de operações\n");
        printf("0: Sair do Menu\n");
        printf("1: Imprimir Pilha.\n");
        printf("2: Adicionar elemento na Pilha.\n");
        printf("3: Desempilhar elemento da Pilha.\n");
        printf("4: Verificar se uma palavra é um palíndromo\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\n");
                imprimir(pilha, topo);
                break;
            case 2:
                printf("Digite o caracter a ser inserido:");
                scanf("%c", &valor);          //lê o expaço em branco
                scanf("%c", &valor);
                empilhar(pilha, &topo, valor);
                break;
            case 3:
                desempilha(pilha, &topo);
                break;
            case 4:
                printf("Digite a palavra a ser verificada: ");
                scanf("%s", &palavra);

                int tamanho = tamanhoString(palavra);

                while(topo >= 0) {
                    desempilha(pilha, &topo);
                }

                for(int i = 0; i < tamanho; i++){
                    empilhar(pilha, &topo, palavra[i]);
                }

                verificaPalindromo(pilha, palavra, tamanho);
                break;

            default:
                printf("Opção inválida\n");
                break;
        } 
        printf("\n\n");
    } while(opcao != 0);

    
    return 0;
}