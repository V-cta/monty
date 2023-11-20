#include <stdlib.h>

/* Function prototypes */
char *getIntString(int num);
unsigned int getAbsoluteValue(int);
int getNumBaseLength(unsigned int num, unsigned int base);
void fillNumBaseBuffer(unsigned int num, unsigned int base,
                       char *buff, int buff_size);

/**
 * getIntString - Converts an integer to a string.
 * @num: Number to convert to string.
 *
 * Return: Pointer to the newly created string. NULL if malloc fails.
 */
char *getIntString(int num)
{
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *result;

    temp = getAbsoluteValue(num);
    length = getNumBaseLength(temp, 10);

    if (num < 0 || num_l < 0)
        length++; /* negative sign */
    result = malloc(length + 1); /* create a new string */
    if (!result)
        return NULL;

    fillNumBaseBuffer(temp, 10, result, length);
    if (num < 0 || num_l < 0)
        result[0] = '-';

    return result;
}

/**
 * getAbsoluteValue - Gets the absolute value of an integer.
 * @i: Integer to get the absolute value of.
 *
 * Return: Unsigned integer representing the absolute value of i.
 */
unsigned int getAbsoluteValue(int i)
{
    if (i < 0)
        return -(unsigned int)i;
    return (unsigned int)i;
}

/**
 * getNumBaseLength - Gets the length of buffer needed for an unsigned int.
 * @num: Number to get the length needed for.
 * @base: Base of number representation used by the buffer.
 *
 * Return: Integer containing the length of the buffer needed (doesn't contain null byte).
 */
int getNumBaseLength(unsigned int num, unsigned int base)
{
    int len = 1; /* all numbers contain at least one digit */

    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return len;
}

/**
 * fillNumBaseBuffer - Fills the buffer with correct numbers up to base 36.
 * @num: Number to convert to a string given the base.
 * @base: Base of the number used in conversion (works up to base 36).
 * @buff: Buffer to fill with the result of conversion.
 * @buff_size: Size of the buffer in bytes.
 *
 * Return: Always void.
 */
void fillNumBaseBuffer(unsigned int num, unsigned int base,
                       char *buff, int buff_size)
{
    int rem, i = buff_size - 1;

    buff[buff_size] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9) /* return lowercase ASCII val representation */
            buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
