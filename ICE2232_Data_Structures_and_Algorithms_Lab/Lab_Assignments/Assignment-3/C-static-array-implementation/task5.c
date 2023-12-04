// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment - 3

// Task No: 5
// Solution by: Saifullah (ICE 21)

// Purpose of this static array implementation is to fix the capacity during compile time

#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux)
{
    if( n == 0 )
        return;
    towerOfHanoi(n-1, from, aux, to);
    printf("Move %d from %c to %c\n", n, from, to);
    towerOfHanoi(n-1, aux, to, from);
    return;
}

int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return;
}