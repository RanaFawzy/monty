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
