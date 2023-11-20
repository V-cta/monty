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

int popError(unsigned int lineNumber)
{
    return showError("L%u: can't pop an empty stack\n", lineNumber);
}

int pintError(unsigned int lineNumber)
{
    return showError("L%d: can't pint, stack empty\n", lineNumber);
}

int shortStackError(unsigned int lineNumber, char *op)
{
    return showError("L%u: can't %s, stack too short\n", lineNumber, op);
}

int divError(unsigned int lineNumber)
{
    return showError("L%u: division by zero\n", lineNumber);
}

int pcharError(unsigned int lineNumber, char *message)
{
    return showError("L%u: can't pchar, %s\n", lineNumber, message);
}
