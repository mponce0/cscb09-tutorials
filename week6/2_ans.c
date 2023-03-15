#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Declare any variables you need
    int sum = 0;
    int fd[2];

    if (pipe(fd) < 0) {
        printf("Bad pipe!\n");
    }

    // Write the code to loop over the command line arguments
    // (Remember to skip the executable name)
    for (int i = 1; i < argc; i++) {
        // call fork
        int r = fork();
        if (r < 0) { // System call error
            // Handle the error
            printf("Unable to print\n");
        } else if (r == 0) { // Child process
            // Child process does work here
            close(fd[0]);
            sum += strlen(argv[i]);
            write(fd[1], &sum, sizeof(sum));
            exit(0);
        }
    }

    // Parent process
    // On the next page, finish the code to sum up
    // the return values from the child processes
    int x;
    for (int i = 1; i < argc; i++) {
        read(fd[0], &x, sizeof(int));
        sum += x;
    }

    printf("The length of all the args is %d\n", sum);
    return 0;
}