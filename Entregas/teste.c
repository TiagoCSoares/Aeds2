#include <stdio.h>


int tamanhoString(const char *str) {
    int tamanho = 0;

    while (str[tamanho] != '\0') {
        tamanho++;
    }

    return tamanho;
}

int main() {

    char lakaka[20];

    scanf("%s", &lakaka);


    int tamanho = tamanhoString(lakaka);
    printf("\n%d\n", tamanho);




    //printf("%s", lakaka);

    return 0;
}