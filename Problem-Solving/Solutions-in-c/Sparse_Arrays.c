#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, Q;
    char *N_array[1000], *Q_array[1000];
    scanf("%d", &N);
    for (int N_i = 0; N_i < N; N_i++) {
        char s[21];
        scanf("%s", s);
        N_array[N_i] = malloc(21);
        strcpy(N_array[N_i], s);
    }
    scanf("%d", &Q);

    for (int Q_i = 0; Q_i < Q; Q_i++) {
        int occurs = 0, result;
        char s[21];
        scanf("%s", s);
        Q_array[Q_i] = malloc(21);
        strcpy(Q_array[Q_i], s);
        for (int N_i2 = 0; N_i2 < N; N_i2++) {
            result = strcmp(Q_array[Q_i], N_array[N_i2]);
            if (result == 0) occurs++;
        }
        printf("%d\n", occurs);
    }

    return 0;
}

