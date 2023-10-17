/* 
 * Valor da questão: 2,0.
 * LEIA COM ATENÇÃO:
 * Este código implementa uma fila circular que executa em um vetor (alocação sequencial).
 *
 * Você deve implementar no código a seguir as funções responsáveis pela inserção
 * e remoção dos valores da fila (inserir e remover, respectivamente). O cabeçalho
 * das funções já se encontra proposto, de modo que não pode ser modificado.
 *
 * Ob.: É obrigatório o uso da fórmula matemática para implementar o comportamento circular da fila.
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Insere um elemento na fila.
 * 
 * @param inicio 
 *	aponta para a posicao onde esta o primeiro elemento da fila.
 * @param fim 
 *	aponta para a posicao onde esta o ultimo elemento da fila.
 * @param tamanho 
 *	tamanho maximo da fila.
 * @param fila 
 *	fila na qual o elemento sera inserido.
 * @param elemento 
 *	elemento a ser inserido.
 * @return 
 *	a posicao de insercao, ou -1 caso esteja cheia.
 */
int inserir(int * inicio, int * fim, int tamanho, int fila[tamanho], int elemento) {
    if (((*fim) + 1) % tamanho == (*inicio)) {
        // Queue is full
        return -1;
    } else {
        // Insert element at the rear end of the queue
        (*fim) = ((*fim) + 1) % tamanho;
        fila[(*fim)] = elemento;
        if ((*inicio) == -1) {
            (*inicio) = (*fim);
        }
        return (*fim);
    }
}
	return -1;

/**
 * Remove um elemento da fila.
 * 
 * @param inicio
 *	aponta para a posicao onde esta o primeiro elemento da fila.
 * @param fim
 *	aponta para a posicao onde esta o ultimo elemento da fila.
 * @param tamanho
 *	tamanho maximo da fila.
 * @param fila
 *	fila na qual o elemento sera inserido.
 * @return
 *	elemento removido, ou NULL caso a fila esteja vazia.
 */
int * remover(int * inicio, int * fim, int tamanho, int fila[tamanho]) {
     int* retorno = NULL;
	 if ((*inicio) == -1) {
        // Queue is empty
        return retorno;
    } else {
        // Remove element from the front end of the queue
        retorno = &fila[(*inicio)];
    if ((*inicio) == (*fim)) {
         (*inicio) = -1;
         (*fim) = -1;
    } else {
            (*inicio) = ((*inicio) + 1) % tamanho;
        }
        return retorno;
    }
}


/**
 * Escreve a fila.
 * 
 * @param inicio
 *	indice onde esta o primeiro elemento da fila.
 * @param fim
 *	indice onde esta o ultimo elemento da fila.
 * @param tamanho
 *	tamanho maximo da fila.
 * @param fila
 *	fila que sera impressa.
 */
void escrever(int inicio, int fim, int tamanho, int fila[tamanho]) {
	if (inicio != -1) {
		char s[] = "<---- inicio ";
		char s2[] = "<---- fim";
		while (inicio != fim) {
			printf("|%5d|", fila[inicio]);
			printf("%s", s);
			s[0] = '\0';
			printf("\n-------\n");
			inicio = ((inicio) + 1) % tamanho;
		}
		printf("|%5d|", fila[inicio]);
		printf("%s", s);
		printf("%s", s2);
		printf("\n-------\n");
	} else {
		printf("-------\n");
		printf("-------\n");
		printf("Fila vazia!\n");
	}
}

