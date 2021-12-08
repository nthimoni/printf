#include <stdlib.h>

#include <stdio.h>
#include "include/ft_printf.h"

int main()
{
	ft_printf("%04d", -14);
}
/*
# include <limits.h>
#include "include/ft_printf.h"
int main()
{
    int ret = ft_printf(" % d ", LONG_MIN);
    int ret2 =   printf(" % ld ", LONG_MIN);
    printf("\n\nret val: %d vs %d", ret, ret2);
    return 0;
}
*/
