#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 2000
#define MAXD 42

int tab[N][N];

void asp() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (i != k) {
                for (int j = 0; j < N; ++j) {
                    int tmp = tab[i][k] + tab[k][j];
                    if (tmp < tab[i][j]) {
                        tab[i][j] = tmp;
                    }
                }
            }
        }
    }
}

void asp_parallel() {
#pragma omp parallel for
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (i != k) {
                for (int j = 0; j < N; ++j) {
                    int tmp = tab[i][k] + tab[k][j];
                    if (tmp < tab[i][j]) {
                        tab[i][j] = tmp;
                    }
                }
            }
        }
    }
}

void test(const char* func_name, void f()) {
    // populate matrix with random numbers
    for (size_t i = 0; i < N - 1; i++) {
        for (size_t j = 0; j < N - 1; j++) {
            if (j == i)
                tab[i][j] = 0;
            else
                tab[i][j] = 1 + rand() % MAXD;
        }
    }

    clock_t start = clock();
    f();
    clock_t end = clock();
    printf("%s: %fs\n", func_name, ((double) end - start) / CLOCKS_PER_SEC);

}

int main(void) {
    time_t t;
    srand((unsigned) time(&t));

    test("asp", asp);
    test("asp_parallel", asp_parallel);

    return 0;
}
