#include "monty.h"


/**
 * read_file - a function used to read a file
 * @fd: a pntr to point to the file descriptor.
 * Return: nothing
 */

void read_file(FILE *fd)
{
int line_number, format = 0;
char *buffer = NULL;
size_t len = 0;

for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
{
	format = parse_line(buffer, line_number, format);
}
free(buffer);
}


/**
 * open_file - a function use to open a file
 * @file_name:  namepath file
 * Return: nothing
 */


void open_file(char *file_name)
{
FILE *fd = fopen(file_name, "r");

if (file_name == NULL || fd == NULL)
	err(2, file_name);

read_file(fd);
fclose(fd);
}

/**
 * parse_line - funct  to separate each line into tokens to determine
 * which function to call
 * @buffer: pntr that points to line from  file
 * @line_number: the line number
 * @format:  integer type storage format.
 * If (0) node will be entered as a stack.
 * if (1) node will be entered as a queue.
 * Return: 0 (success)
 *       if the opcode is stack. or 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}



/**
 * find_func - a func is to find the appropriate function for the opcode
 * @opcode:  a pntr opcode
 * @value: a pntr character type argument of opcode
 * @format:  an integer type storage format.
 * If (0) nodes will be entered as a stack
 * @ln: an integer type and line number
 * if (1) node will entered as a queue.
 * Return: nothing
 */


void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}
