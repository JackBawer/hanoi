#include "hanoi.h"

// Global variable to keep track of the number of moves performed
unsigned long move_count;

/**
 * 
 * This function moves 'n' disks from the source peg to the destination peg
 * using an auxiliary peg, following the Tower of Hanoi rules.
 * 
 * @param n    Number of disks to move
 * @param src  Character representing the source peg
 * @param dest Character representing the destination peg
 * @param aux  Character representing the auxiliary peg
 */
void hanoi_recursive(int n, char src, char dest, char aux) {
    // Base case: If no disks to move, simply return
    if (n == 0){
        return;
    } 

    // Step 1: Move n-1 disks from source to auxiliary peg
    hanoi_recursive(n - 1, src, aux, dest);

    // Step 2: Move the nth (largest) disk from source to destination
    // Increment the global move counter
    move_count++;

    // Step 3: Move the n-1 disks from auxiliary peg to destination peg
    hanoi_recursive(n - 1, aux, dest, src);
}

