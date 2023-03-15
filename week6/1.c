#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    printf("Mangoes\n"); // 1 process
    int r = fork();         // 2 processes
    printf("Apples\n");     // twice
    if (r == 0) { // 1 child process entering
        sleep(1);
        printf("Oranges\n");
        int k = fork();     // 2 processes
        if (k >= 0) {       // child and parent process entering
            printf("Bananas\n");    // twice
        }
    } else if (r > 0) {     // 1 parent process entering
        printf("Peaches\n");    // once
        for (i = 0; i < 3; i++) { // 3 iterations for one process
            if ((r = fork()) == 0) {    // 3 child processes entering
                printf("Pears\n");      // three times
                exit(0);
                printf("Nectarines\n");
            } else if (r > 0) {     // 3 parent processes entering
                printf("Plums\n");
            }
        }
    }   
} 