#include <stdio.h>

int main() {

    int v[5] = { 1, 3, 5, 7, 9}; //2 6 10 14 18
    int *p = &v[0];

    for(int i = 0; i < 5; i++){
        printf("arr[%d]*2: %d\n", (i), *(p + i)*2);
    }

    return 0;
}