#include <stdio.h>

void lie(int *ages, int size) {
    for (int i = 0; i < size; i++) {
        ages[i] += 1;
        // *(ages + i) += 1;
    }
}

int main() {
    int *ages = {1, 2, 3, 4, 5};
    printf("%ld\n", sizeof(ages) / sizeof(int));
    lie(ages, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", ages[i]);
    }

    return 0;
}