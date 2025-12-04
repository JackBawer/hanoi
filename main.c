#include <stdio.h>
#include <time.h>
#include "hanoi.h"

/**
 * Main program to benchmark recursive and iterative Tower of Hanoi algorithms.
 *
 * Measures execution time and counts the number of moves for several values of n.
 */
int main() {
    // Array of disk counts to test
    int tests[] = {1, 3, 5, 10, 12, 14, 16, 18, 20, 22, 24, 25};
    int count = sizeof(tests) / sizeof(tests[0]);

    // Print table header
    printf("+------+---------------------+---------------------+----------------+\n");
    printf("|  n   |   rec time (s)      |   iter time (s)     |  move count    |\n");
    printf("+------+---------------------+---------------------+----------------+\n");

    // Loop over each test case
    for (int i = 0; i < count; i++) {
        int n = tests[i];

        // ---------------------------
        // Recursive method benchmark
        // ---------------------------
        move_count = 0;                 // reset global move counter
        clock_t r1 = clock();           // start timer
        hanoi_recursive(n, 'A', 'C', 'B');
        clock_t r2 = clock();           // end timer
        double trec = (double)(r2 - r1) / CLOCKS_PER_SEC;  // compute elapsed time
        unsigned long moves = move_count;                 // store number of moves

        // ---------------------------
        // Iterative method benchmark
        // ---------------------------
        move_count = 0;                 // reset move counter
        clock_t i1 = clock();           // start timer
        hanoi_iterative(n, 'A', 'B', 'C');
        clock_t i2 = clock();           // end timer
        double titer = (double)(i2 - i1) / CLOCKS_PER_SEC; // compute elapsed time

        // Print result row for this test case
        printf("| %4d |     %10.6f      |     %10.6f      | %14lu |\n",
               n, trec, titer, moves);
    }

    // Print table footer
    printf("+------+---------------------+---------------------+----------------+\n");

    return 0;
}

