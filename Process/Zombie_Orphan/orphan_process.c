// orphan.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // Child: sleep and show parent PID repeatedly
        for (int i = 0; i < 10; i++) {
            printf("Child (PID = %d), parent PID = %d\n", getpid(), getppid());
            sleep(2);
        }
    } 
    else {
        // Parent exits immediately
        printf("Parent (PID = %d) exiting, child becomes orphan.\n", getpid());
        exit(0);
    }

    return 0;
}
