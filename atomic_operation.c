#include <stdio.h>
#include <omp.h>

int main() {
    int counter = 0;

    #pragma omp parallel num_threads(4)
    {
        for (int i = 0; i < 100000; i++) {
            #pragma omp atomic
            counter++;
        }
    }

    printf("Expected Counter: %d\n", 400000);
    printf("Actual Counter: %d\n", counter);

    return 0;
}
