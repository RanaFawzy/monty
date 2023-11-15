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



/**
 * swap_nodes - a funct use to swap the top 2 element of the stack
 * @stack: pntr points to top node of the stack
 * @line_number: an integer type and  represen a line number of opcode.
 */


void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}



/**
 * nop - a function used to Do nothing.
 * @stack: pntr points to top node of the stack.
 * @line_number: an integer type and  represent a line number of opcode.
 */

void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
