#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct no_ no;
struct no_ {
  int valor;
  no * prox;
};

/**
 * 
 * @param cabeca = endereco do no cabeca.
 * @param valor = valor a ser inserido.
 * @return 1 caso seja possivel inserir, e 0 caso contrario.
 *
 */
int inserir(no * cabeca, int valor) {
    //TODO: implemente a funcao inserir.
    //O cabecalho da funcao nao pode ser alterado.
   
   no * novo = (no *)malloc(sizeof(no));
    if (novo == NULL) {
        return 0; // Falha na alocação de memória
    }

    novo->valor = valor;
    novo->prox = NULL;

    no * atual = cabeca->prox;
    if (atual == NULL) {
        cabeca->prox = novo;
    } else {
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }

    return 1; // Inserção bem-sucedida
}

/**
 * 
 * @param cabeca = endereco do no cabeca.
 * @param valor = valor a ser removido.
 * @return = ponteiro para o no removido, ou NULL caso nao seja possivel remover.
 */
no * remover(no * cabeca, int valor) {
    //TODO: implemente a funcao remover.
    //O cabecalho da funcao nao pode ser alterado.


         no * atual = cabeca->prox;
    no * anterior = cabeca;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return NULL; // Valor não encontrado
    }

    anterior->prox = atual->prox;
    free(atual);

    return anterior->prox;
}



/**
 * 
 * @param cabeca = endereco do no cabeca.
 */
void escrever(no * cabeca) {
	printf("[");
	no * atual = cabeca->prox;

	while (atual != NULL) {
		printf("%d", atual->valor);
		if (atual->prox != NULL)
			printf(" -> ");

		atual = atual->prox;
	}
	printf("]\n\n");
}

/**
 * 
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
 * 
 * @return = ponteiro para o no cabeca alocado.
 */
no* aloca_no_cabeca(){
	no * cabeca = (no*)malloc(sizeof(no));
	cabeca->prox = NULL;
	return cabeca;
}

int main()
{
	no * cabeca = aloca_no_cabeca();
	no * n;
	
	int valor;
	int ans = 0;

	do {
        //Opcoes:
		//0 -> inserir
		//1 -> remover
		//2 -> escrever
		//3 -> sair
		scanf("%d", & ans);

		switch (ans) {
            //inserir
			case 0:
				scanf("%d", &valor);
                inserir(cabeca, valor);

				break;
            //remover
			case 1:
				scanf("%d", &valor);
				n = remover(cabeca, valor);
				if (n != NULL) {
					free(n);
				}

				break;
            //escrever
			case 2:
				escrever(cabeca);
				
				break;
            //sair
			case 3:
				desaloca_lista(cabeca);
				
				break;
			default:
				
				break;
		}
	} while (ans != 3);

	return (0);
}
