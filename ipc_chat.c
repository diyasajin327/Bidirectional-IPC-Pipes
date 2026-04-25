#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2]; // Parent to Child
    int pipe2[2]; // Child to Parent
    pid_t pid;
    char msg1[100], msg2[100];

    // Create pipes
    pipe(pipe1);
    pipe(pipe2);

    pid = fork();

    if (pid > 0) {
        // Parent Process
        close(pipe1[0]); // Close read end
        close(pipe2[1]); // Close write end

        printf("Parent: Enter message for child: ");
        fgets(msg1, 100, stdin);

        write(pipe1[1], msg1, strlen(msg1) + 1);

        read(pipe2[0], msg2, sizeof(msg2));
        printf("Parent received: %s", msg2);

    } else if (pid == 0) {
        // Child Process
        close(pipe1[1]); // Close write end
        close(pipe2[0]); // Close read end

        read(pipe1[0], msg1, sizeof(msg1));
        printf("Child received: %s", msg1);

        printf("Child: Enter reply to parent: ");
        fgets(msg2, 100, stdin);

        write(pipe2[1], msg2, strlen(msg2) + 1);
    }

    return 0;
}