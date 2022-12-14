#include "stack.h"
#include <stdlib.h>

t_stack *make_stack(int reserved)
{
	t_stack *new;

	new = malloc(sizeof *new);
	if (new == NULL)
		return (NULL);
	new->arr = malloc(sizeof *new->arr *reserved);
	if (new->arr == NULL)
		return (NULL);
	new->reserved = reserved;
	new->size = 0;
	return (new);
}