void main() {
	int tamanho;
	//printf("Informe o tamanho da fila: ");
	scanf("%d", &tamanho);
	int fila[tamanho];
	int operacao;
	int elemento;
	int inicio = -1;
	int fim = -1;

	do {
		/*printf("====================\n");
		printf("Informe a operacao:\n");
		printf("0 - inserir.\n");
		printf("1 - remover.\n");
		printf("2 - escrever.\n");
		printf("3 - sair.\n");*/
		scanf("%d", &operacao);

		if (operacao == 0) {
			//printf("Informe o elemento a ser inserido: ");
			scanf("%d", &elemento);
			int retorno = inserir(&inicio, &fim, tamanho, fila, elemento);
			/*if (retorno >= 0)
				printf("Elemento inserido na posicao %d.\n", retorno);
			else
				printf("Fila cheia! Elemento nao inserido.\n");*/
		} else if (operacao == 1) {
			int * retorno = remover(&inicio, &fim, tamanho, fila);
			/*if (retorno != NULL)
				printf("Elemento removido: %d.\n", *retorno);
			else
				printf("Fila vazia!\n");*/
		} else if (operacao == 2) {
			escrever(inicio, fim, tamanho, fila);
		} else if (operacao != 3) {
			//printf("Operacao invalida!\n");
		}
	} while (operacao != 3);
}
//
/* 
 * Valor da questão: 2,0.
 * LEIA COM ATENÇÃO:
 * Este código implementa uma fila circular que executa em um vetor (alocação sequencial).
 *
 * Você deve implementar no código a seguir as funções responsáveis pela inserção
 * e remoção dos valores da fila (inserir e remover, respectivamente). O cabeçalho
 * das funções já se encontra proposto, de modo que não pode ser modificado.
 *
 * Ob.: É obrigatório o uso da fórmula matemática para implementar o comportamento circular da fila.
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Insere um elemento na fila.
 * 
 * @param inicio 
 *	aponta para a posicao onde esta o primeiro elemento da fila.
 * @param fim 
 *	aponta para a posicao onde esta o ultimo elemento da fila.
 * @param tamanho 
 *	tamanho maximo da fila.
 * @param fila 
 *	fila na qual o elemento sera inserido.
 * @param elemento 
 *	elemento a ser inserido.
 * @return 
 *	a posicao de insercao, ou -1 caso esteja cheia.
 */
int inserir(int * inicio, int * fim, int tamanho, int fila[], int elemento) {
    if (((*fim + 1) % tamanho) == *inicio) {
        return -1; // queue is full
    } else if (*inicio == -1) { // queue is empty
        *inicio = 0;
        *fim = 0;
        fila[*fim] = elemento;
    } else if (*fim == tamanho - 1 && *inicio != 0) {
        *fim = 0;
        fila[*fim] = elemento;
    } else {
        (*fim)++;
        fila[*fim] = elemento;
    }
    return *fim;
}

/**
 * Remove um elemento da fila.
 * 
 * @param inicio
 *	aponta para a posicao onde esta o primeiro elemento da fila.
 * @param fim
 *	aponta para a posicao onde esta o ultimo elemento da fila.
 * @param tamanho
 *	tamanho maximo da fila.
 * @param fila
 *	fila na qual o elemento sera inserido.
 * @return
 *	elemento removido, ou NULL caso a fila esteja vazia.
 */
int * remover(int * inicio, int * fim, int tamanho, int fila[]) {
    if (*inicio == -1) {
        return NULL; // queue is empty
    }
    int * elemento = &fila[*inicio];
    if (*inicio == *fim) {
        *inicio = -1;
        *fim = -1;
    } else if (*inicio == tamanho - 1) {
        *inicio = 0;
    } else {
        (*inicio)++;
    }
    return elemento;
}



/**
 * Escreve a fila.
 * 
 * @param inicio
 *	indice onde esta o primeiro elemento da fila.
 * @param fim
 *	indice onde esta o ultimo elemento da fila.
 * @param tamanho
 *	tamanho maximo da fila.
 * @param fila
 *	fila que sera impressa.
 */
void escrever(int inicio, int fim, int tamanho, int fila[]) {
    if (inicio != -1) {
        char s[] = "<---- inicio ";
        char s2[] = "<---- fim";
        while (inicio != fim) {
            printf("|%5d|", fila[inicio]);
            printf("%s", s);
            s[0] = '\0';
            printf("\n-------\n");
            inicio = ((inicio) + 1) % tamanho;
        }
        printf("|%5d|", fila[inicio]);
        printf("%s", s);
        printf("%s", s2);
        printf("\n-------\n");
    } else {
        printf("-------\n");
        printf("-------\n");
        printf("Fila vazia!\n");
    }
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);
    int fila[tamanho];
    int operacao;
    int elemento;
    int inicio = -1;
    int fim = -1;

    do {
        scanf("%d", &operacao);

        if (operacao == 0) {
            scanf("%d", &elemento);
            int retorno = inserir(&inicio, &fim, tamanho, fila, elemento);
        } else if (operacao == 1) {
            int * retorno = remover(&inicio, &fim, tamanho, fila);
        } else if (operacao == 2) {
            escrever(inicio, fim, tamanho, fila);
        } else if (operacao != 3) {
            //printf("Operacao invalida!\n");
        }
    } while (operacao != 3);

    return 0;
}