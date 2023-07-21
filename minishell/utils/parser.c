#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
    char* input, shell_prompt[100] = "myshell $";

    // Configure readline to auto-complete paths when the tab key is hit.
    // rl_bind_key('\t', rl_complete);

    for(;;) {
        // Create prompt string from user name and current working directory.
        // snprintf(shell_prompt, sizeof(shell_prompt), "%s:%s $ ", getenv("USER"), getcwd(NULL, 1024));

        // Display prompt and read input (n.b. input must be freed after use)...
        input = readline(shell_prompt);

        // Check for EOF.
        if (input == NULL)
            break;

        // Add input to history.
        add_history(input);

        // Do stuff...
		printf("%s\n", input);

		size_t idx = 0;
		char

        // Free input.
        free(input);
    }
}