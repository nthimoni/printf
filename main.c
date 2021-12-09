#include "include/ft_printf.h"
#include <stdio.h>
int main()
{
	printf("printf    : %8.4u\n", 9875);
	ft_printf("ft_printf : %8.4u\n", 9875);
	printf("printf    : %+8.4d\n", 9875);
	ft_printf("ft_printf : %+8.4d\n", 9875);
}
