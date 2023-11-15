#include "monty.h"

/**
 * mod_nodes -ths is to  add top two elements of stacks.
 * @line_number: this is int type nrepresenting line number of opcodee.
 * @stack: this is Pointer that pointing to top node of stacks.
 *
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_err(8, line_number, "mod");
if ((*stack)->n == 0)
more_err(9, line_number);
(*stack) = (*stack)->next;
sum = (*stack)->n % (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * mul_nodes - this is to add top two elements of stacks.
 * @line_number: this is int type represent line number of opcodee.
 * @stack: this is Pointer that pointing to top node of stacks.
 *
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_err(8, line_number, "mul");
(*stack) = (*stack)->next;
sum = (*stack)->n * (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
