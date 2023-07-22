#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
    char* input, shell_prompt[100] = "myshell $";

    // Configure readline to auto-complete paths when the tab key is hit.
    rl_bind_key('\t', rl_complete);

    for(;;) {
        // Create prompt string from user name and current working directory.
        // snprintf(shell_prompt, sizeof(shell_prompt), "%s:%s $ ", getenv("USER"), getcwd(NULL, 1024));

        // Display prompt and read input (n.b. input must be freed after use)...
        input = readline(shell_prompt);

        if (fork() == 0) {
            execv("/bin/cat", (char *[]){"/bin/cat", input, NULL});
        }
        // Check for EOF.
        // if (input == NULL)
        //     break;
        // if (access(input, R_OK) == 0)
        //     printf("%s : read ok\n", input);
        // else
        //     printf("%s : read fail\n", input);

        // if (access(input, F_OK) == 0)
        //     printf("%s : exist\n", input);
        // else
        //     printf("%s : not exists\n", input);

        // Add input to history.
        add_history(input);

        // Do stuff...

        // Free input.
        free(input);
    }
}