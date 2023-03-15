#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

char name[10];
int finished = 0;

void sing(int signum) {
    printf("happy birthday %s\n", name);
    sleep(10);
    finished = 1;
    return;
}

void leave(int signum) {
    while (!finished);
    exit(0);
}

int main(int argc, char *argv[]) {
    strcpy(name, argv[1]);

    struct sigaction act;
    act.sa_handler = sing;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);

    struct sigaction act2;
    act2.sa_handler = leave;
    act2.sa_flags = 0;
    sigemptyset(&act2.sa_mask);
    sigaction(SIGINT, &act2, NULL);

    while (1);
}