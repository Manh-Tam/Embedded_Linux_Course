#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        //child process
        printf("Hello from child! PID = %d\n", getpid());
        sleep(2);
        printf("Child exiting.\n");
        exit(42); //exit code
    }
    else
    {
        //parent process
        int status;
        printf("Hello from parent! PID = %d, child PID = %d\n", getpid(), pid);
        printf("Parent waiting for child...\n");
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}