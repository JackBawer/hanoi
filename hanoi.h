#ifndef HANOI_H
#define HANOI_H

extern unsigned long move_count;

void hanoi_recursive(int n, char source, char dest, char aux);
void hanoi_iterative(int n, char source, char aux, char dest);

#endif
