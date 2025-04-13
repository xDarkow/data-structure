#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    struct timespec a, b;
    unsigned int t;

    clock_gettime(CLOCK_MONOTONIC, &b);
    sleep(1);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    return 0;
}