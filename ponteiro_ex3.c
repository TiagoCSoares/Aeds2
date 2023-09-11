#include <stdio.h>

int main() {
    int v[5];
    int *p = &v[0];

    for(int i = 0; i < 5; i++){
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", (p+i));
        v[i] = *(p + i);
    }

    for(int i = 0; i < 5; i++){
        printf("arr[%d]: %d\n", (i), *(p + i));
    }


    return 0;
}