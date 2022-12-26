#include "node.h"
#include <stdlib.h>

t_node *make_node(int data, t_node *next)
{
	t_node *new_node;

	new_node = malloc(sizeof *new_node);
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = next;
	return (new_node);
}