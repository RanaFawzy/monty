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




/**
 * err - function that Print the error messages with their error code
 * @error_code: error codes is integer type are the following:
 * (1) => first error is user does not give any file
 * or more than one file to the program
 * (2) => 2nd error the file provided is not a file can be opened or read
 * (3) => third error is the file provided contains an invalid instruction.
 * (4) => fourth error  when the program is unable to malloc more memory.
 * (5) => 5th error is when the parameter passed
 * to the instruction "push" is not an integer
 * (6) => sixth error when the stack it empty for pint
 * (7) => 7th error when the stack it empty for pop.
 * (8) => eighth error  when stack is too short to operate
 */


void err(int error_code, ...)
{
	va_list ag;
	char *opp;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			opp = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}


/**
 * string_err - a function  to deal with errors
 * @error_code: error codes are integer type and are as following:
 * (10) ~> case 10 is the number inside node is outside ASCII bounds
 * (11) ~> case 11 is  stack is empty
 */


void string_err(int error_code, ...)
{
va_list ag;
int l_num;

va_start(ag, error_code);
l_num = va_arg(ag, int);
switch (error_code)
{
	case 10:
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
		break;
	case 11:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
		break;
	default:
		break;
}
free_nodes();
exit(EXIT_FAILURE);
}
