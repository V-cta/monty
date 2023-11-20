#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Global variable declaration */
char **opToks = NULL;

/**
 * main - The entry point for Monty Interpreter.
 *
 * @argc: The count of arguments passed to the program.
 * @argv: Pointer to an array of char pointers to arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char **argv)
{
    FILE *scriptFd = NULL;
    int exitCode = EXIT_SUCCESS;

    if (argc != 2)
        return (usageError());
    
    scriptFd = fopen(argv[1], "r");
    if (scriptFd == NULL)
        return (fOpenError(argv[1]));

    exitCode = runMonty(scriptFd);
    fclose(scriptFd);

    return (exitCode);
}
