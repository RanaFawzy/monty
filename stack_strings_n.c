#include "monty.h"

/**
 * print_char - a func used to print the ASCII value
 * @stack: this pntr points to the top node of the stack.
 * @line_number: an integer type and  represet the line number of the opcode
 */


void print_char(stack_t **stack, unsigned int line_number)
{
int ascii;

if (stack == NULL || *stack == NULL)
	string_err(11, line_number);

ascii = (*stack)->n;
if (ascii < 0 || ascii > 127)
	string_err(10, line_number);
printf("%c\n", ascii);
}



/**
 * print_str - a function using to Print  string
 * @stack: pntr points to the  top node of the stack.
 * @ln: an integer type n represent the line number of the opcode
 */


void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}



/**
 * rotl - a funct using to Rotate the 1st node of the stack to the bottom
 * @stack: pntr points the  top node of the stack.
 * @ln: an integer type and represent line number of opcode.
 */


void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

tmp = *stack;
while (tmp->next != NULL)
	tmp = tmp->next;

tmp->next = *stack;
(*stack)->prev = tmp;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}


/**
 * rotr - a function using to Rotate last node of  stack to the top
 * @stack: pntr points  to the top node of the stack.
 * @ln: an integer type , represent the line number of of the opcode.
 */


void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
