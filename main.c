#include <stdio.h>
#include <time.h>
#include "hanoi.h"

int main() {
    int tests[] = {1, 3, 5, 10, 12, 14, 16, 18, 20, 22, 24, 25};
    int count = sizeof(tests) / sizeof(tests[0]);

    printf("+------+---------------------+---------------------+----------------+\n");
    printf("|  n   |   rec time (s)      |   iter time (s)     |  move count    |\n");
    printf("+------+---------------------+---------------------+----------------+\n");

    for (int i = 0; i < count; i++) {
        int n = tests[i];

        move_count = 0;
        clock_t r1 = clock();
        hanoi_recursive(n, 'A', 'C', 'B');
        clock_t r2 = clock();
        double trec = (double)(r2 - r1) / CLOCKS_PER_SEC;
        unsigned long moves = move_count;

        move_count = 0;
        clock_t i1 = clock();
        hanoi_iterative(n, 'A', 'B', 'C');
        clock_t i2 = clock();
        double titer = (double)(i2 - i1) / CLOCKS_PER_SEC;

        printf("| %4d |     %10.6f      |     %10.6f      | %14lu |\n",
               n, trec, titer, moves);
    }

    printf("+------+---------------------+---------------------+----------------+\n");
    return 0;
}
