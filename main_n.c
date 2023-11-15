#include "monty.h"

/**
 * create_node - function used to create a node
 * @n: an integer type and number go inside the node
 * Return: (pntr to the node)
 *          NULL.
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
