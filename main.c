#include <stdlib.h>

#include <stdio.h>
int	ft_printf(const char *s, ...);
int	write_buf(char *str, size_t len);

#include <stdio.h>

int main()
{
	unsigned int a = 58455;
	int *u = &a;
	printf("%8x\n", a);
	ft_printf("%8x\n", a);
}
