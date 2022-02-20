#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <memory.h>

int main()
{
    int id = fork();
    if (id == -1)
    {
        fprintf(stderr, "Program failed while forking\n");
        return 1;
    }
    else if (id == 0)
    {
        //_*_child process_*_
        int pid_child = getpid();
        printf("This is child process with id : %d ", pid_child);
    }
    else
    {
        //_*_parent process_*_
        int pid = getpid();
        printf("This is Parent process with id : %d ", pid);
    }
    return 0;
}
