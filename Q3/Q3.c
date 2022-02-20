#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <memory.h>

int main()
{
    int fd1[2];
    int fd2[2];
    if (pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        fprintf(stderr, "Program failed while piping\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "Program failed while forking\n");
        return 2;
    }
    else if (id == 0)
    {
        //_*_child process_*_

        // Recieve string from parent
        char string2[501];
        int ppid = getppid();
        int *s = &ppid;
        wait(s);
        read(fd1[0], string2, sizeof(string2));
        close(fd1[0]);
        close(fd1[1]);

        // modifying string to uppercase
        int i;
        for (i = 0; string2[i] < sizeof(string2); i++)
        {
            if (string2[i] >= 'a' && string2[i] <= 'z')
            {
                string2[i] = string2[i] - 32;
            }
        }

        // Sending back modified string to parent process
        write(fd2[1], string2, sizeof(string2));
        close(fd2[1]);
        close(fd2[0]);
    }
    else
    {
        //_*_parent process_*_
        char string1[501];
        scanf("%[^\n]%*c", string1);
        write(fd1[1], string1, sizeof(string1));
        close(fd1[1]);
        close(fd1[0]);

        wait(NULL);
        memset(string1, 0, sizeof(string1));

        // receiving back modified string1
        read(fd2[0], string1, sizeof(string1));
        close(fd2[0]);
        close(fd2[1]);
        printf("%s\n", string1);
    }
    return 0;
}