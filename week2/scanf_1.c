#include <stdio.h>

int main(int argc, char *argv[]) {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int index = 0, value = 0;

    while (index != -1 && value != -1) {
        scanf("%d %d", &index, &value);
        arr[index] += value;
        for (int i = 0; i < 10; i++) printf("%d: %d\n", i, arr[i]);
    }
}