#include <stdio.h>
#include <omp.h>

int main() {

    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();

        printf("Thread %d reached before barrier\n", id);

        #pragma omp barrier

        printf("Thread %d crossed the barrier\n", id);
    }

    return 0;
}
