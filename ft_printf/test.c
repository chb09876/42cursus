#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// printf("%c", 'c');
	ft_printf("%c", 'c');
	// printf("%+010.2d\n", 123);
	// printf("%+010d\n", 123);
	// printf("%+010d", 123);
	// printf("%20d\n", 10);
	// printf("%-20d\n", 10);
	// printf("%020.d\n", 10);
	// printf("%0-20d\n", 10);
	// printf("%+20d\n", 10);
	// printf("%+-20d\n", 10);
	// printf("%+020.5d\n", 10);
	// printf("%+0-20d\n", 10);

	// printf("\n");

	// printf("% 20d\n", 10);
	// printf("% -20d\n", 10);
	// printf("% 020d\n", 10);
	// printf("% 0-20d\n", 10);
	// printf("% +20d\n", 10);
	// printf("% +-20d\n", 10);
	// printf("% +020d\n", 10);
	// printf("% +0-20d\n", 10);

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
