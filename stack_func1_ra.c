#include "monty.h"

/**
 * print_stack - ths is to adds node to stacks.
 * @line_number: this is int type line number of opcodeee.
 * @stack: this is pointer that pointing to top node of stacks.
 *
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
(void) line_number;
if (stack == NULL)
exit(EXIT_FAILURE);
tmp = *stack;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}
/**
 * print_top - this function is to Print top node of stacks.
 * @line_number: this is int type & representing line numberr of opcodee.
 * @stack: this is pointer to that pointing to top node of stacks.
 *
 */
void print_top(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL)
more_err(6, line_number);
printf("%d\n", (*stack)->n);
}
/**
 * pop_top - this function is to add node to stacks.
 * @line_number: this is int type Interger representing line number of opcodee.
 * @stack: this is Pointer that pointing to top node of stacks.
 *
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL)
more_err(7, line_number);
tmp = *stack;
*stack = tmp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(tmp);
}
/**
 * add_to_stack - this function is to add node to stacks.
 * @ln: Interger thisis int type and representing line number of opcodee.
 * @new_node: this is pointer that points to new nodee.
 *
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;
if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *new_node;
return;
}
tmp = head;
head = *new_node;
head->next = tmp;
tmp->prev = head;
}
