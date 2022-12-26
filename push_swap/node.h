#ifndef NODE_H
#define NODE_H

typedef struct s_node
{
	int data;
	struct s_node *next;
} t_node;

t_node *make_node(int data, t_node *next);

#endif