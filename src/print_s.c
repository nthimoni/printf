
#include "parse_flags.h" 
#include "buffer.h"
#include "libft.h"

static int	bound_str_size(const char *str, int max)
{	
	int	len;

	len = ft_strlen(str);	
	if (len <= max || max == -1)
		return (len);
	return (max);
}

void	print_s(const char *s, t_flags *flags)
{
	int		i;
	int		len;

	len = bound_str_size(s, flags->dot);
	i = 0;
	while (!flags->minus && i < flags->size - len)
	{
		write_buf(" ", 1);
		i++;
	}
	write_buf(s, len);
	while (flags->minus && i < flags->size - len)
	{
		write_buf(" ", 1);
		i++;
	}
}
