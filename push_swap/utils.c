#include "utils.h"

int ft_pow(int num, int level)
{
	int result;

	if (level == 0)
		return (1);
	result = 1;
	while (level > 0)
	{
		result *= num;
		--level;
	}
	return (result);
}