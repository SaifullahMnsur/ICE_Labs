#include <stdio.h>

void towerOfHanoi(int n, int from, int to, int aux)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from tower %d to tower %d\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
    return;
}

int main()
{
    int n = 4;
    int from = 3;
    int to = 2;
    printf("\n");
    towerOfHanoi(n, from, to, 1);
    return 0;
}
