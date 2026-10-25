#include <stdio.h>
#include <stdlib.h>

char C[3][3] = {{'x', 'o', 'x'}, {'o', 'x', 'o'}, {'x', 'o', 'x'}};

int main() {
    for (int baris = 0; baris < 3; baris++) {
        for (int kolom = 0; kolom < 3; kolom++) {
            printf("%c ", C[baris][kolom]);
        }
        printf("\n");
    }

    return 0;
}