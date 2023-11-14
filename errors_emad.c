#include "monty.h"


/**
 * more_err - function used to deal with errors
 * @error_code: codes error are integer type and are  the following:
 * (6) => case 6  when the stack it empty for pint.
 * (7) => case 7  when the stack it empty for pop.
 * (8) => case 8  when stack is too short for operation.
 * (9) => case 9  division by zero.
 */

void more_err(int error_code, ...)
{
va_list ag;
char *op;
int l_num;

va_start(ag, error_code);
switch (error_code)
{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			va_arg(ag, int));
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			va_arg(ag, int));
		break;
	case 8:
		l_num = va_arg(ag, unsigned int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n",
			va_arg(ag, unsigned int));
		break;
	default:
		break;
}
free_nodes();
exit(EXIT_FAILURE);
}
