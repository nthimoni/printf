#include "printers.h"
#include "parse_flags.h"
#include "buffer.h"

void	print_c(unsigned char c, t_flags *flags)
{
	int	i = 0;

	while (!flags->minus && i < flags->size - 1)
	{
		write_buf(" ", 1);
		i++;
	}
	write_buf((const char *)&c, 1);
	while (flags->minus && i < flags->size - 1)
	{
		write_buf(" ", 1);
		i++;
	}
}
