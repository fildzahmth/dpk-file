#include <stdio.h>

char papan[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void tampilkanPapan() {
    printf("\n");
    for (int baris = 0; baris < 3; baris++) {
        printf(" %c | %c | %c \n",
               papan[baris][0],
               papan[baris][1],
               papan[baris][2]);

        if (baris < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int cekMenang() {
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == papan[i][1] &&
            papan[i][1] == papan[i][2])
            return 1;

        if (papan[0][i] == papan[1][i] &&
            papan[1][i] == papan[2][i])
            return 1;
    }

    if (papan[0][0] == papan[1][1] &&
        papan[1][1] == papan[2][2])
        return 1;

    if (papan[0][2] == papan[1][1] &&
        papan[1][1] == papan[2][0])
        return 1;

    return 0;
}

int main() {
    int pilihan;
    int giliran = 1;
    char pemain;

    for (int langkah = 0; langkah < 9; ) {
        tampilkanPapan();

        pemain = (giliran == 1) ? 'X' : 'O';

        printf("Pemain %c, pilih kotak (1-9): ", pemain);

        if (scanf("%d", &pilihan) != 1) {
            printf("Masukkan angka saja!\n");

            while (getchar() != '\n');
            continue;
        }

        if (pilihan < 1 || pilihan > 9) {
            printf("Pilihan harus 1 sampai 9!\n");
            continue;
        }

        int baris = (pilihan - 1) / 3;
        int kolom = (pilihan - 1) % 3;

        if (papan[baris][kolom] == 'X' ||
            papan[baris][kolom] == 'O') {
            printf("Kotak sudah terisi! Pilih yang lain.\n");
            continue;
        }

        papan[baris][kolom] = pemain;
        langkah++;

        if (cekMenang()) {
            tampilkanPapan();
            printf("Pemain %c MENANG!\n", pemain);
            return 0;
        }

        giliran = (giliran == 1) ? 2 : 1;
    }

    tampilkanPapan();
    printf("Permainan SERI!\n");

    return 0;
}