/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:06:34 by nthimoni          #+#    #+#             */
/*   Updated: 2021/12/07 19:01:49 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "parse_flags.h"
#include "printers.h"
#include "libft.h"
#include "bases.h"

size_t	ui_len(unsigned long int u, size_t base_len)
{
	int	i;

	if (!u)
		return (1);
	i = 0;
	while (u)
	{
		u /= base_len;
		i++;
	}
	return (i);
}

void	print_ui_base(unsigned long int val, const char *base)
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

void	print_n_char(char c, int n, int sup_zero)
{
	int	i;

	i = 0;
	while (i < n - sup_zero)
	{
		write_buf(&c, 1);
		i++;
	}
	i = 0;
	while (i < sup_zero)
	{
		write_buf("0", 1);
		i++;
	}
}

void	print_u(unsigned int u, t_flags *flags)
{
	int		i;
	size_t	len;

	len = ui_len(u, 10);
	if (flags->plus || flags->space)
		len++;
	reg_dot(flags, len);
	i = 0;
	if (!flags->minus && !flags->zero)
		print_n_char(' ', flags->size - len, flags->dot - len);
	if (!flags->minus && flags->zero)
		print_n_char('0', flags->size - len, 0);
	if (flags->plus)
		write_buf("+", 1);
	else if (flags->space)
		write_buf(" ", 1);
	print_ui_base(u, BASE_10);
	if (flags->minus)
		print_n_char(' ', flags->size - len, 0);
}
