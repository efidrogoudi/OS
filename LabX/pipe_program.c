#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];
    
    if (pipe(pipefd) == -1) {
        printf("Pipe failed");
        return 1;
    }

    pid = fork();
    
    if (pid < 0) {
        printf("Fork failed");
        return 1;
    }
    
    if (pid == 0) { 
        close(pipefd[1]); 
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else { 
        close(pipefd[0]); 
        char message[] = "Hello from parent";
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
        wait(NULL); 
    }
    
    return 0;
}
