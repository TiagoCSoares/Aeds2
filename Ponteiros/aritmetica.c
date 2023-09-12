#include <stdio.h>

int main() {

    int arr[5] = { 10, 20, 30, 40, 50};
    int *p = &arr[4];
    int j = 0;
    // Desconsiderando o ponteiro
    for (int i = 5; i > 0; i--){
        printf("arr[%d]: %d\n", (i-1), *(p - j));
        j++;
    }


    //for (int i = 0; i < 5; i++){
    //    printf("arr[%d]: %d\n", (4-i), *(p - i));
    //}

    return 1;
}