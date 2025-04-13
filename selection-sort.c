#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void selection_sort(int *v, unsigned int n)
{
    int m, i, j;
    for (i = 0; i < (n-1); i++)
    {
        m = i;
        for (j = (i+1); j < n; j++)
        {
            if (v[m]>v[j])
            {
                m = j;
            }
        }
        int temp = v[m];
        v[m] = v[i];
        v[i] = temp;
    }
}

void print_array(int *v, unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}
    
int main(int argc, char **argv)
{
    struct timespec a, b;
    unsigned int t;
    
    unsigned int n = atoi(argv[1]);
    int i, *v;

    v = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        v[i] = n-i;
    }

    clock_gettime(CLOCK_MONOTONIC, &b);
    //print_array(v, n);
    selection_sort(v, n);
    //print_array(v, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}