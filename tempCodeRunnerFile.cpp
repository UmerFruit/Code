#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void execute_command(const char *command, char *const args[]) {
    // Using execl
    execl("/bin/sh", "sh", "-c", command, NULL);
    
    // Using execlv
    //execlv("/bin/sh", "sh", "-c", command, args);
    
    // Using execv
    //execv("/bin/sh", args);
    
    // Using execvp
    //execvp("", args);
    
    // If execl/execv/execvp fails, it will reach this line
    perror("exec failed");
    exit(EXIT_FAILURE);
}

int main() {
    // Example usage
    const char *command = "ls -l";
    char *const args[] = { "ls", "-l", NULL };

    execute_command(command, args);
    
    return 0;
}
