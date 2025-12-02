#include "hanoi.h"

unsigned long long move_count;

void hanoi_recursive(int n, char src, char dest, char aux) {
    if (n == 0){
        return;
    } 

    hanoi_recursive(n - 1, src, aux, dest);

    move_count++;

    hanoi_recursive(n - 1, aux, dest, src);
}

