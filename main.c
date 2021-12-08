#include <stdlib.h>

#include <stdio.h>
#include "include/ft_printf.h"

int main()
{
	int a = 5855;
	ft_printf("1qsdfqsdfqdsfqsd fqsdfqdsfsqdf qsdfqdsfqdsfds fqsdfqdsfqdsf  \n");
	ft_printf("2qsdfqsdfqd%%%%qsd fqsdfqdsfsqdf qsd%05dfqdsfqdsfds fqsdfqdsfqdsf  \n", 256);
	ft_printf("3%s%p%.9d\n","grosse canaille", NULL, 256);
	ft_printf("4%c%8c\n", '\0', 'c');
	ft_printf("5%s%p%p\n", NULL, NULL, NULL);
	ft_printf("%x%8.6x", 85, 1);
}
