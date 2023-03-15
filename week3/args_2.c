#include <stdio.h>

int main(int argc, char **argv) {
    char *num = argv[1];
    int numInt = atoi(num);

    if (numInt > 5) printf("Yikes\n");
    else printf("Yikes again\n");
}