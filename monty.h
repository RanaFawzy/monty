#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked listt representation j stacks.
 * @next: points to next element of stacks (or queue)
 * @prev: points to  previous element of stacks (or queue),
 * @n: integerrr
 * Description: doubly linked listtt nodee structuress.
 *
 * for stack, queues, LIFO, FIFO,,,
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
#endif
