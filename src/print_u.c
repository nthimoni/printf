

#include "buffer.h"
#include "parse_flags.h"
#include "printers.h"
#include "libft.h"
#include "bases.h"

size_t	ui_len(unsigned int u, size_t base_len)
{
	int	i;

	if (!u)
		return (1);
	i = 0;
	while (u)
	{
		u /= base_len - 1;
		i++;
	}
	return (i);
}

void	print_ui_base(unsigned int val, const char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (val > len - 1)
	{
		print_ui_base(val / len, base);
		write_buf(base + (val % len), 1);
	}
	else
		write_buf(base + val, 1);
}

void print_n_char(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write_buf(&c, 1);
		i++;
	}
}

void	print_u(unsigned int u, t_flags *flags)
{
	int		i;
	size_t	len;

	len = ui_len(u, 10);
	if (flags->plus)
		len++;
	i = 0;
	if (!flags->minus && !flags->zero)
		print_n_char(' ', flags->size - len);
	if (!flags->minus && flags->zero)
		print_n_char('0', flags->size - len);
	if (flags->plus)
		write_buf("+", 1);
	print_ui_base(u, BASE_10);
	if (flags->minus)
		print_n_char(' ', flags->size - len);
}
