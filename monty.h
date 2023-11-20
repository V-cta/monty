#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **opToks;

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void freeStack(stack_t **stack);
int initStack(stack_t **stack);
int checkMode(stack_t *stack);
void freeTokens(void);
unsigned int tokenArrLen(void);
int runMonty(FILE *scriptFd);
void setOpTokError(int errorCode);

/* OPCODE FUNCTIONS */
void montyPush(stack_t **stack, unsigned int line_number);
void montyPall(stack_t **stack, unsigned int line_number);
void montyPint(stack_t **stack, unsigned int line_number);
void montyPop(stack_t **stack, unsigned int line_number);
void montySwap(stack_t **stack, unsigned int line_number);
void montyAdd(stack_t **stack, unsigned int line_number);
void montyNop(stack_t **stack, unsigned int line_number);
void montySub(stack_t **stack, unsigned int line_number);
void montyDiv(stack_t **stack, unsigned int line_number);
void montyMul(stack_t **stack, unsigned int line_number);
void montyMod(stack_t **stack, unsigned int line_number);
void montyPchar(stack_t **stack, unsigned int line_number);
void montyPstr(stack_t **stack, unsigned int line_number);
void montyRotl(stack_t **stack, unsigned int line_number);
void montyRotr(stack_t **stack, unsigned int line_number);
void montyStack(stack_t **stack, unsigned int line_number);
void montyQueue(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strToW(char *str, char *delims);
char *getInt(int n);

/* ERROR MESSAGES & ERROR CODES */
int usageError(void);
int mallocError(void);
int fOpenError(char *filename);
int unknownOpError(char *opcode, unsigned int line_number);
int noIntError(unsigned int line_number);
int popError(unsigned int line_number);
int pintError(unsigned int line_number);
int shortStackError(unsigned int line_number, char *op);
int divError(unsigned int line_number);
int pcharError(unsigned int line_number, char *message);

#endif /* __MONTY_H__ */
