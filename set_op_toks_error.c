#include "monty.h"

/**
 * set_op_tok_error - Sets the last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
    int toks_len = 0, i = 0;
    char *error_code_str = NULL;
    char **new_toks = NULL;

    // Check if op_toks is NULL
    if (!op_toks)
    {
        malloc_error();
        return;
    }

    toks_len = token_arr_len();

    // Allocate memory for the new array
    new_toks = malloc(sizeof(char *) * (toks_len + 2));

    // Check if memory allocation fails
    if (!new_toks)
    {
        malloc_error();
        return;
    }

    // Copy existing tokens to the new array
    while (i < toks_len)
    {
        new_toks[i] = op_toks[i];
        i++;
    }

    // Convert error code to string
    error_code_str = get_int(error_code);

    // Check if get_int fails
    if (!error_code_str)
    {
        free(new_toks);
        malloc_error();
        return;
    }

    // Add the error code string to the new array
    new_toks[i++] = error_code_str;
    new_toks[i] = NULL;

    // Free the old op_toks and update it with the new array
    free(op_toks);
    op_toks = new_toks;
}
