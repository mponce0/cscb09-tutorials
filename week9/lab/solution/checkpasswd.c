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
    char *args[] = {"./validate", NULL};
    int fd[2];

    int p = pipe(fd);
    if (p < 0) perror("pipe");

    int f = fork();
    if (f < 0) {
        perror("fork");

    } else if (f == 0) {
        // child
        if (dup2(fd[STDIN_FILENO], STDIN_FILENO) == -1) perror("dup2");
        close(fd[STDOUT_FILENO]);
        execv("./validate", args);
        perror("exec");
    }

    // parent
    close(fd[STDIN_FILENO]);

    char userid[10];
    char password[10];
    /* Read a user id and password from stdin */
    printf("User id:\n");
    scanf("%s", userid);
    printf("Password:\n");
    scanf("%s", password);

    write(fd[STDOUT_FILENO], userid, sizeof(userid));
    write(fd[STDOUT_FILENO], password, sizeof(password));

    // parent
    int status;
    wait(&status);
    status = WEXITSTATUS(status);
    
    if (status == 0) {
        printf("Password verified\n");
    } else if (status == 2) {
        printf("Invalid password or no such user\n");
    } else {
        perror("validate");
    }

    return 0;
}
