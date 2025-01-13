#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child_pid;

    for (int i = 0; i <= 2; i++) {
        pid = fork();
        if (child_pid == 0) { 
            printf("Child %d: PID = %d\n", i+1, getpid());
            _exit(0);
        } else if (child_pid < 0) {
            printf("Fork failed");
            return 1;
        }
    }

    return 0;
}
