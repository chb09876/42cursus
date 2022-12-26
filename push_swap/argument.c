#include "argument.h"

static void push(t_arg *arg, int elem);

t_arg parser(int argc, char *argv[])
{
	char **splited;
	t_arg arg;
	int *parsed;
	int i;
	int j;

	if (argc < 2)
		return (NULL);
	arg.arr = malloc(sizeof *arg.arr * (argc - 1));
	arg.size = 0;
	if (arg.arr == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		splited = ft_split(argv[i]);
		if (splited == NULL)
		{
			cleanup();
			return (NULL);
		}
		j = 0;
		while (splited[j])
		{
			arg.arr[arg.size++] = ft_atoi
		}
	}
}
