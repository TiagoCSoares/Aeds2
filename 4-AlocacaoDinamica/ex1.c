//Nome: Tiago Costa Soares
//Matrícula: 2020.1.08.017


#include <stdio.h>
#include <stdlib.h>

int main() {


    int linhas, colunas;

    linhas = 3, colunas = 3;
    /*
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);
    */

    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; ++i) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }


    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            matriz[i][j] = i * colunas + j;
        }
    }


    printf("Matriz:\n");
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < linhas; ++i) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}