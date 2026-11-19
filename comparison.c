#include <stdio.h>
#include <omp.h>

#define N 1000000

int main() {
    int thread_counts[] = {1, 2, 4, 8};

    for (int t = 0; t < 4; t++) {
        int threads = thread_counts[t];
        int counter;
        double start, end;

        counter = 0;
        start = omp_get_wtime();

        #pragma omp parallel num_threads(threads)
        {
            for (int i = 0; i < N; i++) {
                #pragma omp critical
                counter++;
            }
        }

        end = omp_get_wtime();

        printf("Threads: %d | Critical: %.6f seconds | Result: %d\n",
               threads, end - start, counter);

        counter = 0;
        start = omp_get_wtime();

        #pragma omp parallel num_threads(threads)
        {
            for (int i = 0; i < N; i++) {
                #pragma omp atomic
                counter++;
            }
        }

        end = omp_get_wtime();

        printf("Threads: %d | Atomic: %.6f seconds | Result: %d\n\n",
               threads, end - start, counter);
    }

    return 0;
}
