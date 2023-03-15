#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Declare any variables you need
    int sum = 0;

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
            sum += strlen(argv[i]);
            exit(sum);
        }
    }

    // Parent process
    // On the next page, finish the code to sum up
    // the return values from the child processes
    int x;
    for (int i = 1; i < argc; i++) {
        wait(&x);
        sum += WEXITSTATUS(x);
    }

    printf("The length of all the args is %d\n", sum);
    return 0;
}