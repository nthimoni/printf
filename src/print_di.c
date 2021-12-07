
#include "printers.h"
#include "buffer.h"
#include "parse_flags.h"
#include "bases.h"

void	print_di(int a, t_flags *flags)
{
	unsigned int	u;
	unsigned int	len;
	
	if (a < 0)
		u = -a;
	else
		u = a;
	len = ui_len(u, 10);
	if (a < 0 || flags->plus)
		len++;
	if (!flags->minus && !flags->zero)
	   print_n_char(' ', flags->size - len);
	else if (!flags->minus && flags->zero)
	   print_n_char('0', flags->size - len);
	if (a < 0)
		write_buf("-", 1);
	else if (flags->plus)
		write_buf("+", 1);
	print_ui_base(u, BASE_10);
	if (flags->minus)
	   print_n_char(' ', flags->size - len);
}
