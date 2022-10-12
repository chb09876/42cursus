#include <stdio.h>
#include "ft_printf.h"


int main()
{
	// int a = ft_printf("[%s]\n[%s]\n", "", "world!");
	int b = ft_printf("%s\n", "NULL");
	printf("%d", b);
}

// 패딩을 제외한 출력될 길이를 미리 구한다.
