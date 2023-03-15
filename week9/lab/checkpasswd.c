#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Read a user id and password from standard input, 
   - create a new process to run the validate program
   - send validate the user id and password on a pipe, 
   - print a message 
        "Password verified" if the user id and password matched, 
        "Invalid password or no such user"
     depending on the return value of the validate program.
*/

int main() {
    // create file descriptors
    int fd[2];
    char *args[] = {"./validate", NULL};

    // create pipe
    int p = pipe(fd);
    if (p < 0) {
        perror("pipe");
        exit(1);
    }
    
    int f = fork();
    if (f < 0 ){
        perror("fork");
        exit(1);
    }

    // child
    if (f == 0) {
        // close child writing end
        close(fd[STDOUT_FILENO]);

        // duplicate stdin of child into pipe stdin
        int d = dup2(fd[STDIN_FILENO], STDIN_FILENO);
        if (d == -1) {
            perror("dup2");
            exit(1);
        }

        // run validate
        execv("./validate", args);
    }

    // anything here and forward is parent

    // close parent reading end
    close(fd[STDIN_FILENO]);

    char userid[10];
    char password[10];
    /* Read a user id and password from stdin */
    printf("User id:\n");
    scanf("%s", userid);
    printf("Password:\n");
    scanf("%s", password);

    // write to pipe set up for child stdin
    write(fd[STDOUT_FILENO], userid, sizeof(userid));
    write(fd[STDOUT_FILENO], password, sizeof(password));

    int status;
    wait(&status);

    // get exit status
    status = WEXITSTATUS(status);

    if (status == 1) {
        perror("read");
        exit(1);
    } else if (status == 2) {
        printf("Invalid password or no such user\n");
    } else if (status == 0) {
        printf("Password verified\n");
    }

    return 0;
}
