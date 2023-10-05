/* 
 * Valor da questão: 4,0.
 * LEIA COM ATENÇÃO:
 * Este código implementa uma lista duplamente encadeada em ordem crescente,
 * com uso de nó cabeça e nó cauda.
 *
 * Ou seja, cada nó possui ponteiros para o anterior e o próximo; e existem
 * dois nós especiais (no início e final da lista) com as funções de serem
 * nó cabeca e nó cauda. Inicialmente, a lista estará com a seguinte estrutura:
 * 
 * cabeca* --> no|*ant = NULL, *prox = cauda|
 * cauda* --> no|*ant = cabeca, *prox = NULL|
 *
 * Após inserir o primeiro nó, a estrutura ficará da seguinte forma:
 
 * cabeca* --> no|*ant = NULL, *prox = novo_no|
 * novo_no|*ant = cabeca, *prox = cauda|
 * cauda* --> no|*ant = novo_no, *prox = NULL
 * 
 * Você deve implementar no código a seguir as funções responsáveis pela inserção
 * e remoção dos valores da lista (inserir e remover, respectivamente). O cabeçalho
 * das funções já se encontra proposto, de modo que não pode ser modificado.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no_ no;

struct no_ {
	int valor;
	no * ant;
	no * prox;
};

/**
 * Insere o valor na lista.
 * @param cabeca = endereco do no cabeca.
 * @param cauda = endereco do no cauda.
 * @param valor = valor a ser inserido.
 * @return 1 caso seja possivel inserir, e 0 caso contrario.
 */
int inserir(no * cabeca, no * cauda, int valor) {
    
	 no * novo = (no*) malloc(sizeof(no));
    if (novo == NULL) {
        // Memory allocation failed
        return 0;
    }
    novo->valor = valor;

    no * atual = cabeca->prox;
    while (atual != cauda && atual->valor < valor) {
        atual = atual->prox;
    }

    novo->ant = atual->ant;
    novo->prox = atual;
    atual->ant->prox = novo;
    atual->ant = novo;

    return 1;
}

/**
 * Remove um no da lista.
 * @param cabeca = endereco do no cabeca.
 * @param cauda = endereco do no cauda.
 * @param valor = valor a ser removido.
 * @return = ponteiro para o no removido, ou NULL caso nao seja possivel remover.
 */
no * remover(no * cabeca, no * cauda, int valor) {

	no * atual = cabeca->prox;
    while (atual != cauda && atual->valor != valor) {
        atual = atual->prox;
    }

    if (atual == cauda) {
        // Node not found
        return NULL;
    }

    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;

    return atual;
}

/**
 * Escreve a lista no sentido cabeca -> cauda.
 * @param cabeca = endereco do no cabeca.
 * @param cauda = endereco do no cauda.
 */
void escrever(no * cabeca, no* cauda) {
	printf("[");
	no * atual = cabeca->prox;

	while (atual != cauda) {
		printf("%d", atual->valor);
		if (atual->prox != cauda)
			printf(" --> ");

		atual = atual->prox;
	}
	printf("]\n\n");
}

/**
 * Escreve a lista no sentido cauda -> cabeca.
 * @param cabeca = endereco do no cabeca.
 * @param cauda = endereco do no cauda.
 */
void escrever_reverso(no * cabeca, no* cauda) {
	printf("[");
	no * atual = cauda->ant;

	while (atual != cabeca) {
		printf("%d", atual->valor);
		if (atual->ant != cabeca)
			printf(" --> ");

		atual = atual->ant;
	}
	printf("]\n\n");
}

/**
 * Desaloca a lista.
 * @param cabeca = endereco do no cabeca.
 */
void desaloca_lista(no * cabeca){
	while(cabeca != NULL){
		no * n = cabeca;
		cabeca = cabeca->prox;
		free(n);
	}
}

/**
 * Aloca os nos cabeca e cauda.
 * @param cabeca = endereco do ponteiro do no cabeca.
 * @param cauda = endereco do ponteiro do no cauda.
 */
void aloca_nos_cabeca_cauda(no** cabeca, no** cauda){
	*cabeca = (no*) malloc(sizeof(no));
	* cauda = (no*) malloc(sizeof(no));
	(*(*cabeca)).prox = (*cauda);
	(*(*cabeca)).ant = NULL;


	(*(*cauda)).ant = (*cabeca);
	(*(*cauda)).prox = NULL;
}

int main() {
	no * cabeca;
	no * cauda;
	aloca_nos_cabeca_cauda(&cabeca, &cauda);
	
	no * n;
	
	int valor;
	int ans = 0;

	do {
		/*printf("======================= \n");
		printf("Informe operacao: \n");
		printf("0 --> inserir \n");
		printf("1 --> remover \n");
		printf("2 --> escrever \n");
		printf("3 --> escrever reverso\n");
		printf("4 --> sair \n");
		printf("======================= \n");*/
		scanf("%d", & ans);

		switch (ans) {
			case 0:
				//printf("Informe o valor a ser inserido: ");
				scanf("%d", &valor);
				if (inserir(cabeca, cauda, valor)) {
					//printf("Valor inserido.\n\n");
				} else {
					//printf("Valor nao inserido.\n\n");
				}

				break;
			case 1:
				//printf("Informe o valor a ser removido: ");
				scanf("%d", &valor);

				n = remover(cabeca, cauda, valor);
				if (n != NULL) {
					//printf("Valor removido: %d.\n\n", n->valor);
					free(n);
				} else {
					//printf("Valor inexistente.\n\n");
				}

				break;
			case 2:
				escrever(cabeca, cauda);
				
				break;
			case 3:
				escrever_reverso(cabeca, cauda);
				
				break;
			case 4:
				desaloca_lista(cabeca);
				
				break;
			default:
				//printf("Opcao invalida.\n");
				
				break;
		}
	} while (ans != 4);

	return (EXIT_SUCCESS);
}