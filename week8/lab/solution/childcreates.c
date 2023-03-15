#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {

	int i;
	int n;
	int num_kids;

	if(argc != 2) {
		fprintf(stderr, "Usage: forkloop <numkids>\n");
		exit(1);
	}

	num_kids = atoi(argv[1]);

	for(i = 0; i < num_kids; i++) {
		// printf("%d\n", getpid());
		n = fork();
		if(n < 0) {
			perror("fork");
			exit(1);
		} else if (n > 0) break;

 		printf("%d -> ", getppid());
		fflush(stdout);

		if (i == num_kids - 1) printf("%d\n", getpid());
	}
	
	for (int i = 0; i < num_kids; i++) {
		int status;
		wait(&status);
	}

	return 0;
}
