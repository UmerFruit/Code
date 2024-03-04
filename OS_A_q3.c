#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TEXT_LENGTH 1000

int main() {
    char text[MAX_TEXT_LENGTH];

    // Prompt user to enter text for spell checking
    printf("Enter text for spell checking: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    // Create a pipe for inter-process communication
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork to create a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        // Close the write end of the pipe
        close(pipefd[1]);

        // Redirect stdin to read from the pipe
        dup2(pipefd[0], STDIN_FILENO);

        // Execute the spell checking program (replace "spell_checker" with actual spell checker program)
        execl("./spell_checker", "spell_checker", NULL);
        perror("exec");
        exit(EXIT_FAILURE);
    } else { // Parent process
        // Close the read end of the pipe
        close(pipefd[0]);

        // Write user input to the pipe
        write(pipefd[1], text, MAX_TEXT_LENGTH);

        // Close the write end of the pipe
        close(pipefd[1]);

        // Wait for the child process to finish
        int status;
        waitpid(pid, &status, 0);

        // Read spelling errors reported by the child process
        char errors[MAX_TEXT_LENGTH];
        read(pipefd[0], errors, MAX_TEXT_LENGTH);

        // Close the read end of the pipe
        close(pipefd[0]);

        // Display original user input along with identified spelling errors
        printf("\nOriginal text:\n%s\n", text);
        printf("\nSpelling errors:\n%s\n", errors);
    }

    return 0;
}
