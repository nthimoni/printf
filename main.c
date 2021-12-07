#include <stdlib.h>

#include <stdio.h>
int	ft_printf(const char *s, ...);
int	write_buf(char *str, size_t len);

#include <stdio.h>

int main()
{
	unsigned int a = 5;
	int *u = &a;
	printf("%8.5s\n", "okokok");
	ft_printf("%8.5s\n", "okokok");
}
