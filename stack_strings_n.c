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
