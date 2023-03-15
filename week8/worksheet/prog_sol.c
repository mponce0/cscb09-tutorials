#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Declare any new variables you need
    int fd[argc][2];

    // Write code to loop over command line arguments
    for (int i = 1; i < argc; i++) {
        // Before we call fork, call pipe
        int p = pipe(fd[i]);

        int result = fork();
        if (result < 0) {
            perror("fork");
            exit(1);
        } else if (result == 0) { // child process
            // Child only writes to the pipe, so close reading end
            close(fd[i][0]);

            // Before we forked, parent had open the reading ends to
            // all previously forked children, so close those
            for (int j = 1; j < argc; j++) {
                if (j != i) {
                    close(fd[j][0]);
                }
            }

            // Now do the work - write the value in binary to the pipe
            int len = strlen(argv[i]);
            write(fd[i][1], &len, sizeof(int));

            // Close the pipe since we are doing with it
            close(fd[i][1]);

            exit(0); // Don't fork children on next loop iteration
        } else {
            // In the parent, but before doing the next loop iteration,
            // close the end of the pipe that we don't want open
            close(fd[i][1]);
        }
    }

    // Only the parent gets here
    int sum = 0;
    // Read one integer from each child, print it and add to sum
    for (int i = 1; i < argc; i++) {
        int val;
        read(fd[i][0], &val, sizeof(val));
        sum += val;
    }

    printf("The length of all the args is %d\n", sum);
    return 0;
}