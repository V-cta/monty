#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Tokenizes a string into words.
 *
 * @str: String to tokenize.
 * @delims: Delimiters to use for word separation.
 *
 * Return: 2D array of pointers to each word.
 */
char **strtow(char *str, char *delims)
{
    char **words = NULL;
    int wc, wordLen, i = 0;

    if (str == NULL || !*str || delims == NULL)
        return NULL;

    wc = get_word_count(str, delims);

    if (wc == 0)
        return NULL;

    words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    while (i < wc)
    {
        wordLen = get_word_length(str, delims);
        if (is_delim(*str, delims))
            str = get_next_word(str, delims);

        words[i] = strdup(str); // Use strdup for simpler memory allocation
        if (words[i] == NULL)
        {
            while (i >= 0)
                free(words[i--]);
            free(words);
            return NULL;
        }

        str = get_next_word(str, delims);
        i++;
    }

    words[i] = NULL; // Last element is null for iteration
    return words;
}

// ... (Other functions remain unchanged)
