#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sing(int sig) {
    printf("Singing\n");
}

int main(int argc, char *argv[]) {
    struct sigaction act;
    act.sa_handler = sing;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act, NULL);

    while(1);
}