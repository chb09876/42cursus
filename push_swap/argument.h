#ifndef ARGUMENT_H
#define ARGUMENT_H

typedef struct s_arg
{
	int *arr;
	int size;
} t_arg;

t_arg parser(int argc, char *argv[]);

#endif