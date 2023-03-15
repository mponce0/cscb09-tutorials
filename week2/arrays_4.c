#include <stdio.h>

int main(int argc, char *argv) {
    int ages[] = {5, 7, 18, 20};

    for (int i = 0; i < 4; i++) {
        ages[i] += 1;
    }

    for (int i = 0; i < 4; i++) {
        printf("The element at index %d now has the value %d\n", i, ages[i]);
    }

    // for (int i = 4; i < 7; i++) ages[i] = 1000;

    // int x[] = {100, 2};
    // int *y = x+1;
    // printf("%d\n", y[-1]);

    return 0;
}