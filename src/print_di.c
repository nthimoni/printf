/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:03:31 by nthimoni          #+#    #+#             */
/*   Updated: 2021/12/08 20:02:26 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "buffer.h"
#include "parse_flags.h"
#include "bases.h"

#include <stdio.h>

void reg_dot(t_flags *flags, size_t len)
{
	if (flags->dot == -1)
		flags->dot = len;
}

void	print_before(t_flags *flags, int a, unsigned int len)
{
	if (!flags->minus && !flags->zero)
		print_n_char(' ', flags->size - flags->dot - len, 0);
	if (a < 0)
		write_buf("-", 1);
	else if (flags->plus)
		write_buf("+", 1);
	else if (flags->space)
		write_buf(" ", 1);
	if (!flags->minus && flags->zero)
		print_n_char('0', flags->size - flags->dot, 0);
	if ((a < 0 || flags->space || flags->plus) 
		&& !flags->minus && !flags->zero && flags->dot != (int)len)
		print_n_char('0', flags->dot - len + 1, 0);
	if (!(a < 0) && !flags->space && !flags->plus && flags->dot != (int)len)
		print_n_char('0', flags->dot - len, 0);
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
	print_before(flags, a, len);
	print_ui_base(u, BASE_10);
	if (flags->minus)
		print_n_char(' ', flags->size - flags->dot, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void reg_dot(t_flags *flags, size_t len)
{
	if (flags->dot < (int)len)
		flags->dot = len;
}

void	print_before(t_flags *flags, int a, unsigned int len)
{
	if (!flags->minus && !flags->zero)
		print_n_char(' ', flags->size - flags->dot
		

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
	print_before(flags, a, len);
	len += flags->dot - len;
	print_ui_base(u, BASE_10);
	if (flags->minus)
		print_n_char(' ', flags->size - len, 0);
}*/
