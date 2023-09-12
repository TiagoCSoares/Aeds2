#include <stdio.h>

int main() {

    int m1[3][3] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    int m2[3][3] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    int m3[3][3];
    int *p1 = &m1[0][0];
    int *p2 = &m2[0][0];
    int *p3 = &m3[0][0];

    for(int i = 0; i < 9; i++){
        *(p3 + i) = *(p2 + i) * *(p1 + i);    
    }

    for(int i = 0; i < 9; i++){
            printf("%d\n", *(p3 + i));
    }

    return 0;
}