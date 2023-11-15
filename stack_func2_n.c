#include "monty.h"


/**
 * sub_nodes - a func using to add the top two elements of the stack
 * @stack: pntr points to top node of the stack
 * @line_number: an integer type and  represents the line number of opcode
 */


void sub_nodes(stack_t **stack, unsigned int line_number)
{
int sum;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

	more_err(8, line_number, "sub");


(*stack) = (*stack)->next;
sum = (*stack)->n - (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
