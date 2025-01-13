#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void handle_signal(int sig) {
    printf("Child received signal: %d\n", sig);
}

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        printf("Fork failed");
        return 1;
    }
    
    if (pid == 0) {
        signal(SIGUSR1, handle_signal); 
        pause(); 
        exit(0);
    } else { 
        sleep(1); 
        kill(pid, SIGUSR1); 
        wait(NULL); 
    }
    
    return 0;
}
