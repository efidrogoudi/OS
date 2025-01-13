#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int file = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file < 0) {
        printf("File open failed");
        return 1;
    }
    
    pid_t pid = fork();
    
    if (pid < 0) {
        printf("Fork failed");
        return 1;
    }
    
    if (pid == 0) {
        dprintf(file, "Child PID: %d\n", getpid());
        close(file);
        exit(0);
    } else {
        dprintf(file, "Parent PID: %d\n", getpid());
        close(file);
        wait(NULL);
    }
    
    return 0;
}
