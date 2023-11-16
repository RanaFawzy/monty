#include "monty.h"

/**
 * create_node - a func to create a node.
 * @n: an integer type and number to go inside the node.
 * Return: a pntr to the node
 *       or  NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - a func used to free nodes in the stack.
 */

void free_nodes(void)
{
stack_t *tmp;

if (head == NULL)
	return;

while (head != NULL)
{
	tmp = head;
	head = head->next;
	free(tmp);
}
}


/**
 * add_to_queue - a func is to add a node to the queue.
 * @new_node: pntr points to the new node.
 * @ln: an integer type and line number of the opcode.
 */

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
stack_t *head = NULL;

/**
 * main - a funct is an  entry point
 * @argc:  the arguments count
 * @argv: a list of arguments
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
if (argc != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
open_file(argv[1]);
free_nodes();
return (0);
}
