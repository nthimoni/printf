/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:03:31 by nthimoni          #+#    #+#             */
/*   Updated: 2021/12/07 19:23:31 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "buffer.h"
#include "parse_flags.h"
#include "bases.h"

void reg_dot(t_flags *flags, size_t len)
{
	if (flags->dot < (int)len)
		flags->dot = len;
}

void	print_di(int a, t_flags *flags)
{
	unsigned int	u;
	unsigned int	len;

	if (a < 0)
		u = -a;
	else
		u = a;
	len = ui_len(u, 10);
	if (a < 0 || flags->plus || flags->space)
		len++;
	reg_dot(flags, len);
	if (!flags->minus && !flags->zero)
		print_n_char(' ', flags->size - len, flags->dot - len);
	else if (!flags->minus && flags->zero)
		print_n_char('0', flags->size - len, 0);
	if (a < 0)
		write_buf("-", 1);
	else if (flags->plus)
		write_buf("+", 1);
	else if (flags->space)
		write_buf(" ", 1);
	print_ui_base(u, BASE_10);
	if (flags->minus)
		print_n_char(' ', flags->size - len, 0);
}
