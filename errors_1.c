#include "monty.h"

/* Function prototypes */
int showError(const char *format, ...);

/* Function definitions */
int showError(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    fprintf(stderr, "Error: ");
    vfprintf(stderr, format, args);

    va_end(args);

    return EXIT_FAILURE;
}

int usageError(void)
{
    return showError("USAGE: monty file\n");
}

int mallocError(void)
{
    return showError("malloc failed\n");
}

int fOpenError(char *filename)
{
    return showError("Can't open file %s\n", filename);
}

int unknownOpError(char *opcode, unsigned int lineNumber)
{
    return showError("L%u: unknown instruction %s\n", lineNumber, opcode);
}

int noIntError(unsigned int lineNumber)
{
    return showError("L%u: usage: push integer\n", lineNumber);
}
