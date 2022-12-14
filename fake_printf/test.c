#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	// printf("%c", 'c');
	// char *s = "hello world!";
	int z = 10;
	int *p = &z;
	int a = ft_printf("%%%", 0);
	printf("\n-----------\n");
	// printf("real!\n");
	int b = printf("%%%", 0);
	printf("\n-----------\n");
	printf("a: %d b: %d", a, b);

	// printf("\n");

	// printf("%#5.3x\n", 10);
	// printf("% -20x\n", 10);
	// printf("% 020x\n", 10);
	// printf("% 0-20x\n", 10);
	// printf("% +20x\n", 10);
	// printf("% +-20x\n", 10);
	// printf("% +020x\n", 10);
	// printf("% +0-20x\n", 10);

	// printf("\n");

	// printf("%20d\n", -10);
	// printf("%-20d\n", -10);
	// printf("%020d\n", -10);
	// printf("%0-20d\n", -10);
	// printf("%+20d\n", -10);
	// printf("%+-20d\n", -10);
	// printf("%+020d\n", -10);
	// printf("%+0-20d\n", -10);

	// printf("\n");

	// printf("%1d\n", -10);
	// printf("%-1d\n", -10);
	// printf("%01d\n", -10);
	// printf("%0-1d\n", -10);
	// printf("%+1d\n", -10);
	// printf("%+-1d\n", -10);
	// printf("%+01d\n", -10);
	// printf("%+0-1d\n", -10);
}

// 패딩을 제외한 출력될 길이를 미리 구한다.
