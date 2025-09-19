// zombie.c
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
        // Child exits immediately
        printf("Child (PID = %d) exiting now.\n", getpid());
        exit(0);
    } 
    else {
        // Parent does not call wait()
        printf("Parent (PID = %d) sleeping... child becomes zombie.\n", getpid());
        sleep(60); // Keep parent alive to allow observation
    }

    return 0;
}
