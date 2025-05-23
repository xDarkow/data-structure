#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int search(int *v, unsigned int n, int k)
{
    while (n-- > 0)
    {
        if (v[n] == k)
            return n;
    }
    return -1;
}

int main(int argc, char **argv)
{
    struct timespec a, b;
    unsigned int t;
    
    unsigned int n = atoi(argv[1]);
    int i, *v;

    v = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        v[i] = i;

    clock_gettime(CLOCK_MONOTONIC, &b);
    search(v, n, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}