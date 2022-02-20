#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <memory.h>

int main()
{
    printf("[parent] pid %d\n", getpid(), getppid());
    for (int i = 0; i < 5; i++)
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
            printf("[son] pid %d\n", getpid());
            break;
        }
    }
    return 0;
}
