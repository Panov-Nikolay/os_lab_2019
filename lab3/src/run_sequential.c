#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char **argv)
{
    char *child_argv[argc + 1];
    child_argv[0] = "./sequential_min_max";
    for (int i = 1; i < argc; i++)
        child_argv[i] = argv[i];
    child_argv[argc] = NULL;

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        execv("./sequential_min_max", child_argv);
        perror("execv");
        return 127;
    }

    int status;
    if (waitpid(pid, &status, 0) < 0) {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(status)) {
        printf("Дочерний процесс завершился с кодом %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Дочерний процесс убит сигналом %d\n", WTERMSIG(status));
    }

    return 0;
}